#include <18F4550.H>
#use delay(clock=4Mhz)
#fuses XT, NOPROTECT, NOPUT, NOWDT, NOBROWNOUT, NOLVP, NOCPD
#include "Mi_LCD.c"


void main()
{

  lcd_init();

  lcd_send_byte(0,0x40); // escribe en la cgram (0), direccion 0x40
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x10); // |X| | | | |
  lcd_send_byte(1,0x10); // |x| | | | |
  lcd_send_byte(1,0x10); // |x| | | | | 
  lcd_send_byte(1,0x10); // |x| | | | |
  lcd_send_byte(1,0x17); // |x|X| | | |
  lcd_send_byte(1,0x14); // |x|X|X| | |
  lcd_send_byte(1,0x14); // |x| | | | |

  //segunda parte del logo

  lcd_send_byte(0,0x48); //escribe en la cgram (1), direccion 0x48
  lcd_send_byte(1,0x1F); // |X|X|X|X|X|
  lcd_send_byte(1,0x07); // |X|X|X|X|X|
  lcd_send_byte(1,0x07); // |X|X|x|x|x|
  lcd_send_byte(1,0x07); // | | | | |X|
  lcd_send_byte(1,0x07); // | | | | |x|
  lcd_send_byte(1,0x1F); // | | | |x|x|
  lcd_send_byte(1,0x03); // |x| |X|x|x|
  lcd_send_byte(1,0x03); // |X|X|X|X|X|


  //tercera parte del logo
  lcd_send_byte(0,0x50); // escribe en la cgram (2), direccion 0x50
  lcd_send_byte(1,0x1C); // |x| | | | |
  lcd_send_byte(1,0x1C); // |x|x| | | |
  lcd_send_byte(1,0x1E); // |x|x|x| | |
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x00); // | | | | | |


 //cuarta parte del logo
  lcd_send_byte(0,0x58); // escribe en la cgram (3), direccion 0x58
  lcd_send_byte(1,0x03); // | | | | |x|
  lcd_send_byte(1,0x03); // | | | | |x|
  lcd_send_byte(1,0x07); // | | | |x|x|
  lcd_send_byte(1,0x0F); // |x| | |x|x|
  lcd_send_byte(1,0x1F); // |x| |x|x|x|
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x00); // | | | | | |
/*


  lcd_send_byte(0,0x60); // escribe en la cgram (4), direccion 0x60
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x0A); // | |x| |x| |
  lcd_send_byte(1,0x11); // |x| | | |x|
  lcd_send_byte(1,0x11); // |x| | | |x|
  lcd_send_byte(1,0x1B); // |x|x| |x|x|
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x0E); // | |x|x|x| |
  lcd_send_byte(1,0x00); // | | | | | |



  /*lcd_send_byte(0,0x68); // escribe en la cgram (5), direccion 0x68
  lcd_send_byte(1,0x00); // | | | | | |
  lcd_send_byte(1,0x0E); // | |x|x|x| |
  lcd_send_byte(1,0x1F); // |x|x|x|x|x|
  lcd_send_byte(1,0x1B); // |x|x| |x|x|
  lcd_send_byte(1,0x11); // |x| | | |x|
  lcd_send_byte(1,0x11); // |x| | | |x|
  lcd_send_byte(1,0x0A); // | |x| |x| |
  lcd_send_byte(1,0x00); // | | | | | |
*/
  
  
    lcd_gotoxy(4,1);
    printf(lcd_putc,"Electronica");  
    lcd_gotoxy(6,2);
    printf(lcd_putc,"Univalle");   
  
    lcd_gotoxy(1,1);
    lcd_send_byte(1,0);  //imprime primera parte
      
    lcd_gotoxy(2,1);
    lcd_send_byte(1,1);  //imprime segunda parte
    
    lcd_gotoxy(1,2);
    lcd_send_byte(1,2);  //imprime tercera parte
    
    lcd_gotoxy(2,2);
    lcd_send_byte(1,3);  //imprime cuarta parte
  
}
