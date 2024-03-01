#include <Arduino.h>
#include <MisFunciones.h>

BluetoothSerial BTSerial;                                // Dispositivo bluetooth
char ordenBt[NUMEROPARAMETROS * (LONGMAXPARAMETRO + 1)]; // Array donde recibimos la orden por bluetooth.
char *trozo;                                             // Variable para almacenar los parámetros.
char separador[] = {","};                                // Separadores
bool mensajeRecibido = false;
byte contador;

// Array para almacenar los parámetros pasados por bluetooth
char parametros[NUMEROPARAMETROS][LONGMAXPARAMETRO + 1];

void setup()
{
  Serial.begin(115200);

  // Activamos el módulo bluetooth serial como "cliente".
  BTSerial.begin(NOMBREDISPOSITIVO, false);

#ifdef DEBUG
  Serial.printf("\nEl dispositivo \"%s\" Está iniciado.\nAhora debes emparejarlo por BlueTooth!\n", NOMBREDISPOSITIVO);
  Serial.printf("El número de funciones definidas es %u", numeroFunciones);
#endif
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  // Comprobamos si hemos recibido datos a traves de blueTooth
  if (BTSerial.available())
  {
    // Antes de leer la nueva instrucción borramos la anterior.
    memset(ordenBt, 0, sizeof(ordenBt));
    // Guardamos la cadena recibida en un char array.
    BTSerial.readString().toCharArray(ordenBt, sizeof(ordenBt));
    mensajeRecibido = true;
  }

  if (mensajeRecibido)
  {
    mensajeRecibido = false;
    LecturaComando();
#ifdef DEBUG
    Serial.printf("\nSe han recibido %u parámetros\n", contador);
    for (byte i = 0; i < contador; i++)
    {
      Serial.printf("Parámetro %u = %s\n", i + 1, parametros[i]);
    }
#endif
    // LLamamos a la función pasada por bluetooth
    Mis_Funciones[atoi(parametros[0])]();
  }
}