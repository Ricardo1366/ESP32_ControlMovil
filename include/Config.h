#include <Arduino.h>
#include <BluetoothSerial.h>

#define NUMEROPARAMETROS 5
#define LONGMAXPARAMETRO 6
#define NOMBREDISPOSITIVO "MakAlc_ESP32s"
#define DEBUG

extern BluetoothSerial BTSerial;    // Dispositivo bluetooth
extern char ordenBt[];              // Array donde recibimos la orden por bluetooth.
extern char *trozo;                 // Variable para almacenar los parámetros.
extern char separador[];            // Separadores
extern bool mensajeRecibido;
extern byte contador;
extern byte numeroFunciones;
// Array para almacenar los parámetros pasados por bluetooth
extern char parametros[NUMEROPARAMETROS][LONGMAXPARAMETRO + 1];

