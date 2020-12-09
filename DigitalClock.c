#include <digitalClock.h>

#define buttonStop input(PIN_A4)
#define buttonDigit input(PIN_A5)
#define buttonIncrement input(PIN_E0)
#define buttonDecrement input(PIN_E1)

int milisecondcounter = 0; 
int secondcounter = 0;
int minutecounter = 0;
int hourcounter = 0;
int secondcounter1 = 0; int secondcounter2 = 0;   //saniye onlar ve birler basamaðýndan oluþuyor.
int minutecounter1 = 0; int minutecounter2 = 0;  //dakika birler ve onlar basamaðýndan oluþuyor.
int hourcounter1 = 0;   int hourcounter2=0;     //saat birler ve onlar basamaðýndan oluþuyor.
int i = 0;
int stop = 0;

//Timer Counter
#int_timer1
void timer1(){
 output_a(milisecondcounter);
 secondcounter1 = secondcounter%10;
 secondcounter2 = (secondcounter/10)%10;
 output_b(secondcounter1 | secondcounter2<<4);
 
 minutecounter1 = minutecounter%10;
 minutecounter2 = (minutecounter/10)%10;
 output_c(minutecounter1 | minutecounter2 <<4);

 hourcounter1 = hourcounter % 10 ;
 hourcounter2 = (hourcounter/10)%10;
 output_d(hourcounter1 | hourcounter2 <<4);
 
 if(buttonStop == 0){
   milisecondcounter++;
 }
 if(milisecondcounter == 10){
   milisecondcounter = 0;
   secondcounter++;
   
   if(secondcounter == 60){
      secondcounter = 0;
      minutecounter++;
      
      if(minutecounter == 60){
         minutecounter = 0;
         hourcounter++;
         
         if(hourcounter == 24){
          hourcounter = 0;
          }
      }
    }
  }

}

void main()
{  
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   enable_interrupts(int_timer1);
   enable_interrupts(global);
 
   while(TRUE)
   {
      if(buttonStop==1)
      {
         stop = 1;
      }
      else
      {
         stop = 0;
      }
    
      if(buttonStop == 1)
      {
         while(TRUE)
            {
               if(buttonDigit == 1)
                  {
                     i++;
                     if(i==4)
                        {
                           i=1;
                        }
                  }
                  switch(i)
                  {
                     case 1:
                     if(buttonIncrement == 1)
                     {
                        secondcounter++;
                        if(secondcounter == 60)
                        {
                           secondcounter = 0;
                           minutecounter++;
                           if(minutecounter ==60)
                           {
                              minutecounter = 0;
                              hourcounter++;
                              if(hourcounter == 24)
                              {
                                 hourcounter = 0;
                              }
                           }
                        }
                     }
                     
                     else if(buttonDecrement ==1)
                     {
                        secondcounter--;
                        if(secondcounter == -1)
                           {
                              secondcounter = 59;
                              minutecounter--;
                              if(minutecounter == -1)
                                 {
                                    minutecounter = 59;
                                    hourcounter--;
                                    if(hourcounter ==-1)
                                    {
                                       hourcounter = 23;
                                    }
                                 }
                           }
                     }
                     delay_ms(500);
                     break;
                     
                     case 2:
                     if(buttonIncrement == 1)
                     {
                        minutecounter++;
                        if(minutecounter == 60)
                        {
                           minutecounter = 0;
                           hourcounter++;
                           if(hourcounter == 24)
                           {
                              hourcounter =0;
                           }
                        }
                     }
                     else if(buttonDecrement ==1)
                     {
                        minutecounter--;
                        if(minutecounter == -1)
                        {
                           minutecounter = 59;
                           hourcounter--;
                           if(hourcounter ==-1)
                              {
                                 hourcounter = 23;
                              }
                        }
                     }
                     delay_ms(500);
                     break;
                     
                     case 3:
                        if(buttonIncrement ==1)
                        {
                           hourcounter++;
                           if(hourcounter==24)
                              {
                              hourcounter = 0;
                              }
                        }
                        else if(buttonDecrement ==1)
                        {
                           hourcounter--;
                           if(hourcounter == -1)
                           {
                              hourcounter = 23;
                           }
                        }
                        delay_ms(500);
                        break;
                  }
            }
      }
   }
   }

                        
                   
 
