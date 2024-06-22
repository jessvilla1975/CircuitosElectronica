# Serie de Programas de Circuitos con PIC18F4550

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

![3](https://github.com/jessvilla1975/CircuitosElectr-nica/assets/114515509/a53c531f-7438-4dac-8692-d965de99e767)
