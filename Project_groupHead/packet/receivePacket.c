#include <stdio.h>
#include <string.h>
#include "receivePacket.h"
#include "..\init\init.h"
#include "..\OffNetRejoin\Reconnect.h"
#include "..\ClusterNodesScheduling\sortHead.h"
#include "changeType.h"

void receivePacket(int ID_1, int ID_2, char msg[], int type)
{
    printf("receive packet: ");
    for (int i = 0; i < strlen(msg); i++)
    {
        printf("%c", msg[i]);
    }
    printf("\n");
    if (type == 0) // 鍙跺瓙鑺傜偣鍙戦�佺粰澶囦唤绨囬锛岃幏鍙栧浠界皣棣栦笌绨囬闂寸殑閫氫俊鍏崇郴
    {
        if (strcmp(msg, "0") != 0)
        {
            printf("Re-access.\n");
            Reconnect(node);
        }
        else
        {
            printf("Wait for the backup cluster node to recreate the network.\n");
        }
    }
    else if (type == 1) // 澶囦唤绨囬骞挎挱鎴愪负鏂扮皣棣�
    {
    }
    else if (type == 2) // 鍏ョ綉鏉冮噸浜ゆ崲
    {
        node.weight_matrix[ID_2 - 1] = changeType(msg);
    }
    else if (type == 3)
    {
        int num = msg[0] - '0';
        node.cluster_num[ID_1 - 1] = num;
        // sortHead(ID_2);
    }
    else
    {
        printf("Other message types not involved.\n");
    }
}
