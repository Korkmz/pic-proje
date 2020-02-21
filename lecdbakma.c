#include <lecdbakma.h>     
#fuses HS                  //FUSES :Bu komut ile kullanýlan mikrodenetleyici ile ilgili 
                           //konfigürasyon bitlerinin durumunu belirtir.
                           //HS : Yüksek hýzý ( 8 MHZ )
#use delay(clock=8000000)  //Saat Frekansý belirdik.
#use fast_io(b)            //FAST_ÝO() komutu ile mikrodenetleyicinin hangi portunu
                           //kullandýðýný belirtir.
#include <lcd.c>           //LCD ekranýn kütüphanesi

void main(){
   set_tris_d(0x00);      //set_tris_d() : Bu komutla porttaki hangi bacaklarýn giriþ/çýkýþ
                          //için kullanacaðý belirtmektir.
   lcd_init();           //LCD hazýrlamak için kullanýlan bir komuttur.
   int sutun=1;           //Ekranda imlecin kayýp olmasýn diye sayi tanýmladýk.
   
   while(1) {
      if(input(pin_a0)){             //Ýlk butona týkladýðýnda girecek
         if(sutun <=0){              //Eger silme butununa çok basýlýrsa sutun sýfýrdan
           sutun=1;                  //küçük olabilir baþtan baþlatmak için 1 degeri atadýk
          }
       lcd_gotoxy(sutun,1);          //Ýmlecin yerini belirledik.
       printf(lcd_putc, "A");        //Ekrana "A" harfini yazacak.
       sutun++;                      //Ýmleci bir sonraki sutuna geçirmesi için artýrdýk.
       while(input(pin_a0));         
      }
      
      if(input(pin_a1)){            //Ýkinci butona týkladýðýnda girecek
          if(sutun <=0){
            sutun=1;
           }
        lcd_gotoxy(sutun,1);         //Ýmlecin yerini belirledik.
        printf(lcd_putc, "L");       //Ekrana "L" harfini yazacak.
        sutun++;                     //Ýmleci bir sonraki sutuna geçirmesi için artýrdýk.
         while(input(pin_a1));
      }
      
      if(input(pin_a2)){            //Üçüncü butona týkladýðýnda girecek
           if(sutun <=0){
             sutun=1;
            }
        lcd_gotoxy(sutun,1);         //Ýmlecin yerini belirledik.
        printf(lcd_putc, "I");       //Ekrana "I" harfini yazacak.
        sutun++;                     //Ýmleci bir sonraki sutuna geçirmesi için artýrdýk.
         while(input(pin_a2));
      }
       
      if(input(pin_a3)){             //Dörtüncü butona týkladýðýnda girecek
         if(sutun <=0){              //Bu buton Silme yapar.
           sutun=1;
         }
         sutun--;                    //Silme yapmasý için bir önceki sutuna gitmesi gerek
         lcd_gotoxy(sutun,1);        //Ýmlecin yerini belirledik.
         printf(lcd_putc, " ");      //Bir önceki sutuna girdi ve orayý boþlukla degiþtirdi
         while(input(pin_a3));       //ve silme baþarýlý bir þekilde tamamlandý.
      }
   }

}
