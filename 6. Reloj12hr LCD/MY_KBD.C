                    


// Conexiones del teclado.
/* 
            RB3 RB2 RB1 RB0
             !   !   !   !
             |   |   |   |
           |---|---|---|---|
  RB7 <--- | 1 | 2 | 3 | A |
           |---|---|---|---|
  RB6 <--- | 4 | 5 | 6 | B |
           |---|---|---|---|
  RB5 <--- | 7 | 8 | 9 | C |
           |---|---|---|---|
  RB4 <--- | F | 0 | E | D |
           |---|---|---|---|
*/



char kbd_getc()
{  
      char tecla=0;
   
      port_b_pullups(true);
      set_tris_b(0b11110000); // RB3-RB0 salidas,  RB7-RB4  entradas
      output_b(0x0F);
    
      output_low(PIN_B0);
      if (~input(PIN_B4)) 
         tecla='D';
      else if (~input(PIN_B5))
         tecla='C' ;                  
      else if (~input(PIN_B6))
         tecla='B';
      else if (~input(PIN_B7))
         tecla='A' ;                  
      output_high(PIN_B0);   

      output_low(PIN_B1);
      if (~input(PIN_B4)) 
         tecla='E';
      else if (~input(PIN_B5))
         tecla='3';
      else if(~input(PIN_B6))
         tecla='6';
      else if(~input(PIN_B7))
         tecla='9';
      output_high(PIN_B1);
      
      output_low(PIN_B2);
      if (~input(PIN_B4)) 
         tecla='0';
      else if(~input(PIN_B5))
         tecla='2';
      else if(~input(PIN_B6))
         tecla='5';
      else if(~input(PIN_B7))
         tecla='8';
      output_high(PIN_B2);
      
      output_low(PIN_B3);
      if (~input(PIN_B4)) 
         tecla='F';
      else if(~input(PIN_B5))
         tecla='1';
      else if(~input(PIN_B6))
         tecla='4';
      else if(~input(PIN_B7))
         tecla='7' ;                  
      output_high(PIN_B3);   

     port_b_pullups(false);

     return tecla;
}
