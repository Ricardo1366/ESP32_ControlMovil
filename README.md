# Maneja Arduino desde el móvil.

Código de ejemplo para instalar en un ESP32 que le permite recibir datos vía blurtooth desde un móvil. En el ejemplo se esperan un máximo de 4 parámetros donde cada parámetro es interpretado de la siguiente forma:

1. Función a ejecutar. 0 para la primera función definida, 1 para la segunda, etc.
2. Tiempo de encendido en milisegundos. Función blink "0"
3. Tiempo de apagado en milisegundos. Función blink "0"
4. Numero de repeticiones. Cuantas veces se enciende y apaga el led. Función blink "0"

La función 1 enciende el led de forma fija y la 2 lo apaga.
