#include "UsersDatabase.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "User.h"

UsersDatabase::UsersDatabase() {}

UsersDatabase::~UsersDatabase() {
  // std::cout << "Destructor called" << std::endl;
  // Ahora tengo que liberar la memoria de los atributos de la clase
  // UserDatabase
  users_.clear();
  // std::cout << "Destructor finished" << std::endl;
}

User::Privileges UsersDatabase::stringToPrivileges(std::string privilegesStr) {
  if (privilegesStr == "ADMIN") {
    return User::ADMIN;
  } else if (privilegesStr == "EMPLOYEE") {
    return User::EMPLOYEE;
  } else {
    return User::GUEST;
  }
}

std::vector<User> UsersDatabase::getUsers() const { return users_; }

void UsersDatabase::setUsers(const std::vector<User> &users) { users_ = users; }

void UsersDatabase::addUser(const User &user) {
  users_.push_back(user);
  // std::cout << "Size of users after adding user: " << users_.size() <<
  // std::endl;
}

User *UsersDatabase::findUser(const User &user) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::vector<User>::const_iterator it = users_.begin();
       it != users_.end(); it++) {
    if (*it == user) {
      return const_cast<User *>(&(*it));
    }
  }
  return nullptr;
}

User *UsersDatabase::findUserByName(const std::string name) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::vector<User>::const_iterator it = users_.begin();
       it != users_.end(); it++) {
    if (it->getName() == name) {
      return const_cast<User *>(&(*it));
    }
  }
  return nullptr;
}

User *UsersDatabase::findUserByNif(const std::string nif) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::vector<User>::const_iterator it = users_.begin();
       it != users_.end(); it++) {
    if (it->getNif() == nif) {
      return const_cast<User *>(&(*it));
    }
  }

  return nullptr;
}

User *UsersDatabase::findUserByPassword(const std::string password) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::vector<User>::const_iterator it = users_.begin();
       it != users_.end(); it++) {
    if (it->getPassword() == password) {
      return const_cast<User *>(&(*it));
    }
  }

  return nullptr;
}

User *UsersDatabase::findUserByEmail(const std::string email) const {
  // Si el usuario existe devuelvo el usuario, si no existe devuelvo un usuario
  // con todos los atributos vacios
  for (std::vector<User>::const_iterator it = users_.begin();
       it != users_.end(); it++) {
    if (it->getEmail() == email) {
      return const_cast<User *>(&(*it));
    }
  }
  return nullptr;
}

void UsersDatabase::deleteUser(const User &user) {
  for (std::vector<User>::iterator it = users_.begin(); it != users_.end();
       it++) {
    if (*it == user) {
      printDeletedUser(*it);
      users_.erase(it);
      return;
    }
  }
}

void UsersDatabase::deleteUserByName(const std::string name) {
  for (std::vector<User>::iterator it = users_.begin(); it != users_.end();
       it++) {
    if (it->getName() == name) {
      printDeletedUser(*it);
      users_.erase(it);
      return;
    }
  }
}

void UsersDatabase::deleteUserByNif(const std::string nif) {
  for (std::vector<User>::iterator it = users_.begin(); it != users_.end();
       it++) {
    if (it->getNif() == nif) {
      printDeletedUser(*it);
      users_.erase(it);
      return;
    }
  }
}

void UsersDatabase::deleteUserByEmail(const std::string email) {
  for (std::vector<User>::iterator it = users_.begin(); it != users_.end();
       it++) {
    if (it->getEmail() == email) {
      printDeletedUser(*it);
      users_.erase(it);
      return;
    }
  }
}

void UsersDatabase::printUsers() const {
  std::cout << "*** LIST OF USERS ***" << std::endl;
  for (const auto &user : users_) {
    user.printUser();
    std::cout << std::endl;
  }
  std::cout << "*** END OF LIST ***" << std::endl;
}

void UsersDatabase::printDeletedUser(const User user) const {
  std::cout << "User deleted: " << user.getName() << " " << user.getNif()
            << std::endl;
}