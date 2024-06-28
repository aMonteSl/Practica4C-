#ifndef SCREENHARDWARE_H
#define SCREENHARDWARE_H
#include "Hardware.h"

class ScreenHardware : public Hardware {
 public:
  explicit ScreenHardware(bool active);
  ~ScreenHardware() override;
  void displayOutput() const override;
  int askInput() override;

  // All the windows of the system
  void
  initialWindow();  // Funcion que muestra la ventana principal (espera que se
                    // le de a intro para continuar, cuando se le de a intro
                    // muestra la ventana de login y arranca todos los sensores)
  void loginWindow();  // Funcion que muestra la ventana de login (admin genera
                       // los guess y employee y puede generar otros admins)
  void mainWindowAdmin();  // Funcion que muestra la ventana principal (muestra
                           // todas las opciones) Admin
  void mainWindowEmployee();  // Funcion que muestra la ventana principal
                              // (muestra todas las opciones) Employee
  void mainWindowGuest();  // Funcion que muestra la ventana principal (muestra
                           // todas las opciones) Guest
  void
  createUserWindow();  // Funcion que muestra la ventana para crear un usuario
  void
  deleteUserWindow();  // Funcion que muestra la ventana para borrar un usuario
  void updateUserWindow();  // Funcion que muestra la ventana para actualizar un
                            // usuario
  void displayUsersWindow();    // Funcion que muestra la ventana para ver todos
                                // los usuarios
  void displaySensorsWindow();  // Funcion que muestra la ventana para ver todos
                                // los sensores
  void displayAlarmsWindow();   // Funcion que muestra la ventana para ver todas
                                // las alarmas
  void turnOnOffSystemWindow();  // Funcion que muestra la ventana para encender
                                 // y apagar el sistema
  void displayErrorWindow();     // Funcion que muestra la ventana de error
  void exitWindow();
};

#endif  // SCREENHARDWARE_H