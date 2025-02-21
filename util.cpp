#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> keyWords;
    std::string buffer;
    // Loops through word char by char
    for (char c : rawWords)
    {
        // If it is a "good" character, add to buffer
        if (std::isalnum(c))
        {
            buffer += c;
        }
        // If not add buffer to set, if it is long enough, and clear buffer
        else
        {
            if (buffer.length() > 1)
            {
                keyWords.insert(convToLower(buffer));
                buffer.clear();
            }
            else 
            {
              buffer.clear();
            }
        }
    }
    // For the last word (it will not hit a trigger char)
    if (buffer.length() > 1)
        {
            keyWords.insert(convToLower(buffer));
        }
    return keyWords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}


// Helper function, to convert a double (price) to 2 digit decimal number
std::string priceToString(double p)
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(2) << p;
  return ss.str();
}

