#include "sendFrame.h"
#include <stdio.h>

MaintenanceFrameList maintenanceframelist;
ReplyFrameList replyframelist;

uint16_t var1 = 0xC025; // 缁存姢鏁版嵁鍙戦�佸抚甯уご淇℃伅
uint16_t var2 = 0xC0EE; // 缁存姢鏁版嵁鍙戦�佸抚甯у熬淇℃伅
uint16_t var3 = 0xC0CC; // 搴旂瓟鏁版嵁鍙戦�佸抚甯уご淇℃伅
uint16_t var4 = 0xC0DD; // 搴旂瓟鏁版嵁鍙戦�佸抚甯уご淇℃伅
uint16_t var5 = 0xC0EC; // 搴旂瓟鏁版嵁鍙戦�佸抚甯у熬淇℃伅

void sendFrame(){
    // 楂樺瓧鑺傚厛鍙戦�併�佷綆瀛楄妭鍚庡彂閫侊紝鑰冭檻瑕佷笉瑕佸弽杩囨潵瀛樺偍
    maintenance_frame();
    printf("maintenance_frame_data: %d ", maintenanceframelist.frame_header_information[0]); // 0x25
    printf("%d\n", maintenanceframelist.frame_header_information[1]);                      // 0xC0
    reply_frame();
    printf("reply_frame_data: %d ", replyframelist.frame_header_information[0]); // 0xCC
    printf("%d\n", replyframelist.frame_header_information[1]);                                          // 0xC0
}

void maintenance_frame(){
    maintenanceframelist.frame_header_information[0] = var1;
    maintenanceframelist.frame_header_information[1] = var1 >> 8;
    // 鍏朵粬鏁版嵁
    maintenanceframelist.frame_trailer_information[0] = var2;
    maintenanceframelist.frame_trailer_information[1] = var2 >> 8;
}

void reply_frame(){
    // CRC 鏍￠獙姝ｇ‘
    replyframelist.frame_header_information[0] = var3;
    replyframelist.frame_header_information[1] = var3 >> 8;
    // CRC 鏍￠獙閿欒
    // replyframelist.frame_header_information[0] = var4;
    // replyframelist.frame_header_information[1] = var4 >> 8;
    // 鍏朵粬鏁版嵁
    replyframelist.frame_trailer_information[0] = var5;
    replyframelist.frame_trailer_information[1] = var5 >> 8;
}

//int main(){
//    sendFrame();
//    return 0;
//}
