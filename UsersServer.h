#ifndef USERSSERVER_H
#define USERSSERVER_H
#include <string>

#include "UsersDatabase.h"

// UsersServer:es para controlar todos los usuarios
// Los usuarios estan almacenados en un objeto de la clase UsersDatabase

class UsersServer {
 public:
  // Constructor (necesario pasarle la base de datos)
  UsersServer();
  // Destructor
  ~UsersServer();

  void createUser(const std::string name, const std::string nif,
                  const std::string password, const std::string privileges,
                  const std::string email);
  void deleteUser(const std::string nif);
  void printUsersServer();
  void loadUsersFromFile();
  void saveUsersToFile();
  bool findUserLogin(std::string name, std::string password, std::string nif);
  std::string getPrivileges(std::string nif);
  void updateUser(const std::string name, const std::string nif,
                  const std::string password, const std::string privileges,
                  const std::string email);

 private:
  // Aqui se definen los atributos privados de la clase UsersServer
  UsersDatabase usersDatabase_;
  // File
  std::string fileName_ = "users.dat";
};

#endif  // USERSSERVER_H