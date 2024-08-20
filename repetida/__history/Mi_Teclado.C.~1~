                    


// Conexiones del teclado.
/* 
            RB  RB  RB  RB
  Y0 --------------------+
  Y1 ----------------+   |
  Y2 ------------+   |   |
  Y3 --------+   |   |   |         
             |   |   |   |
           |---|---|---|---|
  RB4 ---> | 1 | 2 | 3 | A |
           |---|---|---|---|
  RB5 ---> | 4 | 5 | 6 | B |
           |---|---|---|---|
  RB6 ---> | 7 | 8 | 9 | C |
           |---|---|---|---|
  RB7 ---> | * | 0 | # | D |
           |---|---|---|---|
*/

char kbd_getc()
{  
      char tecla=0;
   

      set_tris_b(0b11111000); // RB3-RB0 salidas,  RB7-RB4  entradas
      output_b(0x07);
    
      output_b(0);
      if (~input(PIN_B4)) 
         tecla='D';
      else if (~input(PIN_B5))
         tecla='C' ;                  
      else if (~input(PIN_B6))
         tecla='B';
      else if (~input(PIN_B7))
         tecla='A' ; 
         
      output_b(1);
      if (~input(PIN_B4)) 
         tecla='#';
      else if (~input(PIN_B5))
         tecla='9';
      else if(~input(PIN_B6))
         tecla='6';
      else if(~input(PIN_B7))
         tecla='3';

      output_b(2);
      if (~input(PIN_B4)) 
         tecla='0';
      else if(~input(PIN_B5))
         tecla='8';
      else if(~input(PIN_B6))
         tecla='5';
      else if(~input(PIN_B7))
         tecla='2';

      output_b(3);
      if (~input(PIN_B4)) 
         tecla='*';
      else if(~input(PIN_B5))
         tecla='7';
      else if(~input(PIN_B6))
         tecla='4';
      else if(~input(PIN_B7))
         tecla='1' ;                     
     return tecla;
}
