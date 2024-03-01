#include <MisFunciones.h>

funcion Mis_Funciones[]{&Blink, &Encender, &Apagar};

byte numeroFunciones = sizeof(Mis_Funciones) / sizeof(funcion);
// Lee los datos recibidos por bluetooth y guarda el comando y los parámetros en una estructura "mensajeBT"
void LecturaComando()
{
  // Antes de leer los nuevos parámetros borramos los anteriores.
  memset(parametros, 0, sizeof(parametros));

  contador = 0;
  // La cadena puede tener distintos valores separados por "," (coma).
  // Leemos el comando y los parámetros uno a uno.
  trozo = strtok(ordenBt, separador);

  // Estamos leyendo mientras hay parámetros o hasta el máximo número de parámetros
  // para no desbordar el array.
  while (trozo != NULL && contador < NUMEROPARAMETROS)
  {
    // Copiamos el valor de trozo al array de comandos en el índice correspondiente.
    memcpy(parametros[contador], trozo, LONGMAXPARAMETRO);

    // Cargamos en "trozo" el siguiente parámetro de la cadena.
    trozo = strtok(NULL, separador);
    contador++;
  }
}

void Blink()
{
#ifdef DEBUG
  Serial.println("Ejecutando función blink.");
#endif
  int tiempoEncendido;
  int tiempoApagado;
  int repeticiones;
  tiempoEncendido = atoi(parametros[3]);
  tiempoApagado = atoi(parametros[2]);
  repeticiones = atoi(parametros[1]);
  for (int i = 0; i < repeticiones; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(tiempoEncendido);
    digitalWrite(LED_BUILTIN, LOW);
    delay(tiempoApagado);
  }
};

void Encender()
{
#ifdef DEBUG
  Serial.println("Ejecutando función Encender.");
#endif
  digitalWrite(LED_BUILTIN, HIGH);
}

void Apagar()
{
#ifdef DEBUG
  Serial.println("Ejecutando función Apagar.");
#endif
  digitalWrite(LED_BUILTIN, LOW);
}