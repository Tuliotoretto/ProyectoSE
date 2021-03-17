#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/tm4c1294ncpdt.h"

#include "recursos/teclado/teclado.h"
#include "recursos/display/display.h"

void config(void);
char teclaP;
int main(void)
{
    config();

	return 0;
}

void config(void) {
    tecladoConfig();
}


