
#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"

void com(uint32_t M,uint32_t D){
    GPIO_PORTK_DATA_R = D;  //MANDAMOS EL DATO POR EL PORTK
    GPIO_PORTM_DATA_R = M;  //MANDAMOS INFORMACI�N DE LOS PINES DONDE EST�N EL e Y EL R/S
    SysCtlDelay(6400);      //RETARDO
    GPIO_PORTM_DATA_R=0;    //BORRAMOS EL ENABLE PARA QUE SEA COMO MANDAR EL PULSO
    SysCtlDelay(64000);//RETARDO PARA PAUSA DRAM�TICA
}
void inst(uint32_t D){
    com(0x4,D);         //COMO TODAS LAS INSTRUCCIONES, VAN A TENER 4 EN EL PORTM,
                        //HICIMOS UNA FUNCI�N PARA INSTRUCCIONES
}
void car(uint32_t D){
    com(0x5,D);         //Y OTRA PARA CARACTERES
}
void muestrapiso(uint32_t D){
    D=0x30+D;                      //QUEREMOS MOSTRAR EL PISO, ENTONCES LO CONVERTIMOS A UN VALOR ASCII
    inst(0x1);                    //limpia el display
    car(0x50);                    //mandamos una P
    car(0x49);                    //mandamos una I
    car(0x53);                    //mandamos una S
    car(0x4F);                    //mandamos una O
    car(D);                       //MANDA EL VALOR CONVERTIDO
}
void mostrarDisplay(void){
    //CONFIGURACI�N DE LCD
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R9 |SYSCTL_RCGCGPIO_R11;   //HABILITAMOS LOS RELOJES DE LOS PUERTOS K Y M
    //CONFIGURACI�N DE LOS PUERTOS DEL DISPLAY LCD
    //PORTK
    GPIO_PORTK_DIR_R |= 0xFF;
    GPIO_PORTK_DEN_R |= 0xFF;     //Se configuran los bits y salidas del puerto D
    GPIO_PORTK_DATA_R = 0x0;
    //PORTM
    GPIO_PORTM_DIR_R |= 0x07;
    GPIO_PORTM_DEN_R |= 0x07;     //Se configuran los bits y salidas del puerto D
    GPIO_PORTM_DATA_R=0;
    inst(0xC);                    //enciende el display
    while(1){muestrapiso(0x1);
    muestrapiso(0x2);
    muestrapiso(0x3);}
}
