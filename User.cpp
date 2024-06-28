#include "User.h"

#include <iostream>

User::User() {
  name = "";
  nif = "";
  password = "";
  privileges = GUEST;
  email = "";
}

User::User(const std::string name, const std::string nif, std::string password,
           Privileges privileges, std::string email) {
  this->name = name;
  this->nif = nif;
  this->password = password;
  this->privileges = privileges;
  this->email = email;
}

// Destructor
User::~User() {
  // std::cout << "Destructor called" << std::endl;
  // Ahora tengo que liberar la memoria de los atributos de la clase User
  name.clear();
  nif.clear();
  password.clear();
  email.clear();
  privileges = GUEST;
  // std::cout << "Destructor finished" << std::endl;
}

std::string User::getName() const { return name; }

std::string User::getNif() const { return nif; }

std::string User::getPassword() const { return password; }

std::string User::getPrivileges() const {
  switch (privileges) {
    case ADMIN:
      return "ADMIN";
    case EMPLOYEE:
      return "EMPLOYEE";
    case GUEST:
      return "GUEST";
  }
  return "";  // Devolución predeterminada para evitar advertencias del
              // compilador
}

std::string User::getEmail() const { return email; }

void User::setName(std::string name) { this->name = name; }

void User::setNif(std::string nif) { this->nif = nif; }

void User::setPassword(std::string password) { this->password = password; }

void User::setPrivileges(std::string privileges) {
  if (privileges == "ADMIN") {
    this->privileges = ADMIN;
  } else if (privileges == "EMPLOYEE") {
    this->privileges = EMPLOYEE;
  } else if (privileges == "GUEST") {
    this->privileges = GUEST;
  }
}

void User::setEmail(std::string email) { this->email = email; }

void User::printUser() const {
  std::cout << "\n"
            << "USER DATA" << std::endl;
  std::cout << "Name: " << name << "\nNIF: " << nif
            << "\nPassword: " << password << "\nPrivileges: " << getPrivileges()
            << "\nEmail: " << email << std::endl;
}

bool User::operator<(const User& other) const {
  return privileges > other.privileges;
}

// Devuelve true si el usuario a comparar es menor que el usuario actual para
// ello compara los privilegios
bool User::operator>(const User& other) const {
  return privileges < other.privileges;
};

// Devuelve true si el usuario a comparar es igual al usuario actual
bool User::operator==(const User& other) const {
  return name == other.name && nif == other.nif;
}

// Devuelve un string con los datos del usuario
std::ostream& operator<<(std::ostream& os, const User& user) {
  os << user.getName() << " " << user.getNif() << " " << user.getPassword()
     << " " << user.getPrivileges() << " " << user.getEmail() << std::endl;
  return os;
}

// Devuelve los datos del usuario en un string
std::istream& operator>>(std::istream& is, User& user) {
  std::string privilege;
  // std::cout << "Enter data for user(NAME, NIF, PASSWORD,
  // (ADMIN/EMPLOYEE/GUEST), EMAIL): ";
  is >> user.name >> user.nif >> user.password >> privilege >> user.email;
  if (privilege == "ADMIN")
    user.privileges = User::ADMIN;
  else if (privilege == "EMPLOYEE")
    user.privileges = User::EMPLOYEE;
  else if (privilege == "GUEST")
    user.privileges = User::GUEST;
  return is;
}
