#include "PhoneBook.hpp"
#include "Contact.hpp"


#include "PhoneBook.hpp"

void print_word(std::string word)
{
    int i =0;
    if (word.length()>9)
    {
        std::cout << word.substr(0,9);
        std::cout << ".";
    }
    else
    {
        i = word.length(); // Get the length of the word
        while (i < 10) 
        {
            std::cout << " "; // Print spaces to pad the word
            i++;
        }
        std::cout << word;
    }
}

int 	PhoneBook::get_size() const
{
	return (this->size);
}

void PhoneBook::add_contact(std::string *data)
{
    int i = this->index;
    i = i % 8 ;
    this->contacts[i].set_firstname(data[0]);
    this->contacts[i].set_lastname(data[1]);
    this->contacts[i].set_nickname(data[2]);
    this->contacts[i].set_secret(data[3]);
    this->contacts[i].set_number(data[4]);
    this->index++;
    if (this->size < 8)
        this->size++;
}

void PhoneBook::display_contact(int i) const
{
    std::cout  << "               ════════════════════════════════════════════        " <<  std::endl;
    std::cout  << "                  Contact Information for the specified user!" <<  std::endl;
    std::cout  << "               ════════════════════════════════════════════" <<  std::endl;
    std::cout << "First name: " << this->contacts[i-1].get_firstname() << std::endl;
    std::cout << "Last name: " << this->contacts[i-1].get_lastname() << std::endl;
    std::cout << "Nick name: " << this->contacts[i-1].get_nickname() << std::endl;
    std::cout << "Phone number: " << this->contacts[i-1].get_number() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[i-1].get_secret() << std::endl;
}

void PhoneBook::display_phonebook() const
{
    int i = 0;
    std::cout  << "╔══════════╦══════════╦══════════╦══════════╗" <<  std::endl;
    std::cout  << "║     index║first name║ last name║  nickname║" <<  std::endl;
    std::cout  << "╠══════════╬══════════╬══════════╬══════════╣" <<  std::endl;

    while (i < this->size)
    {
        std::cout << "║";
        std::cout << "         " << i+1;
        std::cout << "║";
        print_word(this->contacts[i].get_firstname());
        std::cout << "║";
        print_word(this->contacts[i].get_lastname());
        std::cout << "║";
        print_word(this->contacts[i].get_nickname());
        std::cout << "║" << std::endl;
        i++;
    }
    std::cout << std::endl;

}


