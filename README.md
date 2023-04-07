# Project name --> Juego Pong

** Herramientas necesarias
   -- 1. Una Placa Arduino R3.
   -- 2. Una placa breadboard.
   -- 3. Una tira neopixel strip 8.
   -- 4. Dos pushbutton.
   -- 5. Dos resistor con resistencia de 470 Ohm.
   -- 6. 3m de clave UTP.
   -- 7. (Opcional) Escojer cables de:
           .Color rojo para la conexion de los pushbutton.
           .Color verde para la tira led neopixel strip 8.
           .Color negro para la resistencia.

** Instalacion
   -- 1. Conectar la tira de leds en el placa breadboard.
   -- 2. Conectar el cable verde en la tira(entrada superior izquierda) y la entrada 7 de la placa arduino.
   -- 3. Conectar el cable rojo en la tira(entrada central izquierda) y la entrada 5V de la placa arduino.
   -- 4. Conectar el cable negro en la tira(entrada inferior izquierda) y la entrada GND de la placa arduino.
   -- 5. Conectar los pushbutton uno en cada extremo de la breadboard.
   -- 6. Conectar el cable rojo en el primer pushbutton y en la entrada 5 de la placa arduino.
   -- 7. Conectar el cable rojo en el segundo pushbutton y en la entrada 4 de la placa arduino.
   -- 8. Conectar el cable rojo de los pushbutton y en la entrada de 5V de la placa arduino.
   -- 9. Conectar la resistencia en los pushbutton.
   --10. Conectar el cable negro en la primera resistencia y en la entrada GND de la placa arduino.

** Descripcion
   -- Consiste en un juego donde tenemos 7 leds, al iniciar los leds comienzan en color azul al llegar al
      extremo de la tira led espera 1seg a que el jugados presione el boton para continuar, en caso de
      pasado el tiempo el juego nos muestra una led de color rejo y vuelve a iniciar el juego.

** Tecnologias utilizadas
   .Arduino
   .Tinkercat