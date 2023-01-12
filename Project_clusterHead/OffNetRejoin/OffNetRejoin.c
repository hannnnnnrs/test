#include <stdio.h>
#include "OffNetRejoin.h"
#include "Reconnect.h"
#include "..\init\init.h"
#include "..\packet\sendPacket.h"
#include "..\packet\receivePacket.h"

int head;
int backup;

void OffNetRejoin(NodeList node)
{
    for (int i = 0; i < 8; i++)
    {
        if (node.role != 0)
        {
            printf("Node-%d: Not a function for cluster head and backup.\n", node.ID);
        }
        else
        {
            head = node.head;
            backup = node.backup;
            if (matrix(head) != 0)
            {
                printf("Node-%d: no need to run the function.\n", node.ID);
            }
            else if (matrix(head) == 0 && matrix(backup) != 0)
            {
                printf("Node-%d: Discuss whether to join the backup cluster head.\n", node.ID);
                char msg[100] = "test";
                int type = 0;
                sendPacket(backup, node.ID, msg, type); // sendPacket 调用 receivePacket
            }
            else
            {
                printf("Node-%d: Re-access.\n", node.ID);
                Reconnect(node.ID);
            }
        }
    }
}

int matrix(int ID)
{
    return node.adjacency_matrix[ID - 1];
}
