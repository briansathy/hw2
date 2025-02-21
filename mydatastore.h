#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "user.h"
#include "util.h"
#include "map"
#include <deque>

class MyDataStore:public DataStore
{
    public:

    ~MyDataStore();
    // overriding virtual functions inherited from DataStore
    void addProduct(Product* p) override;
    void addUser(User* u) override;
    void dump(std::ostream& ofile) override;

    // function prototypes for interacting with the database
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void viewCart(std::string username);
    // adds selected product to cart
    void addToCart(std::string username, int hitIndex, std::vector<Product*>& hits);
    // Supports the BUYCART username command
    void buyCart(std::string username);
    void quit(std::string filename);
    void printstuff();

    private:
    // Index mapping key words, to their corresponding set of products
    std::map<std::string, std::set<Product*>> keywordsMap;
    // Maps usernames to user objects
    std::map<std::string, User*> users;
    // set of product objects
    std::set<Product*> products;
    // map that represents each users cart
    std::map<std::string, std::deque<Product*>> cart;
};

#endif