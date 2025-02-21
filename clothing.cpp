#include "clothing.h"

using namespace std;

// Constructor
Clothing::Clothing(const std::string category, const std::string name, double price, int qty, 
    const std::string size, const std::string brand)
    : Product(category, name, price, qty), size_(size), brand_(brand)
    {}
Clothing::~Clothing()
{}
// Finds keywords
std::set<std::string> Clothing::keywords() const
{
    return parseStringToWords(name_ + " " + brand_);
}
// Displays information
std::string Clothing::displayString() const
{
    return name_ + "\nSize: " + size_ + " Brand: " + brand_ + "\n" + priceToString(price_) + " " + std::to_string(qty_) + " left";
}
// Dumps
void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}