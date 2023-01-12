#ifndef INIT_H
#define INIT_H

#include <stdio.h> //涓嶅０鏄庝細璀﹀憡锛屼笉浼氭姤閿�
#include <string.h>
#include <stdio.h>

#define valueSIZE 30
#define Length 10

struct Position
{
    double x;
    double y;
    double z;
};

struct Speed
{
    double x;
    double y;
    double z;
};

struct Record
{
    int dst_id;            // 鐩殑鑺傜偣ID
    char value[valueSIZE]; // 鍒扮洰鐨勮妭鐐笽D鐨勮矾寰�
    double cost;           // 璺緞寮�閿�
    int size;              // 璺緞璺虫暟
};

struct RoutingTable_net
{
    int src_id;                 // 婧愯妭鐐笽D
    struct Record data[Length]; // 婧愯妭鐐圭殑璺敱琛�
};

typedef struct node
{
    /* data */
    char name[5];
    int ID;                         // PK锛岃缃垚 1-128锛侊紒锛�
    int type;                       // 寮傛瀯 A=0, B=1, C=2
    struct Position position; // 60脳60
    struct Speed speed;       // 60脳60

    int role;                 // member=0; backup=1; head=2
    int head;                 // 鎵�鍦ㄧ皣绨囬
    int record_member[8];     // 鍦ㄦ垚涓哄浠界皣棣�/绨囬鍚庢湁鎰忎箟锛屽惁鍒欏叏缃负 0, 浠D璁板綍
    int record_head[10];      // 鍦ㄦ垚涓哄浠界兢棣�/缇ら鍚庢湁鎰忎箟锛屽惁鍒欏叏缃负 0锛屼互ID璁板綍
    int backup;               // 鎵�鍦ㄧ皣澶囦唤绨囬
    int group_head;           // 鎵�鍦ㄧ兢棣�
    int role_group;           // 鏄惁涓虹兢棣�/澶囦唤绨囬锛岀粨鍚坮ole纭畾
    int record_group_head[3]; // 鎴愪负缇ら鍚庢湁鎰忎箟锛岃褰� ABC 涓変釜缇ょ殑缇ら

    int adjacency_matrix[128];             // 璁板綍鑷繁鐨勯偦鎺ョ煩闃典俊鎭�
    int global_adjacency_matrix[128][128]; // 鎴愪负绨囬鍚庢眹鎬绘湰绨囧唴閭绘帴鐭╅樀淇℃伅锛屾垚涓虹兢棣栧悗姹囨�绘湰缇ゅ唴閭绘帴鐭╅樀淇℃伅

    double weight; // 渚濇嵁閭绘帴鐭╅樀鍜岃妭鐐归棿鐩稿璺濈
    double weight_matrix[128];

    int cluster_num[128]; // 鍦ㄦ垚涓哄浠界兢棣�/缇ら鍚庢湁鎰忎箟锛岀皣涓瓨鏀剧殑鑺傜偣鏁伴噺 ID-num

} NodeList;
// 鍦ㄥご鏂囦欢涓彧鑳藉缁撴瀯浣撶殑杩涜绫诲瀷瀹氫箟鍜屽疄浣撳０鏄�
// 瀵逛簬鐢ㄥ埌璇ョ粨鏋勪綋鐨� .c 瑕佽繘琛屽疄浣撳畾涔�

extern NodeList node;

void input(); // 瀵瑰嚱鏁扮殑澹版槑
void init();
void name();
void ID();
void Type();
void Position();
void Role();
void head_Record_Member();
void head_Record_Head();
void backup_Record_Member();
void show();
void proc();

#endif /* D544059F_2263_4F62_BA58_D156DB586A1F */
