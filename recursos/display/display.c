
#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "driverlib/rom_map.h"
#include "sysctl.h"

#include "display.h"

void com(uint32_t M,uint32_t D){
    GPIO_PORTK_DATA_R = D;  //Dato de control al puerto K
    GPIO_PORTM_DATA_R = M;  //Dato al puerto M
    SysCtlDelay(6400);
    GPIO_PORTM_DATA_R=0;    //BORRAMOS EL ENABLE PARA QUE SEA COMO MANDAR EL PULSO
    SysCtlDelay(64000);//RETARDO PARA PAUSA DRAM�TICA
}

void inst(uint32_t D){
    com(0x4,D);         //Todas las intrucciones tienen un 4 en puerto M (Enable)

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
}

void mostrarDisplay(void){
    inst(0xF);                    //enciende el display
    muestrapiso(0x1);
}

void displayConfig(void) {

    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R9 |SYSCTL_RCGCGPIO_R11;   //HABILITA LOS RELOJES DE LOS PUERTOS K Y M

    //PORTK
    GPIO_PORTK_DIR_R |= 0xFF;   //bit 7 6 5 4 3 2 1 0
    GPIO_PORTK_DEN_R |= 0xFF;   //    1 1 1 1 1 1 1 1
    GPIO_PORTK_DATA_R = 0x0;

    //PORTM
    GPIO_PORTM_DIR_R |= 0x07;   //bit 7 6 5 4 3 2 1 0
    GPIO_PORTM_DEN_R |= 0x07;   //              1 1 1
    GPIO_PORTM_DATA_R=0;
}
