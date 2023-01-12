#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../init/init.h"

int readPosition(int i, int j, int time)
{
    char path[100];
    char s1[100];
    int frequency = 0;
    memset(path, 0, 100);
    memset(s1, 0, 100);
    sprintf(s1, "%d", i);
    strcpy(path, "..\\location\\128\\");
    strcat(path, s1);
    strcat(path, "\\");
    strcat(path, itoa(j, s1, 10));
    strcat(path, ".txt");

    // printf("ID:  node Position at second is:\n");

    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        printf("Fail to open file!\n");
        return 0;
    }
    // printf("ID:  node Position at second is:\n");

    while (frequency < time) // 鏁版嵁閲忎笉澶�
    {
        float time, x, y;
        fscanf(file, "%f ", &time);
        fscanf(file, "%f ", &x);
        fscanf(file, "%f ", &y);
        node.position.x = x;
        node.position.y = y;
        node.position.z = 0;
        // printf("ID: %d node Position at %d second is:\n", (i - 1) * 8 + j, (int)time);
        // printf("%f ", node[(i - 1) * 8 + j - 1].position[frequency].x);
        // printf("%f ", node[(i - 1) * 8 + j - 1].position[frequency].y);
        // printf("%f\n", node[(i - 1) * 8 + j - 1].position[frequency].z);
        frequency++;
    }
    fclose(file);
    return 1;
}
