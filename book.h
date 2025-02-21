#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include "util.h"

class Book:public Product{
public: 
    // Book constructor
    Book(const std::string category, const std::string name, double price, int qty, 
    const std::string author, const std::string ISBN);

    virtual ~Book();

    // Member functions supporting keywords, display, and dump
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

private:
    std::string author_;
    std::string ISBN_;

};

#endif