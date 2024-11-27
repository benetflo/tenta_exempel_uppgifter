// Fråga 2
// Skriv ett program som implementerar en enkel telefonbok:

// Använd en map för att lagra namn och telefonnummer
// Implementera funktioner för att:
// Lägga till nya kontakter
// Ta bort kontakter
// Söka efter en kontakt
// Visa alla kontakter i alfabetisk ordning
// Inkludera inmatningsvalidering och felhantering

#include <map>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cctype>




class Phonebook{

    private:
        std::map<std::string, std::string> user_phone_book;

    public:

        Phonebook() {}     // CONSTRUCTOR

        void addContact(std::string name, std::string number){ 

            if(!user_phone_book.insert(std::pair<std::string, std::string>(name, number)).second){     // IF NOT SUCCESFUL INSERT
                
                char answ;
                std::string num;
                std::cout << "User is already in phonebook!\n";
                std::cout << "Do you want to change " << name << "'s number? (y/n)"; std::cin >> answ;    // ASK IF USER WANT TO CHANGE NUMBER OF ALREADY EXISTING CONTACT

                switch (answ)
                {
                case 'y':
                    std::cout << "New number: "; std::cin >> num;    // INSERT NEW NUMBER
                    for(auto &p : user_phone_book){
                        if(p.first == name){
                            p.second = num;         // CHANGE NUMBER
                        }
                    }
                    break;
                case 'n':
                    break;
                default:
                    std::cout << "Invalid command!\n";
                    break;
                }
            }
            else // IF INSERT WAS SUCCESFUL
                std::cout << "Contact was added to your phonebook!\n";
            

        }

        void showContacts(){
            
            if(user_phone_book.empty()) // IF EMPTY
                std::cout << "Your phonebook is empty!\n";
            
            else{           // PRINT CONTACTS
                std::cout << "\n----My contacts----\n";
                for(auto &contact : user_phone_book){

                    std::cout << contact.first << " : " << contact.second << "\n";
                }
            }
        }

        void searchContact(std::string name){

            if(user_phone_book.empty()) // IF EMPTY
                std::cout << "Your phonebook is empty.\n";
            
            else{

                bool found = false; // found = true if name was found in phonebook

                for(auto &contact : user_phone_book){
                    
                    if(contact.first == name){

                        std::cout << name << "'s number: " << contact.second << "\n"; // print contact info
                        found = true;
                    }
                }
                if(!found) //if not found
                    std::cout << name << " is not in your contacts.\n";
                
            }

        }

        void removeContact(std::string name){

            if(user_phone_book.empty()) // if empty
                std::cout << "Your phonebook is empty.\n";
            
            else{

                auto it = user_phone_book.find(name); // LOOK FOR NAME

                if(it != user_phone_book.end()){ // IF FOUND

                    user_phone_book.erase(it);
                    std::cout << name << " was removed from your phonebook.\n";
                }
                else // IF NOT FOUND
                    std::cout << name << " is not in your phonebook.\n";
            }
            
        }


};


std::string name_input(){

    std::string name;
    
    while(1){

        std::cin.clear();
        std::cin.ignore();
        std::cout << "Enter name: "; std::getline(std::cin, name);
        
        if(name.empty())
            std::cout << "Name can't be empty.\n";
        else{
            name[0] = toupper(name[0]); // fix so that first char is always capital so the map can sort in alphabetical order.
            break;
        }
    }
    
    return name;
}

std::string number_input(){

    std::string number;

    while(1){
        
        bool is_valid = true;
        int plus_count = 0;
        int dash_count = 0;

        std::cout << "Enter number: "; std::cin >> number;
        
        for(size_t i = 0; i < number.length(); ++i){

            char c = number[i];

            if(std::isdigit(c))
                continue;
            else if(c == '-'){

                dash_count++;
                if(dash_count > 1){       // only one - is allowed
                    is_valid = false;
                    break;
                }
            }
            else if(c == '+'){
                if(i > 0){          // + can only be the first c
                    is_valid = false;
                    break;
                }
                plus_count++;
                if(plus_count > 1){        // only one + is allowed
                    is_valid = false;
                    break;
                }
            }
            else{
                is_valid = false;
                break;
            }     

        }
        if(is_valid)
            break;
        else
            std::cout << "Invalid number. Can only contain one ('-' and '+') and numbers 0-9\n";

    }
    
    return number;
}

int main(int argc, char const *argv[])
{
    Phonebook my_contacts; // new obj


    char menu_answ; // for menu choices
    std::string contact_number; // variable to store number inp in menu
    std::string contact_name; // variable to store name inp in menu
    
    
    std::cout << "-- PHONEBOOK PROGRAM  --\n";
    std::cout << "-- ADD CONTACT    (a) --\n";
    std::cout << "-- REMOVE CONTACT (r) --\n";
    std::cout << "-- SEARCH CONTACT (s) --\n";
    std::cout << "-- SHOW CONTACTS  (p) --\n";
    std::cout << "--      QUIT      (q) --\n";

    while(1)
    {
        std::cin >> menu_answ; 

        switch (menu_answ)
        {
        case 'a':
            contact_name = name_input(); //input name
            contact_number = number_input(); //input number
            my_contacts.addContact(contact_name, contact_number); 
            break;
        case 'r':
            contact_name = name_input(); // input name
            my_contacts.removeContact(contact_name);
            break;
        case 's':
            contact_name = name_input(); // input name
            my_contacts.searchContact(contact_name);
            break;
        case 'p':
            my_contacts.showContacts();
            break;
        case 'q':
            exit(0);
            break;
        default:
            std::cout << "Invalid command.\n";
            break;
        }
    }


    

    return 0;
}
