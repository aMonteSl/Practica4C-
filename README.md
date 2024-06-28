# P4-ImplClases-AST_23-24
## Autor Adrián Montes Linares

## Introducción

El programa principal se encuentra en main.cpp donde podremos lanzar el sistema del invernadero y realizar todas las operaciones posibles. Como compilar el main.cpp y ejecutar el programa se enseñara más adelante.
De momento muestro todas las clases, una explicación breve de ellas y que SOURCES tiene que tener el MakeFile para probar cada clase

1. User.cpp = Define los métodos y atributos básicos de un usuario.
```make
SOURCES = User.cpp mainUser.cpp
```
2. UserDatabase.cpp = Define los métodos y atributos básicos de una base de datos que almacena usuarios. (Maneja a cada usuario de manera individual de una base de datos)
```make
SOURCES = User.cpp UsersDatabase.cpp mainUsersDatabase.cpp
```
3. UsersServer.cpp = Define los métodos y atributos básicos de un servidor que maneja una base de datos. (Maneja al conjunto de usuarios de una base de datos)
```make
SOURCES = User.cpp UsersDatabase.cpp mainUsersServer.cpp UsersServer.cpp
```
4. Sensor.cpp = Define los métodos y atributos básicos de un sensor
```make
SOURCES = Sensor.cpp mainSensor.cpp
```
5. TemperatureSensor.cpp = Define los métodos y atributos de un sensor de temperatura
```make
SOURCES = Sensor.cpp TemperatureSensor.cpp mainTemperatureSensor.cpp
```
6. AirQualitySensor.cpp = Define los métodos y atributos de un sensor de aire
```make
SOURCES = Sensor.cpp AirQualitySensor.cpp mainAirQualitySensor.cpp
```
7. HydrometerSensor.cpp = Define los métodos y atributos de un hydrometro
```make
SOURCES = Sensor.cpp HydrometerSensor.cpp mainHydrometerSensor.cpp
```
8. PressureSensor.cpp = Define los métodos y atributos de un sensor de presión
```make
SOURCES = Sensor.cpp PressureSensor.cpp mainPressureSensor.cpp
```
9. LightSensor.cpp = Define los métodos y atributos de un sensor de luz
```make
SOURCES = Sensor.cpp LightSensor.cpp mainLightSensor.cpp
```
10. PhSensor.cpp = Define los métodos y atributos de un sensor de pH
```make
SOURCES = Sensor.cpp PhSensor.cpp mainPhSensor.cpp
```
11. Hardware.cpp = Define los métodos y atributos de un hardware generico (pantalla/teclado/interruptor)
```make
SOURCES = Hardware.cpp mainHardware.cpp 
```
12. ScreenHardware.cpp = Define los métodos y atributos necesarios de una pantalla
```make
SOURCES = Hardware.cpp mainScreenHardware.cpp ScreenHardware.cpp
```
13. KeyboardHardware.cpp = Define los métodos y atributos necesarios de un teclado
```make
SOURCES = Hardware.cpp mainKeyboardHardware.cpp KeyboardHardware.cpp
```
14. SwitchHardware.cpp = Define los métodos y atributos necesarios de un interruptor
```make
SOURCES = Hardware.cpp mainSwitchHardware.cpp SwitchHardware.cpp
```
15. AlarmSensors.cpp = Define los métodos y atributos necesarios para manejar todos los sensores y sus alarmas
```make
SOURCES = Sensor.cpp TemperatureSensor.cpp AirQualitySensor.cpp HydrometerSensor.cpp PressureSensor.cpp LightSensor.cpp PhSensor.cpp mainAlarmSensor.cpp AlarmSensor.cpp
```
16. MonitoringSystem.cpp = Define los métodos y atributos necesarios para manejar el sistema implementando un hardware de cada tipo
```make
SOURCES = Hardware.cpp MonitoringSystem.cpp mainMonitoringSystem.cpp KeyboardHardware.cpp ScreenHardware.cpp SwitchHardware.cpp
```
17. GreenHouse.cpp = Define los métodos y atributos necesarios para lanzar el sistema del invernadero, controlarlo, ver los sensores, usuarios y el resto de funciones según el rol que tengamos. Por defecto siempre hay tres usuarios, uno de cada tipo
* Nombre NIF Contraseña Privilegios Correo:
- admin 12345678X admin ADMIN admin@example.com
- employee 12345678Y employee EMPLOYEE employee@example.com
- guest 12345678Z guest GUEST guest@example.com

