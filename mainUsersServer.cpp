#include <iostream>

#include "UsersDatabase.h"
#include "UsersServer.h"
using namespace std;

int main() {
  // creamos un server de usuarios
  UsersServer usersServer;
  // Imprimimos usuarios
  usersServer.createUser("Lena", "LJ809K5ES43", "Bagumm.87¡", "ADMIN",
                         "liselese.ratte@aol.com");
  usersServer.printUsersServer();
  usersServer.deleteUser("LJ809K5ES43");
  usersServer.printUsersServer();
  // usersServer.deleteUser("395530gggggg10A");
  //  usersServer.printUsersServer();
  usersServer.createUser("PEPE", "greghregh", "hhhhheh.rrrrr", "EMPLOYEE",
                         "hhhhrhr.rahrhrtte@aol.com");
  usersServer.printUsersServer();
  usersServer.saveUsersToFile();
  UsersServer usersServer2;
  usersServer2.loadUsersFromFile();
  std::cout << "*** Users loaded from file (SERVER 2) ***" << std::endl;
  usersServer2.printUsersServer();
}
