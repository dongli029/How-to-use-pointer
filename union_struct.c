#include<stdlib.h>
#include<stdio.h>


int main(){

    typedef union control{   // 因為union是共用記憶體位址, 可以利用 union + struct 技巧來控制內部特定位置的byte ==> 通常用在韌體控制
        int total;    // 4 byte
        struct{
            char light_big;   // 1 byte
            char light_small; // 1 byte
            char sound_big;   // 1 byte
            char sound_small; // 1 byte
        };     
    }TV;

    TV sony;
    sony.light_big = 10;
    sony.light_small = 15;
    sony.sound_big = 5;
    sony.sound_small = 116; 

    printf("%d\n", sony.total);

    printf("%d\n",sony.sound_big);

    sony.sound_big = sony.sound_big << 1;  //單獨控制 sony.sound_big這一個byte(<<1 == *2) 

    printf("%d\n",sony.sound_big);

}