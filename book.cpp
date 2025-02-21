#include "book.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, 
    const std::string author, const std::string ISBN)
    : Product(category, name, price, qty), author_(author), ISBN_(ISBN)
{}

Book::~Book()
{
}
// Function to find all keywords for a book 
std::set<std::string> Book::keywords() const
{
    std::set<std::string> words = parseStringToWords(name_ + " " + author_);
    words.insert(this->ISBN_);
    return words;
}
// Display relevant information
std::string Book::displayString() const
{
    return name_ + "\nAuthor: " + author_ + " ISBN: " + ISBN_ + "\n" + priceToString(price_) + " " + std::to_string(qty_) + " left";
}
// Dumps all information in appropriate format
void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_  << endl;
}