#include <string>
#include <regex>
#include <iostream>
#include "utils.hpp"

void check_email(std::string email){
    std::regex pattern(R"(.+@.+..+)");
    
    if(std::regex_match(email, pattern))
        std::cout << "match\n";
    else
        throw std::invalid_argument ("email does not match pattern");
}