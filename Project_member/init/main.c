#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "init.h"
#include "..\OffNetRejoin\OffNetRejoin.h"

int frequency = 1; // 不要用time

int main()
{
    init();
    printf("\n0s: start...\n");

    while (1)
    {
        OffNetRejoin(node);
        if (frequency >= 3)
            break;
        sleep(1);
        printf("%ds: continue...\n", frequency);
        frequency++;
    }

    printf("3s: end...\n");
    return 0;
}
