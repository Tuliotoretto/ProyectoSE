#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c1294ncpdt.h"
#include "teclado.h"

void tecladoConfig(void) {
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R14 | SYSCTL_RCGCGPIO_R7
}

