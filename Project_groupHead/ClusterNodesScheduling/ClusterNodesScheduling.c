#include <stdio.h>
#include "ClusterNodesScheduling.h"
#include "..\packet\sendPacket.h"
#include "..\packet\receivePacket.h"
#include "..\OffNetRejoin\OffNetRejoin.h"

int min = 6; // 鏈�灏忓畬鎴愪换鍔¤妭鐐规暟閲�

void ClusterNodesScheduling(NodeList node)
{
    if (node.role == 2)
    {
        int num = 0;
        for (int j = 0; j < 8; j++)
        {
            if (matrix(node.record_member[j]) == 1)
            {
                num++;
            }
        }
        char total = num + '0';
        if (num <= 6)
        {
            // sendPacket(node.ID, node.group_head, &total, 3); // 绨囬鐜版湁鑺傜偣鏁伴噺
            printf("num = %d", num);
        }
        else
        {
            printf("The cluster does not need to execute the scheduling function.\n");
            // sendPacket(node.ID, node.group_head, &total, 3);
        }
    }
}