```make
SOURCES =  GreenHouse.cpp AlarmSensors.cpp UsersServer.cpp MonitoringSystem.cpp AirQualitySensor.cpp Hardware.cpp HydrometerSensor.cpp KeyboardHardware.cpp LightSensor.cpp TemperatureSensor.cpp User.cpp mainGreenHouse.cpp PhSensor.cpp PressureSensor.cpp ScreenHardware.cpp Sensor.cpp SwitchHardware.cpp UsersDatabase.cpp
```
                                                                   


## Objetivos de la práctica

### Creacion del encabezado (*.h)
Aprender a definir correctamente las clases en el archivo de encabezado (*.h) correspondiente a cada clase. Para ello es necesario usar las siguientes directivas del prepocesador

1. `#ifndef`: Esta directiva de preprocesador se utiliza para prevenir la doble inclusión de un archivo de encabezado. Cuando se incluye un archivo de encabezado, el preprocesador copia todo su contenido al archivo de origen. Si el mismo archivo de encabezado se incluye más de una vez, puede causar problemas como la redefinición de clases, funciones o variables. `#ifndef` ayuda a evitar esto al permitir que el contenido del archivo de encabezado se incluya solo si un identificador específico no ha sido definido anteriormente.

2. `#define`: Esta directiva de preprocesador se utiliza para definir un identificador que puede representar un valor o una pieza de código. Esto se conoce como una macro. Una vez que se define una macro, el preprocesador reemplazará todas las instancias de esa macro en el código con su valor definido antes de que el código se compile.

3. `#endif`: Esta directiva de preprocesador se utiliza para marcar el final de una sección de código que comenzó con `#if`, `#ifdef` o `#ifndef`. Esta directiva le dice al preprocesador que deje de ignorar la inclusión de un archivo si la condición especificada en la directiva `#if`, `#ifdef` o `#ifndef` es falsa. Por ejemplo:

Ejemplo genérico de las directivas del prepocesador:
```cpp
#ifndef SOME_HEADER_H
#define SOME_HEADER_H

// contenido del archivo de encabezado

#endif
```

Ejemplo de una clase de las implementadas:
```cpp
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
  void setPassword(const std::string password);
  void setPrivileges(const std::string privileges);
  void setEmail(const std::string email);

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
```

## Declarar los atributos en private
Aprender que los atributos de cualquier objeto deben de ser privados y si se quieren modificar o acceder a sus valores se deben de definir métodos para ello como público. 
get* para obtener un valor y set* para cambiar el valor de un atributo. Ejemplos:

### Ejemplos de geters y seters
- En este ejemplo, mostramos cómo obtener el NIF (Número de Identificación Fiscal) gracias a getNif(). Destacamos el uso de const en la firma de la función para evitar cambios accidentales en el valor del NIF.
```cpp
std::string getNif() const;
```
- En este ejemplo, mostramos cómo cambiar el NIF (Número de Identificación Fiscal) gracias a setNif(const std::string nif). En este caso const es para asegurarnos que los parametros en el metodo no sean modificados, ojo si que nos permite cambiar el atributo privado correspondiente al NIF del usuario.
```cpp
void setNif(const std::string nif);
```

## Uso de la directiva #include
#include se usa en C++ para incluir el contenido de otros archivos en un archivo fuente, como bibliotecas estándar o archivos de encabezado personalizados, facilitando la reutilización y modularidad del código
Ejemplo TemperatureSensor, el cual es un tipo de sensor, por lo que necesita saber la deifinicion de un objeto Sensor
```cpp
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include <string>

#include "Sensor.h"

class TemperatureSensor : public Sensor {
 public:
  explicit TemperatureSensor(int id, bool active);
  ~TemperatureSensor() override;

  void collectData() override;
  bool checkAllgood() const override;
  void printData() const override;
  std::string stringStatus() const;
  void collectAndPrint();

  friend std::ostream& operator<<(std::ostream& os,
                                  const TemperatureSensor& sensor);
};

#endif  // TEMPERATURESENSOR_H
```
## Declaraciones Anticipadas
Las declaraciones anticipadas en C++ se utilizan para informar al compilador sobre la existencia de una función, clase o variable antes de que se utilicen en el código. Esto permite al compilador compilar el código sin necesidad de tener la definición completa de la función, clase o variable en ese momento. Se utilizan para evitar errores de "referencia indefinida" y para permitir la separación de la interfaz y la implementación en archivos de encabezado y de código fuente, respectivamente.

