#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <limits> // Add this line


int is_valid_number(std::string number)
{
	int i = 0;
	while (number[i]==' ')
			i++;
	if (!(number[i]))
		std::cout << "Empty input";
	while (number[i])
	{
		if (!(number[i] >='0' && number[i]<='9'))
			return(0);
		i++;
	}
	return (1);
}


void initialize_contacts(PhoneBook &phonebook) {
    std::string contactsData[8][5] = {
        {"John", "Doe", "Johnny", "1234567890", "Secret 1"},
        {"Jane", "Smith", "Janie", "2345678901", "Secret 2"},
        {"Alice", "Johnson", "Ali", "3456789012", "Secret 3"},
        {"Bob", "Brown", "Bobby", "4567890123", "Secret 4"},
        {"Charlie", "Davis", "CharlieBoy", "5678901234", "Secret 5"},
        {"Daisy", "Miller", "Dais", "6789012345", "Secret 6"},
        {"Eva", "Garcia", "Evie", "7890123456", "Secret 7"},
        {"Frank", "Wilson", "Frankie", "8901234567", "Secret 8"}
    };

    for (int i = 0; i < 8; i++) {
        phonebook.add_contact(contactsData[i]);
    }
}


int main()
{
	PhoneBook phonebook;
	std:: string data [5];
	std::string input;
	int index;
    initialize_contacts(phonebook);
    phonebook.display_phonebook(); 
	while (1)
	{
		std::cout << "                                 Welcome to Your PhoneBook 📇☎️" << std::endl;
		std::cout << "                          Please type one of the following commands:\n"
        << "                   \033[32mADD\033[0m(Add new contact), \033[32mSEARCH\033[0m (View contacts), \033[32mEXIT\033[0m (Quit application)." << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			std::cout << "First Name : ";
			std::getline(std::cin , data[0]);
			std::cout << "Last Name : ";
			std::getline(std::cin , data[1]);
			std::cout << "Nick Name : ";
			std::getline(std::cin , data[2]);
			std::cout << "Phone Number : ";
			std::getline(std::cin , data[3]);
			while (!(is_valid_number(data[3])))
			{
				std::cout<< "\033[31mPlease input a valid phone number!\033[0m\n" ;
				std::cout << "Phone Number : ";
				std::getline(std::cin , data[3]);

			}
			std::cout << "Darkest secret : ";
			std::getline(std::cin , data[4]);
			phonebook.add_contact(data);
			std::cout << "                                  \033[32mContact Added Successfully !" << std::endl;

		}
		else if (input == "SEARCH")
		{
			phonebook.display_phonebook();
			std::cout << "\033[32mInput index of contact for more info : " ;
			// std::cin >> index ;
			// while (std::cin.fail() || index < 1 || index > phonebook.get_size())
            // {
            //     std::cout << "Please input an index within the range : ";
            //     std::cin >> index ;
            //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // }
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             while (true) {
        std::cin >> index;

        // Check if the input is valid and within range
        if (!std::cin.fail() && index >= 1 && index <= phonebook.get_size()) {
            break; // Valid input; exit the loop
        }

        // If input is invalid, clear the fail state and ignore the bad input
        std::cin.clear(); // Clear the fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input

        std::cout << "Please input an index within the range: ";
    }

    // Clear the input buffer to prepare for the next input (if necessary)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			phonebook.display_contact(index);
		}
		else if (input == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else
		{
			std::cout << "COMMAND NOT FOUND !" << std :: endl;
		}
	}
	return (0);
}