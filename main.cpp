#include <iostream>
#include <string>
#include "utils.hpp"

int main(){

    std::cout << "Enter an email\n";
    bool x = true;

    while(x){
        std::string email;
        std::cin >> email;
        try{
            check_email(email);
            x = false; 
        } catch(const std::exception& e){
            std::cout << "email is invalid format, enter another email\n";
        }
    }
    
    return 0;
}