#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c1294ncpdt.h"
#include "teclado.h"


uint8_t d_uint8Dato;

uint32_t ui32Loop;
uint8_t  tecla1;
uint8_t  tecla2;
uint8_t  tecla3;
uint8_t  caracter1;

void tecladoConfig(void) {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R14 | SYSCTL_RCGCGPIO_R7 | SYSCTL_RCGCGPIO_R12 ;
    ui32Loop = SYSCTL_RCGCGPIO_R;


    GPIO_PORTQ_DIR_R   =0xF;     // bit 7 6 5 4 3 2 1 0
    GPIO_PORTQ_DEN_R   =0xF;     //             1 1 1 1  =0xF
    GPIO_PORTQ_DATA_R  =0x0;

    GPIO_PORTH_AHB_DIR_R  =0x0;
    GPIO_PORTH_AHB_DEN_R  =0xF;
    GPIO_PORTH_AHB_PUR_R  =0xF;

    GPIO_PORTN_DIR_R   =0x03;
    GPIO_PORTN_DEN_R   =0x03;
    GPIO_PORTN_DATA_R  =0x0;
}

void retardotecla(){
    uint32_t retardotecla;
    //retardo=4000;
    retardotecla=340000;
    while(retardotecla>1){
    retardotecla=retardotecla-1;
    }
}

char caracter(int y, int x){
    if((x==0x0E) &&(y==0x0E)){ return '1';}
    if((x==0x0D) &&(y==0x0E)){ return '2';}
    if((x==0x0B) &&(y==0x0E)){ return '3';}
    if((x==0x07) &&(y==0x0E)){ return 'A';}

    if((x==0x0E) &&(y==0x0D)){ return '4';}
    if((x==0x0D) &&(y==0x0D)){ return '5';}
    if((x==0x0B) &&(y==0x0D)){ return '6';}
    if((x==0x07) &&(y==0x0D)){ return 'B';}

    if((x==0x0E) &&(y==0x0B)){ return '7';}
    if((x==0x0D) &&(y==0x0B)){ return '8';}
    if((x==0x0B) &&(y==0x0B)){ return '9';}
    if((x==0x07) &&(y==0x0B)){ return 'C';}

    if((x==0x0E) &&(y==0x07)){ return '*';}
    if((x==0x0D) &&(y==0x07)){ return '0';}
    if((x==0x0B) &&(y==0x07)){ return '#';}
    if((x==0x07) &&(y==0x07)){ return 'D';}
}

char decodifica(int cordenaday){
      GPIO_PORTQ_DATA_R  =0x0E;
      if(GPIO_PORTH_AHB_DATA_R==cordenaday){
        return caracter(GPIO_PORTQ_DATA_R,cordenaday);
      }
      GPIO_PORTQ_DATA_R  =0x0D;
      if(GPIO_PORTH_AHB_DATA_R==cordenaday){
        return caracter(GPIO_PORTQ_DATA_R,cordenaday);
      }
      GPIO_PORTQ_DATA_R  =0x0B;
      if(GPIO_PORTH_AHB_DATA_R==cordenaday){
         return caracter(GPIO_PORTQ_DATA_R,cordenaday);
      }
      GPIO_PORTQ_DATA_R  =0x07;
      if(GPIO_PORTH_AHB_DATA_R==cordenaday){
         return caracter(GPIO_PORTQ_DATA_R,cordenaday);
      }


}

char tecla(void){
    if ((GPIO_PORTH_AHB_DATA_R & 0X0F)!=1){
        retardotecla();
        GPIO_PORTQ_DATA_R  =0x00;
        tecla1=0;
        tecla2=0;
        tecla1=GPIO_PORTH_AHB_DATA_R;
        retardotecla();
        tecla2=GPIO_PORTH_AHB_DATA_R;
        if((tecla1 != 0x0F)&&(tecla1==tecla2)){
            caracter1=decodifica(tecla1);
           while((tecla1 == tecla2) && 1){
               tecla3=GPIO_PORTH_AHB_DATA_R;
               tecla2=tecla3;
           }
            return caracter1;
            }
     }
}
