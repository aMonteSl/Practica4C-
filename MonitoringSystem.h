#ifndef MONITORINGSYSTEM_H
#define MONITORINGSYSTEM_H
#include <iostream>
#include <string>

// Delcaracion anticipada de ScreenHardware, KeyboardHardware y SwitchHardware
class ScreenHardware;
class KeyboardHardware;
class SwitchHardware;

class MonitoringSystem {
 public:
  // Constructor con las declaraciones anticipadas
  explicit MonitoringSystem(ScreenHardware *screen, KeyboardHardware *keyboard,
                            SwitchHardware *sw);
  ~MonitoringSystem();

  int getSelection();
  std::string getName();
  std::string getNIF();
  std::string getPassword();

  std::string getNameSelectedUser();
  std::string getNIFSelectedUser();
  std::string getPasswordSelectedUser();
  std::string getPrivilegesSelectedUser();
  std::string getEmailSelectedUser();

  void
  initialScreen();  // Llama a initialWindow de Screen y askInput de Keyboard
  // ***********************
  void exitScreen();  // Llama a exitWindow de Screen
  void
  loginScreen();  // Llama a loginWindow de Screen y stringInput de Keyboard
  // ***********************
  void mainWindowAdmin();     // Llama a mainWindowAdmin de Screen
  void mainWindowEmployee();  // Llama a mainWindowEmployee de Screen
  void mainWindowGuest();     // Llama a mainWindowGuest de Screen
  // ***********************
  // Opciones menu
  void createUserScreen();  // Llama a createUserWindow de Screen y stringInput
                            // de Keyboard
  void deleteUserScreen();  // Llama a deleteUserWindow de Screen y stringInput
                            // de Keyboard
  void updateUserScreen();  // Llama a updateUserWindow de Screen y stringInput
                            // de Keyboard
  void displayUsersScreen();     // Llama a displayUsersWindow de Screen
  void displaySensorsScreen();   // Llama a displaySensorsWindow de Screen
  void displayAlarmsScreen();    // Llama a displayAlarmsWindow de Screen
  void turnOnOffSystemScreen();  // Llama a turnOnOffSystemWindow de Screen
  void displayErrorScreen();     // Llama a displayErrorWindow de Screen

 private:
  bool inputCorrect(int input, int max);
  int askInputInt(int max);
  std::string askName();
  std::string askNIF();
  std::string askPassword();
  std::string askPrivileges();
  std::string askEmail();
  ScreenHardware *screen;
  KeyboardHardware *keyboard;
  SwitchHardware *sw;
  int selection_;
  std::string name_;
  std::string nif_;
  std::string password_;
  // data new user
  void selectUser();
  std::string nameSelectedUser_;
  std::string nifSelectedUser_;
  std::string passwordSelectedUser_;
  std::string privilegesSelectedUser_;
  std::string emailSelectedUser_;
};

#endif  // MONITORINGSYSTEM_H
