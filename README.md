# Serie de Programas de Circuitos con PIC18F4550 Micros

Este proyecto muestra cómo controlar displays de 7 segmentos utilizando un microcontrolador PIC18F4550. El código está escrito en C y configurado para funcionar con una frecuencia de reloj de 4MHz.

## Descripción
Esta serie de programas demuestra cómo utilizar el microcontrolador PIC18F4550 para diversas aplicaciones en circuitos electrónicos. Los ejemplos incluyen el uso de displays de 7 segmentos, pantallas LCD, control de motores, y comunicación serial.

Programa

## Requisitos

- Microcontrolador PIC18F4550
- Cristal de 4MHz
- Displays de 7 segmentos
- Compilador CCS C
- Proteus

## Configuración del PIC

El PIC18F4550 está configurado con los siguientes fusibles:

- `XT`: Oscilador XT para cristales <= 4MHz
- `NOWDT`: Deshabilita el watchdog timer
- `NOPROTECT`: No protege el código
- `PUT`: Power-up Timer habilitado

## Librerias necesarias
- #include <18F4550.h>
- #fuses XT, NOWDT, NOPROTECT, PUT
- #use delay(clock=4Mhz)
- #include <lcd.c>

## Programa 1: Control de Displays de 7 Segmentos
El programa enciende un display de 7 segmentos conectado a los puertos B y D del PIC18F4550. Los puertos están configurados como salidas y se utiliza una matriz para definir los valores de cada dígito que se muestra en el display. Es un contador ascedente de 0-9.
![1](https://github.com/jessvilla1975/CircuitosElectr-nica/assets/114515509/5934a634-fc52-469e-97e7-e4bab1bfd7c7)

## Programa 2: Control de Displays de 7 Segmentos con Buffer de Dígitos
Este código en C está diseñado para un microcontrolador PIC18F4550 y controla un display de 7 segmentos, programando una alarma y un cronómetro. Los tres primeros elementos del buffer se utilizan para la alarma, con funciones para incrementar, decrementar y resetear valores, mientras que los tres últimos elementos se usan para el cronómetro. El cronómetro se inicia con la tecla Enter, y cuando ambos segmentos del buffer coinciden, el display parpadea como una alarma. El código también incluye funciones para actualizar continuamente el display mostrando los valores del buffer.

![2](https://github.com/jessvilla1975/CircuitosElectr-nica/assets/114515509/4b5e9890-06a6-4e4e-8834-c0402a48a082)

## Programa 3: Pacman
Este código en C para un microcontrolador PIC18F4550 controla un LCD para simular un juego de Pac-Man. Pac-Man se mueve automáticamente a lo largo de la pantalla del LCD, alternando entre diferentes posiciones de la boca (abierta, cerrada, arriba, abajo) para crear una animación. 

![3](https://github.com/jessvilla1975/CircuitosElectr-nica/assets/114515509/a53c531f-7438-4dac-8692-d965de99e767)7


## Programa 4: Secuencia de Iluminación de LEDs Ocho Loco
Este código en C para un microcontrolador PIC18F4550 controla una secuencia de encendido y apagado de LEDs conectados a los puertos B y C. Configura ambos puertos como salidas y ejecuta un ciclo donde los LEDs se encienden uno por uno con un retardo decreciente. Cuando el retardo es menor a 50 ms, se reinicia y todos los LEDs parpadean rápidamente durante 10 ciclos.

![OCHOLOCO](https://github.com/jessvilla1975/CircuitosElectronica/assets/114515509/533577c1-7373-4071-a4cb-694df1119f46)

## Programa 5: Desplazamiento de Texto en LCD
Este código en C para un microcontrolador PIC18F4550 despliega y desplaza un texto en una pantalla LCD. Configura los puertos B y D como salidas, y utiliza una función para imprimir el nombre "Microprocesadores-I" en una posición que se incrementa continuamente, creando un efecto de desplazamiento. El texto se reinicia al llegar a la posición final, repitiendo el ciclo.

![ANUNCIO](https://github.com/jessvilla1975/CircuitosElectronica/assets/114515509/ea6022b3-a94a-446a-bbb6-2d0b4bf8ee96)

## Programa 6: Reloj con LCD y Teclado
Este código en C para un microcontrolador PIC18F4550 implementa un reloj que muestra la hora actual en una pantalla LCD y permite ajustes a través de un teclado matricial. Utiliza un buffer para almacenar y actualizar los valores de horas, minutos y segundos, y controla el flujo del tiempo mediante interrupciones del temporizador. Además, incluye funciones para restringir horas inválidas y ajustar la hora actual, así como comparadores para manejar cambios específicos en la hora.

![reloj](https://github.com/jessvilla1975/CircuitosElectronica/assets/114515509/b082c1fe-4882-47e9-97bb-b6d67f70f540)

## Programa 7: Creación de Caracteres Personalizados en LCD
Este código en C para un microcontrolador PIC18F4550 crea y muestra caracteres personalizados en una pantalla LCD. Define cuatro patrones en la memoria CGRAM del LCD para formar un logotipo y muestra el texto "Electronica" y "Univalle". Los caracteres personalizados se almacenan en posiciones específicas de la CGRAM y se imprimen en la pantalla en ubicaciones designadas.

![logo](https://github.com/jessvilla1975/CircuitosElectronica/assets/114515509/42095bc5-b218-4c10-a24d-857b83e5d720)

## Programa 8: Calculadora Básica con LCD y Teclado
Este programa en C para un microcontrolador PIC18F4550 implementa una calculadora básica que utiliza una pantalla LCD y un teclado matricial. Las operaciones soportadas son suma, resta, multiplicación y división. Los resultados se muestran en el LCD.

![CALCULADORA](https://github.com/jessvilla1975/CircuitosElectronica/assets/114515509/e2a87eb6-6644-48d1-b75e-6390e064ce99)
