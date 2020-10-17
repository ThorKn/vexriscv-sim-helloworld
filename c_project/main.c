#include <stdbool.h>
#include "hal.h"

int main(void)
{
    printf("HELLO WORLD\n");
    int a = 4;
    int b = 12;
	int c = 0;
    while (1) {
        c = a + b + c;
		printf("c = %d\n", c);
        printf("LOOP ON\n");
    }
    return 0;
}
