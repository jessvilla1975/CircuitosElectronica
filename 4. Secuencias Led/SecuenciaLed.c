#include <18F4550.h>
//| tx cristales <= 4Mhz; ht cristales > 4Mhz;|,  nowdt -> no usa el recurso de reset al estar en un bucle, noproject-> no protejer codigo
#fuses xt,nowdt,noprotect,put 
#use delay(clock = 4Mhz)
#use fast_io(b)
#use fast_io(d)

void main(){
   set_tris_b(0x00);  // define el puerto b como salida
   set_tris_c(0x00); // define le puerto d como salida
   output_d(0xFF);
   output_c(0xFF);
   int delay = 200;
   while(true){

       output_b(0b11011111); //b5
       delay_ms(delay);
       output_b(0b11101111); //b4
       delay_ms(delay);
       output_b(0b11111011); // b2
       delay_ms(delay);
       output_b(0b11111110); //b0
       delay_ms(delay);
       output_b(0b11111101); //b1
       delay_ms(delay);
       output_b(0b11110111); //b3
       delay_ms(delay);
       output_b(0b11011111); //b5
       delay_ms(delay);
       output_b(0b11101111); //b4
       delay_ms(delay);
       output_b(0b10111111); //b6
       delay_ms(delay);
       output_b(0b11111111); //apaga los_b
       
       output_c(0b11111110); //d0
       delay_ms(delay);
       output_c(0b11111101); //d1
       delay_ms(delay);
       
       output_c(0b11111111); //apaga los_d
        
       output_b(0b01111111); //b7
       delay_ms(delay);
       delay -= 50;
       if(delay < 50){
           delay = 200;
           int i;
           for(i = 0; i < 10; i++){
                   output_c(0b00000000); 
                   output_b(0b00000000); 
                   delay_ms(200);
                   output_c(0b11111111); 
                   output_b(0b11111111); 
           }
       }
      
   }
}

