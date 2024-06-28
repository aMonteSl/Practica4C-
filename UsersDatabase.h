#ifndef USERSDATABASE_H
#define USERSDATABASE_H

#include <vector>

#include "User.h"

// UserDatabase:es para controlar todos los usuarios
class UsersDatabase {
 public:
  // Constructor por defecto
  UsersDatabase();

  // Funciones getters y setters
  // Esta funcion std::set<User> getUsers() const; devuelve los usuarios
  std::vector<User> getUsers() const;
  void setUsers(const std::vector<User>& users);
  void addUser(const User& user);
  // Ahora se implementan funciones para buscar un usuario por usuario, por
  // nombre, por NIF, por correo electrónico
  User* findUser(const User& user) const;
  User* findUserByName(const std::string name) const;
  User* findUserByNif(const std::string nif) const;
  User* findUserByPassword(const std::string password) const;
  User* findUserByEmail(const std::string email) const;
  // Ahora se implementa la funcion para eliminar un usuario por usuario, por
  // nombre, por NIF, por correo electrónico
  void deleteUser(const User& user);
  void deleteUserByName(const std::string name);
  void deleteUserByNif(const std::string nif);
  void deleteUserByEmail(const std::string email);
  // Ahora imprimimos todos los usuarios
  void printUsers() const;

  User::Privileges stringToPrivileges(std::string privilegesStr);

  // Destructor
  ~UsersDatabase();

 private:
  // Aqui se definen los atributos privados de la clase UsersDatabase
  std::vector<User> users_;
  void printDeletedUser(const User user) const;
};

#endif  // UsersDatabase