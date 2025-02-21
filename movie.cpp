#include "movie.h"    

using namespace std;
    
Movie::Movie(const std::string category, const std::string name, double price, 
int qty, std::string genre, std::string rating):
    Product(category, name, price, qty), genre_(genre), rating_(rating)
    {}


Movie::~Movie()
{}

// Finds keywords
std::set<std::string> Movie::keywords() const
{
    std::set<std::string> words = parseStringToWords(name_);
    words.insert(convToLower(this->genre_));
    return words;
}
// Displays information
std::string Movie::displayString() const
{
    return name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + priceToString(price_) + " " + std::to_string(qty_) + " left";
}
// Dumps
void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}