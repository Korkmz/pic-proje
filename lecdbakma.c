#include <lecdbakma.h>     
#fuses HS                  //FUSES :Bu komut ile kullan�lan mikrodenetleyici ile ilgili 
                           //konfig�rasyon bitlerinin durumunu belirtir.
                           //HS : Y�ksek h�z� ( 8 MHZ )
#use delay(clock=8000000)  //Saat Frekans� belirdik.
#use fast_io(b)            //FAST_�O() komutu ile mikrodenetleyicinin hangi portunu
                           //kulland���n� belirtir.
#include <lcd.c>           //LCD ekran�n k�t�phanesi

void main(){
   set_tris_d(0x00);      //set_tris_d() : Bu komutla porttaki hangi bacaklar�n giri�/��k��
                          //i�in kullanaca�� belirtmektir.
   lcd_init();           //LCD haz�rlamak i�in kullan�lan bir komuttur.
   int sutun=1;           //Ekranda imlecin kay�p olmas�n diye sayi tan�mlad�k.
   
   while(1) {
      if(input(pin_a0)){             //�lk butona t�klad���nda girecek
         if(sutun <=0){              //Eger silme butununa �ok bas�l�rsa sutun s�f�rdan
           sutun=1;                  //k���k olabilir ba�tan ba�latmak i�in 1 degeri atad�k
          }
       lcd_gotoxy(sutun,1);          //�mlecin yerini belirledik.
       printf(lcd_putc, "A");        //Ekrana "A" harfini yazacak.
       sutun++;                      //�mleci bir sonraki sutuna ge�irmesi i�in art�rd�k.
       while(input(pin_a0));         
      }
      
      if(input(pin_a1)){            //�kinci butona t�klad���nda girecek
          if(sutun <=0){
            sutun=1;
           }
        lcd_gotoxy(sutun,1);         //�mlecin yerini belirledik.
        printf(lcd_putc, "L");       //Ekrana "L" harfini yazacak.
        sutun++;                     //�mleci bir sonraki sutuna ge�irmesi i�in art�rd�k.
         while(input(pin_a1));
      }
      
      if(input(pin_a2)){            //���nc� butona t�klad���nda girecek
           if(sutun <=0){
             sutun=1;
            }
        lcd_gotoxy(sutun,1);         //�mlecin yerini belirledik.
        printf(lcd_putc, "I");       //Ekrana "I" harfini yazacak.
        sutun++;                     //�mleci bir sonraki sutuna ge�irmesi i�in art�rd�k.
         while(input(pin_a2));
      }
       
      if(input(pin_a3)){             //D�rt�nc� butona t�klad���nda girecek
         if(sutun <=0){              //Bu buton Silme yapar.
           sutun=1;
         }
         sutun--;                    //Silme yapmas� i�in bir �nceki sutuna gitmesi gerek
         lcd_gotoxy(sutun,1);        //�mlecin yerini belirledik.
         printf(lcd_putc, " ");      //Bir �nceki sutuna girdi ve oray� bo�lukla degi�tirdi
         while(input(pin_a3));       //ve silme ba�ar�l� bir �ekilde tamamland�.
      }
   }

}
