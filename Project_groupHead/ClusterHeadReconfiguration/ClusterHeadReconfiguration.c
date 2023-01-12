#include <stdio.h>
#include "ClusterHeadReconfiguration.h"
#include "BackupBroadcast.h"
#include "..\init\init.h"
#include "..\packet\sendPacket.h"
#include "..\packet\receivePacket.h"
#include "..\OffNetRejoin\OffNetRejoin.h"
#include "..\OffNetRejoin\Reconnect.h"

int flag = 0;
void ClusterHeadChange(int ID);

void ClusterHeadReconfiguration(NodeList node)
{
        if (node.role == 1)
        {
            if (matrix(node.head) != 1)
            {
                ClusterHeadChange(node.ID);
            } else printf("Continue to be the backup cluster head.\n");
        }
}

void ClusterHeadChange(int ID)
{
    // int num=sizeof(node[ID-1].record_member)/sizeof(node[ID-1].record_member[0]); // 涓嶈兘鑾峰彇浼犻�掓暟缁勭殑闀垮害
    for (int i = 0; i < 8; i++)
    {
        if (node.record_member[i] != node.head && matrix(node.record_member[i]) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Backup cluster head becomes new cluster head.\n");
        BackupBroadcast(ID);
    }
    else
    {
        node.role = 0;
        printf("Re-access.\n");
        Reconnect(node);
    }
}
