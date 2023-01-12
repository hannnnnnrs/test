#include "receiveFrame.h"
#include <stdio.h>
#include <string.h>

const char frame_header_information_1[16] = "1100000000100010";  // C022
const char frame_trailer_information_1[16] = "1100000011101110"; // C0EE
const char frame_header_information_2[16] = "1100000000100001";  // C021
const char frame_trailer_information_2[16] = "1100000011101101"; // C0ED
const char frame_header_information_3[16] = "1100000011001100";  // C0CC
const char frame_trailer_information_3[16] = "1100000011101100"; // C0EC
const char frame_header_information_4[16] = "1100000011011101";  // C0DD

MaintenanceFrameList maintenanceframe;
BusinessFrameList businessframe;
ReplyFrameList replyframe;

void bytesWitheRouter(char msg[])
{
    char frame_header_information[16];
//    char frame_trailer_information[16];
    for (int i = 0; i < 16; i++)
    {
        frame_header_information[i] = msg[i];
    }
    if (compare(frame_header_information, frame_header_information_1, 16) == 0) // 娌℃硶鐢╯trcmp
    {
        printf("This is a maintenance data receiving frame.\n");
        for (int i = 0; i < 16; i++)
        {
            maintenanceframe.frame_header_information[i] = msg[i];
            maintenanceframe.frame_trailer_information[i] = msg[81 + i];
        }

        maintenanceframe.data_identification[0] = msg[16];
        if (msg[16] == '0')
        { // 鍥哄畾浣�0
            printf("No data.\n");
        }

        printf("Destination address: ");
        for (int i = 0; i < 5; i++)
        {
            maintenanceframe.destination_address[i] = msg[17 + i];
            printf("%c", maintenanceframe.destination_address[i]);
        }
        printf("-");
        for (int i = 0; i < 5; i++)
        {
            maintenanceframe.destination_address[5 + i] = msg[22 + i];
            printf("%c", maintenanceframe.destination_address[5 + i]);
        }
        printf("\n");

        printf("Source address: ");
        for (int i = 0; i < 5; i++)
        {
            maintenanceframe.source_address[i] = msg[27 + i];
            printf("%c", maintenanceframe.source_address[i]);
        }
        printf("-");
        for (int i = 0; i < 5; i++)
        {
            maintenanceframe.source_address[5 + i] = msg[32 + i];
            printf("%c", maintenanceframe.source_address[5 + i]);
        }
        printf("\n");

        for (int i = 0; i < 3; i++)
        {
            maintenanceframe.type_of_control_package[i] = msg[37 + i];
        }

        maintenanceframe.priority[0] = msg[40];
        maintenanceframe.priority[1] = msg[41];

        maintenanceframe.reliable_transmission_identification[0] = msg[42];
        maintenanceframe.reliable_transmission_identification[1] = msg[43];

        printf("checksum: ");
        for (int i = 0; i < 16; i++)
        {
            maintenanceframe.checksum[i] = msg[44 + i];
            printf("%c", maintenanceframe.checksum[i]);
        }
        printf("\n");

        printf("reliable transmission identification: ");
        for (int i = 0; i < 16; i++)
        {
            maintenanceframe.reliable_transmission_identification[i] = msg[60 + i];
            printf("%c", maintenanceframe.reliable_transmission_identification[i]);
        }
        printf("\n");

        maintenanceframe.retransmission_identification[0] = msg[76];

        for (int i = 0; i < 4; i++)
        {
            maintenanceframe.standby[i] = msg[77 + i];
            printf("%c", maintenanceframe.standby[i]);
        }
    }
    else if (compare(frame_header_information, frame_header_information_2, 16) == 0)
    {
        printf("This is a business data receiving frame.\n");
        for (int i = 0; i < 16; i++)
        {
            businessframe.frame_header_information[i] = msg[i];
            businessframe.frame_trailer_information[i] = msg[401 + i];
        }

        printf("Destination address: ");
        for (int i = 0; i < 5; i++)
        {
            businessframe.destination_address[i] = msg[17 + i];
            printf("%c", businessframe.destination_address[i]);
        }
        printf("-");
        for (int i = 0; i < 5; i++)
        {
            businessframe.destination_address[5 + i] = msg[22 + i];
            printf("%c", businessframe.destination_address[5 + i]);
        }
        printf("\n");

        printf("Source address: ");
        for (int i = 0; i < 5; i++)
        {
            businessframe.source_address[i] = msg[27 + i];
            printf("%c", businessframe.source_address[i]);
        }
        printf("-");
        for (int i = 0; i < 5; i++)
        {
            businessframe.source_address[5 + i] = msg[32 + i];
            printf("%c", businessframe.source_address[5 + i]);
        }
        printf("\n");

        for (int i = 0; i < 3; i++)
        {
            businessframe.type_of_control_package[i] = msg[37 + i];
        }

        for (int i = 0; i < 320; i++)
        {
            businessframe.data[i] = msg[40 + i];
        }

        for (int i = 0; i < 16; i++)
        {
            businessframe.valid_field_length[i] = msg[360 + i];
        }

        businessframe.priority[0] = msg[376];
        businessframe.priority[1] = msg[377];

        businessframe.reliable_transmission_identification[0] = msg[378];
        businessframe.reliable_transmission_identification[1] = msg[379];

        printf("checksum: ");
        for (int i = 0; i < 16; i++)
        {
            businessframe.checksum[i] = msg[380 + i];
            printf("%c", businessframe.checksum[i]);
        }
        printf("\n");

        businessframe.retransmission_identification[0] = msg[396];

        for (int i = 0; i < 4; i++)
        {
            businessframe.standby[i] = msg[397 + i];
            printf("%c", businessframe.standby[i]);
        }
    }
    else if (compare(frame_header_information, frame_header_information_3, 16) == 0)
    {
        printf("The route layer frame message is received and CRC verification is correct.\n");
        for (int i = 0; i < 16; i++)
        {
            replyframe.frame_header_information[i] = msg[i];
            replyframe.frame_trailer_information[i] = msg[17 + i];
        }

        replyframe.retransmission_identification[0] = msg[16];
    }
    else if (compare(frame_header_information, frame_header_information_4, 16) == 0)
    {
        printf("The route layer frame message is received, but CRC verification error occurs.\n");
        for (int i = 0; i < 16; i++)
        {
            replyframe.frame_header_information[i] = msg[i];
            replyframe.frame_trailer_information[i] = msg[17 + i];
        }

        replyframe.retransmission_identification[0] = msg[16];
    }
    else
    {
        printf("Other frames.\n");
    }
}

int compare(char msg_1[], const char msg_2[], int num)
{
    int flag = 0;
    for (int i = 0; i < num; i++)
    {
        if (msg_1[i] != msg_2[i])
            flag = 1;
    }
    return flag;
}
//int main()
//{ // test
//    char msg[] = "1100000000100010000011001110001100010000100111111111111111110011001100110010000001100000011101110"; // 缁存姢鏁版嵁鎺ユ敹甯�
//    // char msg[] = "1100000000100001000011001110001100010000100111111111111111110011001100110010000001100000011101101"; // 涓氬姟鏁版嵁鎺ユ敹甯�(320涓暟鎹�)
//    // char msg[] = "11000000110011001"; // 搴旂瓟鏁版嵁鎺ユ敹甯�
//    // char msg[] = "11000000110111010"; // 搴旂瓟鏁版嵁鎺ユ敹甯�
//    bytesWitheRouter(msg);
//    return 0;
//}
