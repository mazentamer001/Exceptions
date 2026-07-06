#include <iostream>
#include <string>
#include <map>
#include "utils.hpp"
#include "bcrypt/BCrypt.hpp"

int main(){

    std::map<std::string,std::string> database;
    int choice;
    
    bool x = true;
    bool isLogedin = false;

    while(true){
       
        if(!isLogedin){
            std::cout << "enter 1 to signUp and 2 to login\n";
            std::cin >> choice;
            if(choice == 1){
                while(x){
                    std::string email;
                    std::string password;
                    std::cout << "Enter valid email\n";
                    std::cin >> email;
                    std::cout << "Enter valid password\n";
                    std::cin >> password;
                    try{
                        check_email(email);
                        x = false;
                        database[email] = BCrypt::generateHash(password);
                        isLogedin = true;
                    } catch(const std::exception& e){
                        std::cout << "email is invalid format, enter another email\n";
                    }
                }
            }
            else if(choice == 2){
                std::string email;
                std::string password;
                std::cout << "Enter valid email\n";
                std::cin >> email;
                std::cout << "Enter valid password\n";
                std::cin >> password;
                for(std::pair p : database){
                    std::cout << p.second << std::endl;
                    std::cout << BCrypt::generateHash(password) << std::endl;
                    if(p.first == email && BCrypt::validatePassword(password,p.second)){
                        std::cout << "Log in successful \n";
                        isLogedin = true;
                    }
                }
                if(!isLogedin)
                    std::cout << "not found\n";
            }
        }
        else if(isLogedin){
            while(true){
                std::cout << "type q to logout\n";
                char x;
                std::cin >> x;
                if(x == 'q'){
                    isLogedin = false;
                    std::cout << "Log out successful\n";
                    break;
                }
            }
            
        }
    }
        
    
    return 0;
}