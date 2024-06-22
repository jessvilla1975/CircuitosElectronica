
#include <18F4550.H>
#use delay(clock=4Mhz)
#fuses XT, NOPROTECT, NOPUT, NOWDT, NOBROWNOUT, NOLVP, NOCPD

void main(){
   int8 i;
   set_tris_b(0x00);  // define el puerto b como salida
   set_tris_d(0x00);  // define le puerto d como salida
   
   int8 display[10] = {192,249,164,176,153,146,130,248,128,144};
   while(true){
       for(i=0;i<10;i++){
          output_b(i^0xFF);
          output_d(display[i]);
          delay_ms(200);
       }
   }

}
