#include <stdio.h>
#include "Reconnect.h"
#include "..\packet\sendPacket.h"
#include "..\packet\receivePacket.h"

void Reconnect(int ID)
{
    if (node.type == 0)
    {
        for (int i = 0; i < 24; i++)
        {
            sendPacket(ID,i+1,"A",2);
        }
    } else if(node.type == 1){
        for (int i = 24; i < 48; i++)
        {
            sendPacket(ID,i+1,"B",2);
        }
    } else {
        for (int i = 48; i < 128; i++)
        {
            sendPacket(ID,i+1,"C",2);
        }
    }
}