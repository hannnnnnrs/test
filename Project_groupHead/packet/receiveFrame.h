#include <stdio.h>

// 维护数据接收帧
typedef struct maintenanceframe
{
    /* data */
    char frame_header_information[16];            // 帧头信息
    char data_identification[1];                  // 数据标识
    char destination_address[10];                 // 目的地址
    char source_address[10];                      // 源地址
    char type_of_control_package[3];              // 控制包种类
    char priority[2];                             // 优先级
    char reliable_transmission_identification[2]; // 可靠传输标识
    char checksum[16];                            // 校验和
    char valid_field_length[16];                  // 有效字段长度
    char retransmission_identification[1];        // 重传标识
    char standby[4];                              // 备用
    char frame_trailer_information[16];           // 帧尾信息
} MaintenanceFrameList;

// 业务数据接收帧
typedef struct businessframe
{
    /* data */
    char frame_header_information[2];             // 帧头信息
    char destination_address[16];                 // 目的地址
    char source_address[10];                      // 源地址
    char type_of_control_package[3];              // 控制包种类
    char data[320];                               // 数据
    char valid_field_length[16];                  // 有效字段长度
    char priority[2];                             // 优先级
    char reliable_transmission_identification[2]; // 可靠传输标识
    char checksum[16];                            // 校验和
    char retransmission_identification[1];        // 重传标识
    char standby[4];                              // 备用
    char frame_trailer_information[16];           // 帧尾信息
} BusinessFrameList;

// 应答数据接收帧
typedef struct replyframe
{
    /* data */
    char frame_header_information[16];     // 帧头信息
    char retransmission_identification[1]; // 重传标识
    char frame_trailer_information[16];    // 帧尾信息
} ReplyFrameList;

extern MaintenanceFrameList maintenanceframe;
extern BusinessFrameList businessframe;
extern ReplyFrameList replyframe;

int compare(char msg_1[], const char msg_2[], int num);
