/*
Este Programa

*/
#include <18F4550.H> // Selecciona el Microcontrolador
#use delay(clock= 4Mhz)
#include "Mi_LCD.c"
#include "Mi_Teclado.c"
#fuses xt,nowdt,noprotect,put

#use fast_io(b)
#use fast_io(d)
#byte PORTB = 0xF81
#byte PORTD = 0xF83

int X=0;
int Y=0;
float A=0;
float B=0;
float C=0;


void main(void)
{  
   char K;
   int T;
   
   int8 LaTecla;
   set_tris_b(0xf0);
   set_tris_d(0x00);
   lcd_init();
   
   do
   {
     K=kbd_getc(); 
     T= K-48;
     
     if ((K!=0)&&(K!='D')&&(K!='*')&&(K!='A')&&(K!='B')&&(K!='C')&&(K!='#'))
     {
         A=(A*10)+T;
         X++;
         lcd_gotoxy(X,1);
         printf(lcd_putc,"%d",T);
         delay_ms(100);
     }
     
     if(K=='*')
     {
         X=0;
         A=0;
         B=0;
         C=0;
         printf(lcd_putc,"\f");
     }
//////////////////////SUMA/////////////////////////////

     if(K=='D')
     {
         X++;
         Y=1;
         printf(lcd_putc,"+"); 
        do
        {
            K=kbd_getc();
            T=K-48;
           
      if ((K!=0)&&(K!='D')&&(K!='*')&&(K!='A')&&(K!='B')&&(K!='C')&&(K!='#'))
      {
         B=(B*10)+T;
         X++;
         lcd_gotoxy(X,1);
         printf(lcd_putc,"%d",T);
         delay_ms(100);
      }
      
      if(K=='#')
      {
         C=A+B;
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%f",C);
         delay_ms(100);
      }
      
      if(K=='*')
     {
         Y=0;
         X=0;
         A=0;
         B=0;
         C=0;
         printf(lcd_putc,"\f");
     }
     
      } While(Y==1);
        
     }
     
     
/////////////////////Resta///////////////////////////////////////////

if(K=='C')
     {
         X++;
         Y=1;
         printf(lcd_putc,"-"); 
        do
        {
            K=kbd_getc();
            T=K-48;
           
      if ((K!=0)&&(K!='D')&&(K!='*')&&(K!='A')&&(K!='B')&&(K!='C')&&(K!='#'))
      {
         B=(B*10)+T;
         X++;
         lcd_gotoxy(X,1);
         printf(lcd_putc,"%d",T);
         delay_ms(100);
      }
      
      if(K=='#')
      {
         C=A-B;
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%f",C);
         delay_ms(100);
      }
      
      if(K=='*')
     {
         Y=0;
         X=0;
         A=0;
         B=0;
         C=0;
         printf(lcd_putc,"\f");
     }
     
      } While(Y==1);
        
     }
     
     
//////////////////multiplicacion/////////////////////////////     
     
     
     if(K=='B')
     {
         X++;
         Y=1;
         printf(lcd_putc,"x"); 
        do
        {
            K=kbd_getc();
            T=K-48;
           
      if ((K!=0)&&(K!='D')&&(K!='*')&&(K!='A')&&(K!='B')&&(K!='C')&&(K!='#'))
      {
         B=(B*10)+T;
         X++;
         lcd_gotoxy(X,1);
         printf(lcd_putc,"%d",T);
         delay_ms(100);
      }
      
      if(K=='#')
      {
         C=A*B;
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%f",C);
         delay_ms(100);
      }
      
      if(K=='*')
     {
         Y=0;
         X=0;
         A=0;
         B=0;
         C=0;
         printf(lcd_putc,"\f");
     }
     
      } While(Y==1);
        
     }
//////////////////Division////////////////////////

if(K=='A')
     {
         X++;
         Y=1;
         printf(lcd_putc,"/"); 
        do
        {
            K=kbd_getc();
            T=K-48;
           
      if ((K!=0)&&(K!='D')&&(K!='*')&&(K!='A')&&(K!='B')&&(K!='C')&&(K!='#'))
      {
         B=(B*10)+T;
         X++;
         lcd_gotoxy(X,1);
         printf(lcd_putc,"%d",T);
         delay_ms(100);
      }
      
      if(K=='#')
      {
         C=A/B;
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%.3f",C);
         delay_ms(100);
      }
      
      if(K=='*')
     {
         Y=0;
         X=0;
         A=0;
         B=0;
         C=0;
         printf(lcd_putc,"\f");
     }
     
      } While(Y==1);
        
     }

   } while(TRUE);
 }

