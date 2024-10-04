#include <iostream>
#include "Contact.hpp"

Contact::Contact() {
};

Contact::~Contact() {
};

void Contact::set_firstname(std::string firstName){
    this->firstname = firstName;
}

void Contact::set_lastname(std::string lastName){
    this->lastname = lastName;
}

void Contact::set_nickname(std::string nickName){
    this->nickname = nickName ;
}
 
void Contact::set_number(std::string phoneNumber){
    this->number = phoneNumber;
}

void Contact::set_secret(std::string d_secret){
    this->secret = d_secret;
}

const std::string& Contact::get_firstname() const{
    return this->firstname;
}

const std::string& Contact::get_lastname() const {
    return this->lastname;
}

const std::string& Contact::get_nickname() const{
    return this->nickname;
}
 
const std::string& Contact::get_number() const{
    return this->number;
}

const std::string& Contact::get_secret() const{
    return this->secret;
}