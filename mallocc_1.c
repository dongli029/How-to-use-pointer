#include <stdio.h>
#include<stdlib.h>

int main(){
    int* p1;
    // 設定p1指標變數指向的記憶體位址為0
    p1 = NULL;
    // 因為上面設定p1指向的記憶體為null 所以印出來會是0;
    printf("p1原始指向的記憶體位址= %d\n", p1);
    // *p1 = 5; 因為上面設定p1指向的記憶體位址為0(可以想成不存在), 所以無法在這個不存在的位址放入值, 若要影印 會報錯!!
    // printf("p1指向的記憶體位址存放的值= %d\n", *p1);
    printf("p1原始本身記憶體位址= %d\n", &p1);
    char a[] = "==============\n";
    printf(a);
    //為p1指向位置配置記憶體
    p1 = (int*)malloc(sizeof(int));
    printf("為p1指向位置配置記憶體 => p1 = (int*)malloc(sizeof(int))\n");
    printf(a);
    // 設定上面指向的記憶體位智裡面存放整數10
    printf("p1指向的記憶體位址p1 = %d\np1本身的記憶體位址&p1 = %d\n",p1, &p1 );
    printf("p1指向的記憶體位址存放的值= %d", *p1);


}