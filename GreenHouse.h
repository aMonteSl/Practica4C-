#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "AlarmSensors.h"
#include "MonitoringSystem.h"
#include "UsersServer.h"

class GreenHouse {
 public:
  GreenHouse();
  ~GreenHouse();

  void startSystem();
  void mainSystem();

 private:
  void sleep();
  void manageLogin();
  void manageAdmin();
  void manageEmployee();
  void manageGuest();
  void manageUpdateUser();
  void manageCreateUser();
  void manageDeleteUser();
  bool searchUser(std::string name, std::string password, std::string nif);
  AlarmSensors* alarm_;
  MonitoringSystem* ms_;
  UsersServer us_;
};

#endif  // GREENHOUSE_H
