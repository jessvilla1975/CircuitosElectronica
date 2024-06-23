#include <18F4550.H> // Selecciona el Microcontrolador
#fuses xt,nowdt,noprotect,put
#use delay(clock= 4Mhz)
#include "Mi_LCD.c"
#include <Mi_Teclado.c>
#use fast_io(b)
#use fast_io(d)
#use fast_io(c)
#byte PORTB = 0xF81
#byte PORTC = 0xF82
#byte PORTD = 0xF83
#byte PORTE = 0xF84
#define  Useg Buffer[7]
#define  Dseg Buffer[6]
#define  Umin Buffer[4]
#define  Dmin Buffer[3]
#define  Uhora Buffer[1]
#define  Dhora Buffer[0]
long  part1;

// Variables Globales

int8 Buffer[8] = {48, 55, 58, 51, 52, 58, 48, 48};
int8 LaTecla; 

#int_TIMER0
void Timer0_int()
{  set_timer0(49910);
   Useg++;
   if (Useg < 58)
      goto  sale;
   Useg = 48;
   Dseg++;
   if (Dseg < 54)
      goto  sale;
   Dseg = 48;
   Umin++;
   if (Umin < 58)
      goto  sale;
   Umin = 48;
   Dmin++;
   if (Dmin < 54)
      goto  sale;
   Dmin = 48;
   Uhora++;
   if (Dhora==48)
      if (Uhora<58)
         goto sale;
   else if (Uhora<51)
         goto Sale;
   Uhora = 48;
   Dhora++;
   if (Dhora < 50)
      goto sale;
   Uhora = 49;
   Dhora= 48;
   sale:lcd_gotoxy(2,2);
   printf(lcd_putc,"%s",Buffer);
   output_toggle(PIN_C0);
}

//**************************************************************************
void MoverBuffer()
{  Buffer[0] = Buffer[1];
   delay_ms(50);
   Buffer[1] = Buffer[3];
    delay_ms(50);
   Buffer[3] = Buffer[4];
    delay_ms(50);
   Buffer[4] = Buffer[6];
    delay_ms(50);
   Buffer[6] = Buffer[7];
    delay_ms(50);
   Buffer[7] = LaTecla;
   Buffer[8] = 0x00;
   lcd_gotoxy(2,2);
   printf(lcd_putc,"%s",Buffer);
}
 //***************************************************************************
 

 void borrar()  //Detiene por break y pone en 0 los buffers
 {
  
    
  Buffer[7] = 48;
  Buffer[6] = 48;
  Buffer[4] = 48;
  Buffer[3] = 48;
  Buffer[1] = 48;
  Buffer[0] = 48;            
    
 }
 
 
 //*****************************************************************************

 void restriccion()  //Restriccion para horas invalidas
 {
  
  if((Buffer[0] >= 50)  ||  (Buffer[3] >= 54)  || (Buffer[6] >= 54) || (Buffer[0] >= 50 ) && (Buffer[1] >=48) || (Buffer[0] >= 49 ) && (Buffer[1] >=51)  )
              
              {  Buffer[7] = 0x00;
                 Buffer[6] = 0x00;
                 Buffer[4] = 0x00;
                 Buffer[3] = 0x00;
                 Buffer[1] = 0x00;
                 Buffer[0] = 0x00;
            
                        }   
              
       else { setup_timer_0(RTCC_DIV_16 | RTCC_INTERNAL); //Reloj continua contando en horas validas
       }
              
              
 }
 
 
//*****************************************************************************
 void comparador()  //compara las 11 para 12
 {
  
  if((Buffer[0] == 49 ) && (Buffer[1] == 49) &&  (Buffer[3] == 53) && (Buffer[4] == 57) && (Buffer[6] == 53) && (Buffer[7] == 57) )
              {  Buffer[7] = 48;
                 Buffer[6] = 48;
                 Buffer[4] = 48;
                 Buffer[3] = 48;
                 Buffer[1] = 50;
                 Buffer[0] = 49;
             
            
                        }   
              
              
 }
/********************************************************************************/
  void comparador2()  //compara las 10 para 11
 {
  
  if((Buffer[0] == 49 ) && (Buffer[1] == 48) &&  (Buffer[3] == 53) && (Buffer[4] == 57) && (Buffer[6] == 53) && (Buffer[7] == 57) )
              {  Buffer[7] = 48;
                 Buffer[6] = 48;
                 Buffer[4] = 48;
                 Buffer[3] = 48;
                 Buffer[1] = 49;
                 Buffer[0] = 49;
             
            
                        }   
              
              
 }
 
void separador1()
{ part1 = buffer[3]*100+buffer[2]*10+buffer[1];
 
}

//*****************************************************************************

void main()
{  set_tris_b(0xF0);
   set_tris_d(0x00);
   set_tris_c(0x00);
   setup_timer_0(RTCC_DIV_16 | RTCC_INTERNAL);
   set_timer0(49910);
   enable_interrupts(INT_TIMER0);
   enable_interrupts(GLOBAL);
   output_c(0xff);
   lcd_init();
   lcd_putc("Hora Actual:");

   while(1)
      {  LaTecla = kbd_getc();
         delay_ms(40);
         if (LaTecla != 0)
               switch(LaTecla)
               {  case 65: break;
            
                  case 66: setup_timer_0(RTCC_DIV_16 | RTCC_INTERNAL);
                           break;
               
                  case 67: restriccion();  //Sigue contando con la restriccion de horas invalidas reinicia
                           
                           
                           break;
               
                   case 68: 
                           setup_timer_0(RTCC_DIV_16 | RTCC_INTERNAL | RTCC_OFF); //Ajustar la hora 
                           borrar();
                           
                           
                           break;
               
                  case 69: 
                           break;
               
                  case 70: break;
               
                  default: MoverBuffer();
                           break;
               }
               
              comparador();
              comparador2();
              
      }
}





