#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "init.h"
#include "..\ClusterHeadReconfiguration\ClusterHeadReconfiguration.h"

int frequency = 1; // 不要用time

int main()
{
    init();
    printf("\n0s: start...\n");

    while (1)
    {
        ClusterHeadReconfiguration(node); // 簇首战毁重构算法
        if (frequency >= 3)
            break;
        sleep(1);
        printf("%ds: continue...\n", frequency);
        frequency++;
    }

    printf("3s: end...\n");
    return 0;
}
