#include <stdio.h>
#include "DynamicGroupHeadElection.h"
#include "../packet/sendPacket.h"
#include "../init/init.h"
#include "../OffNetRejoin/OffNetRejoin.h"

void DynamicGroupHeadElection(NodeList *node)
{
    if (node->role_group == 1 || matrix(node->group_head) == 1)
    {
        printf("No need to run the function.\n");
    }
    else
    {
        int average_hops[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}; // 3 + 3 + 10 = 16
        for (int i = 0; i < 16; i++)                                                                           // A + B
        {
            sendPacket(node->ID, node->record_head[i], "", 4); // 閫氳繃璺敱妯″潡鑾峰彇鍒板叾浠栧紓鏋勭皣棣栫殑鏈�鐭烦鏁�
            average_hops[i] = 2;                               // 閫氳繃璺敱妯″潡鑾峰彇鍙傛暟
        }
        int total = 0;
        for (int i = 0; i < 16; i++) // 鍒版墍鏈夌皣棣栫殑璺虫暟
        {
            // printf("%d ", average_hops[i]);
            total += average_hops[i];
        }
        // printf("\n");
        // 璁＄畻鍒版墍鏈夌皣棣栫殑鎬绘潈閲�
        printf("total = %d\n", total);
        int nums[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
        if (node->type == 0)
        {
            for (int i = 0; i < 3; i++)
            {
                sendPacket(node->ID, node->record_head[i], "", 4); // 鍚屾瀯涔嬮棿浜ゆ崲鎬绘潈閲嶏紝閫変妇鍏ㄥ眬璺虫暟鏈�灏忕殑绨囬涓虹兢棣�
                nums[i] = total;                                   // 浠庤矾鐢辨ā鍧楄幏鍙栧叾浠栬妭鐐规�绘潈閲�
            }
        }
        else if (node->type == 1)
        {
            for (int i = 3; i < 6; i++)
            {
                sendPacket(node->ID, node->record_head[i], "", 4); // 鍚屾瀯涔嬮棿浜ゆ崲鎬绘潈閲嶏紝閫変妇鍏ㄥ眬璺虫暟鏈�灏忕殑绨囬涓虹兢棣�
                nums[i - 3] = total;                               // 浠庤矾鐢辨ā鍧楄幏鍙栧叾浠栬妭鐐规�绘潈閲�
            }
        }
        else
        {
            for (int i = 6; i < 16; i++)
            {
                sendPacket(node->ID, node->record_head[i], "", 4); // 鍚屾瀯涔嬮棿浜ゆ崲鎬绘潈閲嶏紝閫変妇鍏ㄥ眬璺虫暟鏈�灏忕殑绨囬涓虹兢棣�
                nums[i - 6] = total;                               // 浠庤矾鐢辨ā鍧楄幏鍙栧叾浠栬妭鐐规�绘潈閲�
            }
        }
        int min = 100;
        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            if (nums[i] == 100)
                break;
            else
            {
                if (nums[i] < min)
                {
                    min = nums[i];
                    index = i;
                    printf("min = %d, index = %d\n", min, index);
                }
            }
        }
        if (node->ID == node->record_head[index])
        {
            node->role_group = 1;                           // 绨囬 + 缇ゅ唴瑙掕壊 = 缇ら
            node->record_group_head[node->type] = node->ID; // 灏嗕笁涓兢棣栦箣涓�璁剧疆涓鸿嚜宸� ID
            node->adjacency_matrix[node->group_head - 1] = 1;
            for (int i = 0; i < 16; i++)
            {
                sendPacket(node->ID, node->record_head[i], "test", 4); // 鍚戞墍鏈夌皣棣栧箍鎾嚜宸辨垚涓虹兢棣�
            }
            printf("Become a new group leader.\n");
        }
        else
        {
            printf("Don't become the group leader.\n");
        }
    }
}