A continuación un ejemplo de declaración anticipada, tanto el .h como el .cpp. Destacar que lo que cambia es el .h, en el .cpp se tiene que seguir usando la directiva #include. Ejemplo MonitoringSystem.h MonitoringSystem.cpp:

### Ejemplos .h y .cpp con declaraciones anticipadas
- Este es el .h:
```cpp
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
```

- Este es el .cpp (donde se sigue teniendo que usar la directiva #include)
```cpp
#include "MonitoringSystem.h"

#include <iostream>

#include "KeyboardHardware.h"
#include "ScreenHardware.h"
#include "SwitchHardware.h"
using namespace std;

MonitoringSystem::MonitoringSystem(ScreenHardware *screen,
                                   KeyboardHardware *keyboard,
                                   SwitchHardware *sw)
    : screen(screen), keyboard(keyboard), sw(sw) {}

MonitoringSystem::~MonitoringSystem() {
  delete screen;
  delete keyboard;
  delete sw;
}

int MonitoringSystem::getSelection() { return selection_; }

void MonitoringSystem::selectUser() {
  nameSelectedUser_ = askName();
  passwordSelectedUser_ = askPassword();
  nifSelectedUser_ = askNIF();
  privilegesSelectedUser_ = askPrivileges();
  emailSelectedUser_ = askEmail();
}

std::string MonitoringSystem::getName() { return name_; }

std::string MonitoringSystem::getNIF() { return nif_; }

std::string MonitoringSystem::getPassword() { return password_; }

std::string MonitoringSystem::getNameSelectedUser() {
  return nameSelectedUser_;
}

std::string MonitoringSystem::getNIFSelectedUser() { return nifSelectedUser_; }

std::string MonitoringSystem::getPasswordSelectedUser() {
  return passwordSelectedUser_;
}

std::string MonitoringSystem::getPrivilegesSelectedUser() {
  return privilegesSelectedUser_;
}

std::string MonitoringSystem::getEmailSelectedUser() {
  return emailSelectedUser_;
}

bool MonitoringSystem::inputCorrect(int input, int max) {
  bool correct = input >= 1 && input <= max;
  if (!correct) {
    cout << "Invalid input. Please enter an integer that corresponds to one of "
            "the options"
         << endl;
  }
  // Input debe de estar entre 1 y max
  return correct;
}

int MonitoringSystem::askInputInt(int max) {
  int input;

  do {
    input = keyboard->askInput();
  } while (!inputCorrect(input, max));

  return input;
}

void MonitoringSystem::initialScreen() {
  system("clear");
  int options = 2;
  // Muestro de screen la initialWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  screen->initialWindow();
  selection_ = askInputInt(options);
}

void MonitoringSystem::exitScreen() {
  // Borrar terminal y mostrar el exitWindow
  system("clear");
  screen->exitWindow();
}

std::string MonitoringSystem::askName() {
  std::cout << "(NAME) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askPassword() {
  std::cout << "(PASSWORD) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askNIF() {
  std::cout << "(NIF) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askPrivileges() {
  std::cout << "(PRIVILEGES) ";
  return keyboard->stringInput();
}

std::string MonitoringSystem::askEmail() {
  std::cout << "(EMAIL) ";
  return keyboard->stringInput();
}

void MonitoringSystem::loginScreen() {
  // Muestro de screen la loginWindow, luego pido con el keyboard un input hasta
  // que este entre los valores correctos
  system("clear");
  screen->loginWindow();
  name_ = askName();
  password_ = askPassword();
  nif_ = askNIF();
  // std::cout << name_ << " " << password_ << " " << nif_ << endl;
}

void MonitoringSystem::mainWindowAdmin() {
  // Muestro de screen la mainWindowAdmin, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  system("clear");
  int options = 8;
  screen->mainWindowAdmin();
  selection_ = askInputInt(options);
}

void MonitoringSystem::mainWindowEmployee() {
  // Muestro de screen la mainWindowEmployee, luego pido con el keyboard un
  // input hasta que este entre los valores correctos
  system("clear");
  int options = 4;
  screen->mainWindowEmployee();
  selection_ = askInputInt(options);
}

void MonitoringSystem::mainWindowGuest() {
  // Muestro de screen la mainWindowGuest, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  system("clear");
  int options = 3;
  screen->mainWindowGuest();
  selection_ = askInputInt(options);
}

// Opciones del menu

void MonitoringSystem::createUserScreen() {
  // Muestro de screen la createUserWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  system("clear");
  screen->createUserWindow();
  selectUser();
}

void MonitoringSystem::deleteUserScreen() {
  // Muestro de screen la deleteUserWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  system("clear");
  screen->deleteUserWindow();
  selectUser();
}

void MonitoringSystem::updateUserScreen() {
  // Muestro de screen la updateUserWindow, luego pido con el keyboard un input
  // hasta que este entre los valores correctos
  system("clear");
  screen->updateUserWindow();
  selectUser();
}

void MonitoringSystem::displayUsersScreen() {
  // Muestro de screen la displayUsersWindow
  system("clear");
  screen->displayUsersWindow();
  // keyboard->stringInput();
}

void MonitoringSystem::displaySensorsScreen() {
  // Muestro de screen la displaySensorsWindow
  system("clear");
  screen->displaySensorsWindow();
  // keyboard->stringInput();
}

void MonitoringSystem::displayAlarmsScreen() {
  // Muestro de screen la displayAlarmsWindow
  system("clear");
  screen->displayAlarmsWindow();
  // keyboard->stringInput();
}

void MonitoringSystem::turnOnOffSystemScreen() {
  // Muestro de screen la turnOnOffSystemWindow
  system("clear");
  int options = 2;
  screen->turnOnOffSystemWindow();
  selection_ = askInputInt(options);
}

void MonitoringSystem::displayErrorScreen() {
  // Muestro de screen la displayErrorWindow
  system("clear");
  screen->displayErrorWindow();
  keyboard->stringInput();
  exitScreen();
}
```

## Declaración de propios métodos
Declaraciones de propios métodos de cada clase para el comportamiento de cada clase. Destacar que si en el .h estan declaradas como públicas es que se puede acceder a esos metodos, si están en la sección de privado no se podrá acceder directamente a ese metodo, lo más probable es sea un apoyo a un método público.
A continuación algunos ejemplos de métodos y explicación

### Ejemplos de metodós
- Método que no tiene ningún valor de retorno (ejemplo prints, display...):
```cpp
void createUserScreen();
```
- Método que devuelve una string (cádena de caracteres):
```cpp
std::string stringStatus() const;
```
- Método que devuelve un integer (número entero):
```cpp
int sumIntegers(const int i, int j);
```
- Hay más valores que puede retornar un método, como floats, o incluso tipos que hemos definido nosotros como un usuario (en este caso es un puntero al usuario, no directamente el usuario):
```cpp
User* findUser(const User& user) const;
```
## Compilar y ejecutar
### Compilar
- Con el siguiente comando se compila todos los .cpp que se encuntren en SOURCES
```bash
make
```
- Con el siguiente comando se limpia todos los .o de los .cpp que se encuetren en SOURCES
```bash
make clean
```
### Ejecutar
Por defecto el SOURCES tiene todo lo necesrio para compilar el programa principal **main.cpp**. Aquí están los pasos
1. Comprobar que el SOURCES es el necesario para compilar main.cpp, por defecto esta puesto el SOURCES correcto:
```make
SOURCES =  main.cpp GreenHouse.cpp AlarmSensors.cpp UsersServer.cpp MonitoringSystem.cpp AirQualitySensor.cpp Hardware.cpp HydrometerSensor.cpp KeyboardHardware.cpp LightSensor.cpp TemperatureSensor.cpp User.cpp PhSensor.cpp PressureSensor.cpp ScreenHardware.cpp Sensor.cpp SwitchHardware.cpp UsersDatabase.cpp
```
2. Compilar con el comando del apartado anterior:
```bash
make
```
3. Ejecutar el programa, cualquier programa se ejecutara como a continación independientemente del SOURCES del MakeFile
```bash
./main
```