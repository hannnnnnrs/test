#include <stdio.h>
#include "BackupBroadcast.h"
#include "..\init\init.h"
#include "..\packet\sendPacket.h"
#include "..\packet\receivePacket.h"

void BackupBroadcast(int ID)
{
    node.role = 2;
    for (int i = 0; i < 8; i++)
    {
        sendPacket(node.record_member[i], ID, "test", 1); // 和消息内容无关
    }
}