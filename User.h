#ifndef USER_H
#define USER_H

#include <string>

class User {
 public:
  enum Privileges { ADMIN, EMPLOYEE, GUEST };
  // Constructor por defecto
  User();
  // Constructor pasando los valores de los atributos .Cada usuario se puede
  // construir con un nombre, NIF, password, privilegios y correo electrónico
  explicit User(const std::string name, const std::string nif,
                std::string password, Privileges privileges, std::string email);

  std::string getName() const;
  std::string getNif() const;
  std::string getPassword() const;
  std::string getPrivileges() const;
  std::string getEmail() const;

  void setName(const std::string name);
  void setNif(const std::string nif);
  void setPassword(std::string password);
  void setPrivileges(std::string privileges);
  void setEmail(std::string email);

  // Aqui se podrian poner mas funciones, de momento solo se implementa el
  // constructor por defecto y los getters y setters además de una funcion para
  // imprimir los datos de un usuario bool operator<(const User& user) const es
  // para poder ordenar los usuarios por nombre y NIF
  bool operator<(const User& user) const;
  bool operator>(const User& user) const;
  bool operator==(const User& user) const;
  friend std::ostream& operator<<(std::ostream& os, const User& user);
  friend std::istream& operator>>(std::istream& is, User& user);
  void printUser() const;

  // Destructor
  ~User();

 private:
  // Aqui se definen los atributos privados de la clase User
  // name y nig deberian de ser constante, const std::string name;.... pero esto
  // colisona con el constructor por defecto de User.cpp posible solucion: hacer
  // que el constructor por defecto sea ADMIN ADMIN
  std::string name;
  std::string nif;
  std::string password;
  Privileges privileges;
  std::string email;
};

#endif