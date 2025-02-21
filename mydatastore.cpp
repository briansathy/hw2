#include "mydatastore.h"
#include <fstream>
#include <iostream>

using namespace std;

// Destructor, deallocates all the dynamically allocated users and products
MyDataStore::~MyDataStore()
{
    for (std::set<Product*>::iterator it = products.begin(); it != products.end(); ++it)
    {
        delete (*it);
    }
    for (std::map<std::string, User*>::iterator it = users.begin(); it != users.end(); ++it)
    {
        delete (*it).second;
    }

}
// void MyDataStore:: printstuff()
// {
//     for (std::map<std::string, std::set<Product*>>::iterator it = keywordsMap.begin(); it != keywordsMap.end(); ++it)
//     {
//       cout << (*it).first + " ";
//     }
// }


// adds the products to the set of products
void MyDataStore::addProduct(Product* p)
{
    //inserts to product set
    if (products.find(p) == products.end()) // this condition may be pointless
    {
        products.insert(p);
    }
    std::set<std::string> keys = p -> keywords();
    // Loops thrugh each keyword associated with each product, then adds product to appropriate queue
    // if necessary
    for (std::set<std::string>::iterator it = keys.begin(); it != keys.end(); ++it)
    {
            keywordsMap[*it].insert(p);
    }
}
void MyDataStore::addUser(User* u)
{
    // Adds user to map of usernames to users
    users[u->getName()] = u;
}

void MyDataStore::dump(std::ostream& os)
{

        os << "<products>\n";
        // iterates through the set of products, calling their dump function
        for (std::set<Product*>::iterator it = products.begin(); it != products.end(); ++it)
        {
            (*it) -> dump(os);
        }
        os << "</products>\n";

        os << "<users>\n";
        // iterates through users calling dump
        for (std::map<std::string, User*>::iterator it = users.begin(); it != users.end(); ++it)
        {
            (*it).second -> dump(os);
        }
        os << "</users>";
// }
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    if (terms.size() == 0)
    {
        throw std::runtime_error("No keywords were entered");
    }
    if (type == 0)
    {
        std::vector<Product*> intersection;
        // Gets the set of products corresponding to the first keyword
        std::set<Product*> returnList = keywordsMap[terms[0]];
        // Iterates through the rest of the terms, updating intersections appropriately
        for (size_t i = 1; i < terms.size(); ++i)
        {
            returnList = setIntersection(keywordsMap[terms[i]], returnList);
        }
        // Converts the set of products into a vector
        for (std::set<Product*>::iterator it = returnList.begin(); it != returnList.end(); ++it)
        {
            intersection.push_back(*it);
        }  
        return intersection;
    }
    else if (type == 1)
    {
        std::vector<Product*> un;
        std::set<Product*> setUn = keywordsMap[terms[0]];
        // Iterates through each adjacent term, adding their unions to the return set
        for (size_t i = 1; i < terms.size(); ++i)
        {
            setUn = setUnion(keywordsMap[terms[i]], setUn);
        }
        // Adds the data from the set to a vector
        for (std::set<Product*>::iterator it = setUn.begin(); it != setUn.end(); ++it)
        {
            un.push_back(*it);
        }
        return un;
    }
    else
    {
        throw std::runtime_error("Invalid type");
    }
}
void MyDataStore::viewCart(std::string username)
{
// {    std::map<std::string, std::deque<Product*>> cart;
    if (cart.find(username) == cart.end())
    {
        cout << "Invalid username" << endl;
    }
    // Iterates through appropriate cart, displaying information
    for (size_t i = 0; i < cart[username].size(); ++i)
    {
        cout << "Item " << to_string(i+1) + "\n" << cart[username][i]->displayString() << endl;
    }
    cout << endl;
}
// function to support the Add command
void MyDataStore::addToCart(std::string username, int hitIndex, std::vector<Product*>& hits)
    {
        if (users.find(username) == users.end()) 
        {
            cout << "Invalid Request" << endl;
            return;
        }
        (cart[username]).push_back(hits[hitIndex-1]);
    }
void MyDataStore::buyCart(std::string username)
{
    if (cart.find(username) == cart.end())
    {
        cout << "Invalid username" << endl;
    }
    std::deque<Product*>::iterator it = cart[username].begin();
    while (it != cart[username].end())
    {
        // Checks if item is in stock, and if user has enough money
        if ((*it) -> getQty() > 0 && (*it) -> getPrice() <= users[username] -> getBalance())
        {
            // Debits user
            users[username] -> deductAmount((*it) -> getPrice());
            // Updates stock
            (*it) -> subtractQty(1);
            // Updates cart
            it = cart[username].erase(it);
        }
        else
        {
            ++it;
        }
    }
}
