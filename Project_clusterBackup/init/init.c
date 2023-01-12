#define _CRT_SECURE_NO_WARNINGS

#include "init.h"
#include "..\location\readPosition.h"
//#include "..\packet\sendPacket.h"
//#include "..\packet\receivePacket.h"

NodeList node; // 鍦�.c 涓缁撴瀯浣撶殑瀹氫箟

char configuration;

void input()
{
    printf("Use default configuration:[y/n] ");
    scanf(" %c", &configuration);
    if (configuration == 'y')
    {
        init();
    }
    else
        printf("No configuration.\n");
}

void init()
{
    proc();
    name();
    ID();
    Type();
    Position();
    Role();
    head_Record_Member();
    backup_Record_Member();
    show();
}

void name()
{
    node.name[0] = 'A';
    node.name[1] = '0';
    node.name[2] = '2';
    printf("Initialize Name Complete.\n");
}

void ID()
{
    node.ID = 2;
    printf("Initialize ID Complete.\n");
}

void Type()
{
    node.type = 0; // A=0
    printf("Initialize Type Complete.\n");
}

void Position()
{
    readPosition(node.ID / 16 + 1, node.ID % 8, 1);
    printf("Initialize Position Complete.\n");
}

void Role()
{
    node.role = 1; // member
    printf("Initialize Role Complete.\n");
}

void head_Record_Member()
{
    for (int j = 0; j < 8; j++)
    {
        // sendPacket(i, j + i, "cluster", 0);
        node.record_member[j] = 1 + j;
    }
    printf("Initialize HEAD-Record Member Complete.\n");
}

void backup_Record_Member()
{
    node.backup = 2;     // 鎵�鍦ㄧ皣澶囦唤绨囬
    node.group_head = 9; // 鎵�鍦ㄧ兢棣�
    node.role_group = 0; // 鏄惁涓虹兢棣�/澶囦唤绨囬锛岀粨鍚坮ole纭畾

    for (int i = 0; i < sizeof(node.adjacency_matrix) / sizeof(node.adjacency_matrix[0]); i++)
    {
        node.adjacency_matrix[i] = 1;
    }
    // double weight; // 渚濇嵁閭绘帴鐭╅樀鍜岃妭鐐归棿鐩稿璺濈
    // double weight_matrix[128];

    printf("Initialize BACKUP-Record Member Complete.\n");
}

void show()
{
    printf("------------------------------------\n");
    printf("KEY              VALUE\n");
    printf("name             ");
    for (int i = 0; i < 5; i++)
    {
        printf("%c", node.name[i]);
    }
    printf("\n");
    printf("ID               %d\n", node.ID);
    printf("type             %d\n", node.type);
    printf("position         %-10f  %-10f  %-10f\n", node.position.x, node.position.y, node.position.z);
    printf("speed            %-10f  %-10f  %-10f\n", node.speed.x, node.speed.y, node.speed.z);
    printf("role             %d\n", node.role);
    printf("head             %d\n", node.head);
    printf("record member    ");
    for (int i = 0; i < sizeof(node.record_member) / sizeof(node.record_member[0]); i++)
    {
        printf("%d ", node.record_member[i]);
    }
    printf("\n");
    printf("backup           %d\n", node.backup);
    printf("group head       %d\n", node.group_head);
    printf("role group       %d\n", node.role_group);

    printf("adjacency matrix ");
    for (int i = 0; i < sizeof(node.adjacency_matrix) / sizeof(node.adjacency_matrix[0]); i++)
    {
        printf("%d ", node.adjacency_matrix[i]);
    }
    printf("\n");
    // double weight; // 渚濇嵁閭绘帴鐭╅樀鍜岃妭鐐归棿鐩稿璺濈
    // double weight_matrix[128];
    printf("------------------------------------");
}

void proc()
{
    char buf[103];
    memset(buf, ' ', sizeof(buf));
    buf[0] = '[';
    buf[101] = ']';
    buf[102] = '\0';
    int i = 0;
    while (i <= 100)
    {
        buf[i] = '=';
        printf("%s [%d%%]\r", buf, i);
        fflush(stdout); // 鍒锋柊缂撳啿鍖�
        sleep(0.01);
        i++;
    }

    printf("\n");
}
