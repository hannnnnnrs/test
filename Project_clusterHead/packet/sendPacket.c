#include <stdio.h>
#include <string.h>
#include "sendPacket.h"
#include "..\init\init.h"
#include "..\OffNetRejoin\OffNetRejoin.h"
#include "receivePacket.h"

void sendPacket(int ID_1, int ID_2, char msg[], int type)
{
    printf("send packet: ");
    for (int i = 0; i < strlen(msg); i++)
    {
        printf("%c", msg[i]);
    }
    printf("\n");
    if (type == 0) // 叶子节点发送给备份簇首，获取备份簇首与簇首间的通信关系
    {
        for (int i = 0; i < 128; i++)
        {
            if (node.ID == ID_1)
            {
                if (matrix(node.head) != 0)
                {
                    receivePacket(ID_1, ID_2, "1", 0);
                }
                else
                {
                    receivePacket(ID_1, ID_2, "0", 0);
                }
            }
        }
    }
    else if (type == 1) // 备份簇首向簇首广播其成为新簇首
    {
        receivePacket(ID_1, ID_2, msg, type);
    }
    else if (type == 2) // 权重交换
    {
        receivePacket(ID_1, ID_2, "12.34", type); // test
    }
    else if (type == 3)
    {
        receivePacket(ID_1, ID_2, msg, type); 
    }
    else
    {
        printf("Other message types not involved.\n");
    }
}