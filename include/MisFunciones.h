#include <Arduino.h>
#include <Config.h>

void LecturaComando();

// Funciones a ejecutar en función de los parámetros recibidos.
void Blink();
void Encender();
void Apagar();

// Declaramos el array de punteros a funciones.
typedef void (*funcion)();

extern funcion Mis_Funciones[];
                
