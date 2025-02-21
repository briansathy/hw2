#ifndef UTIL_H
#define UTIL_H

#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> intersection;
    // Iterates through set1, if it can find it in set 2, then add it
    for (typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it)
    {
        typename std::set<T>::iterator correspIt = s2.find(*it);
        if (correspIt != s2.end())
        {
            intersection.insert(*it);
        }
    } 
    return intersection;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    std::set<T> u;
    // Iterates over first set, adding it to the set to be returned
    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it )
    {
        u.insert(*it);
    }
    // Iterates over second set, checks if it hasn't already been added, if so then it adds each item
    for(typename std::set<T>::iterator it = s2.begin(); it != s2.end(); ++it)
    {
        if (s1.find(*it) != s1.end())
        {
            continue;
        }
        u.insert(*it);
    }
    return u;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string rawString);


std::set<std::string> parseStringToWords(std::string line);

std::string priceToString(double p);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s);

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
