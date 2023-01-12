#include "sortHead.h"
#include "..\init\init.h"
#include "..\packet\sendPacket.h"
#include "..\packet\receivePacket.h"
#include <stdio.h>

int serial[10]; // 簇首
int num[10];    // 对应簇首内节点数量

void sortHead(int ID) // 按照节点数量排序
{
    int flag = 0;
    for (int i = 0; i < 128; i++)
    {
        if (node.cluster_num[i] != 0)
        {
            serial[flag] = i;
            num[flag] = node.cluster_num[i];
            flag++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d: ", serial[i]);
        printf("%d\t", num[i]); //先输出要排序的数组元素
    }
    printf("\n");
    reserve(num, 10); //对数组元素排序
    for (int i = 9; i >= 0; i--)
    {
        printf("%d: ", serial[i]);
        printf("%d\t", num[i]); //输出排序后的数组元素
    }
    printf("\n");
}

void reserve(int x[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    { //一共n个元素，则需要比较n-1次
        for (j = 0; j < n - 1 - i; j++)
        { //每一个元素需要比较的次数
            if (x[i] < x[i + j + 1])
            {
                temp = x[i];
                x[i] = x[i + j + 1];
                x[i + j + 1] = temp;

                temp = serial[i];
                serial[i] = serial[i + j + 1];
                serial[i + j + 1] = temp;
            }
        }
    }
}