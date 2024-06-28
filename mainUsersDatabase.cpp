#include <iostream>

#include "User.h"
#include "UsersDatabase.h"

int main() {
  // Crear una instancia de UsersDatabase
  UsersDatabase usersDatabase;

  // Agregar algunos usuarios
  usersDatabase.addUser(User("Lena", "LJ809K5ES43", "Bagumm.87¡", User::ADMIN,
                             "liselese.ratte@aol.com"));
  usersDatabase.addUser(User("PEPE", "greghregh", "hhhhheh.rrrrr",
                             User::EMPLOYEE, "hhhhrhr.rahrhrtte@aol.com"));

  // Obtener los usuarios
  std::vector<User> usersCopy = usersDatabase.getUsers();

  // Modificar los usuarios en la copia
  for (User& user : usersCopy) {
    user.setEmail("newemail@example.com");  // Modificar el correo electrónico
  }

  // Establecer los usuarios modificados
  usersDatabase.setUsers(usersCopy);

  // Imprimir los usuarios actualizados
  usersDatabase.printUsers();

  // Encontrar un usuario
  if (usersDatabase.findUser(User("PEPE", "greghregh", "hhhhheh.rrrrr",
                                  User::EMPLOYEE,
                                  "hhhhrhr.rahrhrtte@aol.com"))) {
    std::cout << "PEPE found" << std::endl;
  } else {
    std::cout << "PEPE not found" << std::endl;
  }

  // encontrar un usuario por nombre
  if (usersDatabase.findUserByName("Lena")) {
    std::cout << "Lena found" << std::endl;
  } else {
    std::cout << "Lena not found" << std::endl;
  }

  // Encontrar un usuaario por NIF
  if (usersDatabase.findUserByNif("LJ809K5ES43")) {
    std::cout << "LJ809K5ES43 found" << std::endl;
  } else {
    std::cout << "LJ809K5ES43 not found" << std::endl;
  }

  // Encontrar un usuario por correo electrónico
  if (usersDatabase.findUserByEmail("liselese.ratte@aol.com")) {
    std::cout << "liselese.ratte@aol.com found" << std::endl;
  } else {
    std::cout << "liselese.ratte@aol.com not found" << std::endl;
  }

  // Borrar un usuario
  usersDatabase.deleteUser(User("Lena", "LJ809K5ES43", "Bagumm.87¡",
                                User::ADMIN, "newemail@example.com"));
  usersDatabase.printUsers();
  // Borrar un usuario por nombre
  usersDatabase.deleteUserByName("PEPE");
  usersDatabase.printUsers();
  // Borrar un usuario por NIF
  usersDatabase.addUser(User("PEPE", "greghregh", "hhhhheh.rrrrr",
                             User::EMPLOYEE, "hhhhrhr.rahrhrtte@aol.com"));
  usersDatabase.deleteUserByNif("greghregh");
  // Borrar un usuario por correo electrónico
  usersDatabase.deleteUserByEmail("hhhhrhr.rahrhrtte@aol.com");

  return 0;
}
