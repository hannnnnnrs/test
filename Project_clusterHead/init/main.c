#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "..\ClusterNodesScheduling\ClusterNodesScheduling.h"
#include "..\DynamicGroupHeadElection\DynamicGroupHeadElection.h"

int frequency = 1; // 涓嶈鐢╰ime

int main()
{
    init();
    printf("\n0s: start...\n");

    while (1)
    {
        ClusterNodesScheduling(node);   // 绨囩兢鎴樻崯璋冨害閲嶆瀯绠楁硶
        DynamicGroupHeadElection(&node); // 鍔ㄦ�佺兢棣栭�変妇
        if (frequency >= 3)
            break;
        sleep(1);
        printf("\n%ds: continue...\n", frequency);
        frequency++;
    }

    printf("3s: end...\n");
    return 0;
}
