#include "UsersServer.h"

#include <fstream>
#include <iostream>
#include <string>

#include "UsersDatabase.h"

// Constructor, el sevidor al construirse guardara en su base de datos tres
// usuarios de casa tipo
UsersServer::UsersServer() {
  // Creamos tres usuarios por defecto
  createUser("admin", "12345678X", "admin", "ADMIN", "admin@example.com");
  createUser("employee", "12345678Y", "employee", "EMPLOYEE",
             "employee@example.com");
  createUser("guest", "12345678Z", "guest", "GUEST", "guest@example.com");
}

UsersServer::~UsersServer() {}

void UsersServer::createUser(const std::string name, const std::string nif,
                             const std::string password,
                             const std::string privileges,
                             const std::string email) {
  User userToCreate(name, nif, password,
                    usersDatabase_.stringToPrivileges(privileges), email);
  usersDatabase_.addUser(userToCreate);
}

void UsersServer::deleteUser(const std::string nif) {
  User *userToDelete = usersDatabase_.findUserByNif(nif);
  if (userToDelete->getNif() == nif) {
    this->usersDatabase_.deleteUser(*userToDelete);
  }
}

std::string UsersServer::getPrivileges(std::string nif) {
  User *user = usersDatabase_.findUserByNif(nif);
  if (user != nullptr) {
    return user->getPrivileges();
  } else {
    return "GUEST";
  }
}

bool UsersServer::findUserLogin(std::string name, std::string password,
                                std::string nif) {
  // si encuentro por nombre, por password y por nif devuelvo true, ademas
  // debemos asegurarnos de los usuarios encontrados sean el mismo antes de
  // devolver true
  if (usersDatabase_.findUserByName(name) != nullptr &&
      usersDatabase_.findUserByPassword(password) != nullptr &&
      usersDatabase_.findUserByNif(nif) != nullptr) {
    if (usersDatabase_.findUserByName(name) ==
            usersDatabase_.findUserByPassword(password) &&
        usersDatabase_.findUserByName(name) ==
            usersDatabase_.findUserByNif(nif)) {
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

void UsersServer::updateUser(const std::string name, const std::string nif,
                             const std::string password,
                             const std::string privileges,
                             const std::string email) {
  User *userToUpdate = usersDatabase_.findUserByNif(nif);
  if (userToUpdate->getNif() == nif) {
    userToUpdate->setPrivileges(privileges);
    userToUpdate->setEmail(email);
  }
}

void UsersServer::printUsersServer() { this->usersDatabase_.printUsers(); }

void UsersServer::loadUsersFromFile() {
  // Cargamos los usuarios desde el archivo
  std::cout << "Loading users from file..." << std::endl;
  std::ifstream file(fileName_);
  if (file.is_open()) {
    std::string name;
    std::string nif;
    std::string password;
    std::string privileges;
    std::string email;
    while (file >> name >> nif >> password >> privileges >> email) {
      User user(name, nif, password,
                usersDatabase_.stringToPrivileges(privileges), email);
      // Si ya esta el usuario no le añadimos
      if (usersDatabase_.findUserByNif(nif) == nullptr) {
        usersDatabase_.addUser(user);
        std::cout << "User with NIF " << nif << " added." << std::endl;
      } else {
        std::cout << "Warning: User with NIF " << nif << " already exists."
                  << std::endl;
      }
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for reading." << std::endl;
  }
}

void UsersServer::saveUsersToFile() {
  std::ofstream file(fileName_, std::ios::trunc);
  if (file.is_open()) {
    const std::vector<User> &users = usersDatabase_.getUsers();
    for (const User &user : users) {
      file << user.getName() << " " << user.getNif() << " "
           << user.getPassword() << " " << user.getPrivileges() << " "
           << user.getEmail() << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Error: Unable to open file for writing." << std::endl;
  }
}
