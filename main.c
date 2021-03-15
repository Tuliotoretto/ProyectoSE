#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/tm4c1294ncpdt.h"

#include "recursos/teclado/teclado.h"

void config(void);

int main(void)
{
    puts("Hello, world!");
    config();

	return 0;
}

void config(void) {
    tecladoConfig();
}


