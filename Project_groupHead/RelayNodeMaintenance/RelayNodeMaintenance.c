#include "RelayNodeMaintenance.h"
#include "..\offNetRejoin\OffNetRejoin.h"
#include "..\ClusterNodesScheduling\sortHead.h"
#include <stdio.h>

void RelayNodeMaintenance(NodeList node)
{
    int flag_A = 0;
    int flag_B = 0;
    int flag_C = 0;
    if (node.role == 2 && node.role_group == 1)
    {
        if (node.type == 0)
        {
            flag_A = 1;
            for (int i = 24; i < 48; i++) // 缇ら A 鍙互涓庡紓鏋勮妭鐐� B 涔嬩竴鐩存帴閫氫俊
            {
                if (matrix(i + 1) == 1)
                {
                    flag_B = 1;
                    printf("direct connect with Group-B.\n");
                    break;
                }
            }
            if (flag_B == 0 && cluster_connect(node.ID, 1) == 1) // 瀛樺湪缇ら A 鐨勭皣棣栬妭鐐瑰彲浠ヤ笌寮傛瀯鑺傜偣 B 涔嬩竴鐩存帴閫氫俊
            {
                flag_B = 1;
                printf("indirect connect with Group-B.\n");
            }
            for (int i = 48; i < 128; i++) // 缇ら A 鍙互涓庡紓鏋勮妭鐐� C 涔嬩竴鐩存帴閫氫俊
            {
                if (matrix(i + 1) == 1)
                {
                    flag_C = 1;
                    printf("direct connect with Group-C.\n");
                    break;
                }
            }
            if (flag_C == 0 && cluster_connect(node.ID, 2) == 1) // 瀛樺湪缇ら A 鐨勭皣棣栬妭鐐瑰彲浠ヤ笌寮傛瀯鑺傜偣 C 涔嬩竴鐩存帴閫氫俊
            {
                flag_C = 1;
                printf("indirect connect with Group-C.\n");
            }
            maintenance('A', flag_A, flag_B, flag_C, node.record_group_head[0], node.record_group_head[1], node.record_group_head[2]);
        }
        else if (node.type == 1)
        {
            flag_B = 1;
            for (int i = 0; i < 24; i++)
            {
                if (matrix(i + 1) == 1)
                {
                    flag_A = 1;
                    printf("direct connect with Group-A.\n");
                    break;
                }
            }
            if (flag_A == 0 && cluster_connect(node.ID, 0) == 1) // 瀛樺湪缇ら B 鐨勭皣棣栬妭鐐瑰彲浠ヤ笌寮傛瀯鑺傜偣 A 涔嬩竴鐩存帴閫氫俊
            {
                flag_A = 1;
                printf("indirect connect with Group-A.\n");
            }
            for (int i = 48; i < 128; i++)
            {
                if (matrix(i + 1) == 1)
                {
                    flag_C = 1;
                    printf("direct connect with Group-C.\n");
                    break;
                }
            }
            if (flag_C == 0 && cluster_connect(node.ID, 2) == 1) // 瀛樺湪缇ら B 鐨勭皣棣栬妭鐐瑰彲浠ヤ笌寮傛瀯鑺傜偣 C 涔嬩竴鐩存帴閫氫俊
            {
                flag_C = 1;
                printf("indirect connect with Group-C.\n");
            }
            maintenance('B', flag_A, flag_B, flag_C, node.record_group_head[0], node.record_group_head[1], node.record_group_head[2]);
        }
        else
        {
            flag_C = 1;
            for (int i = 0; i < 24; i++)
            {
                if (matrix(i + 1) == 1)
                {
                    flag_A = 1;
                    printf("direct connect with Group-A.\n");
                    break;
                }
            }
            if (flag_A == 0 && cluster_connect(node.ID, 0) == 1) // 瀛樺湪缇ら B 鐨勭皣棣栬妭鐐瑰彲浠ヤ笌寮傛瀯鑺傜偣 C 涔嬩竴鐩存帴閫氫俊
            {
                flag_A = 1;
                printf("indirect connect with Group-A.\n");
            }
            for (int i = 24; i < 48; i++)
            {
                if (matrix(i + 1) == 1)
                {
                    flag_B = 1;
                    printf("direct connect with Group-B.\n");
                    break;
                }
            }
            if (flag_B == 0 && cluster_connect(node.ID, 1) == 1) // 瀛樺湪缇ら B 鐨勭皣棣栬妭鐐瑰彲浠ヤ笌寮傛瀯鑺傜偣 C 涔嬩竴鐩存帴閫氫俊
            {
                flag_B = 1;
                printf("indirect connect with Group-B.\n");
            }
            maintenance('C', flag_A, flag_B, flag_C, node.record_group_head[0], node.record_group_head[1], node.record_group_head[2]);
        }
    }
}

void maintenance(char group, int group_1, int group_2, int group_3, int ID_1, int ID_2, int ID_3)
{
    if (group_1 == 0)
    {
        printf("group-%c can not connect with group-A.\n", group);
        sortHead(ID_1);
    }
    if (group_2 == 0)
    {
        printf("group-%c can not connect with group-B.\n", group);
        sortHead(ID_2);
    }
    if (group_3 == 0)
    {
        printf("group-%c can not connect with group-C.\n", group);
        sortHead(ID_3);
    }
}

int cluster_connect(int ID, int type)
{
    for (int i = 0; i < 10; i++)
    {
        if (node.record_head[i] == 0)
            break;
        else
        {
            sendPacket(node.ID, node.record_head[i], "", type);
            return 1;
        }
    }
    return 0;
}
