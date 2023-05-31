#include <stdlib.h>
#include <stdio.h>


int abc();

int* assigMem(int** p){
    printf("assigMem函數內 %p\n",&p);
    p = (int *)malloc(sizeof(int));
    *p = 10;
    return p;
}

int main(){
    //建立一個指標變數p 指向null
    int* p = NULL;
    printf("一開始指標變數p自己的記憶體位置 = %a\n",&p); //指標變數p自己的記憶體位置
    int* a = assigMem(p);  // 建立指標變數a 
    printf("指標變數a自己的記憶體位置 = %a\n",&a); //印出指標變數a自己的記憶體位置
    printf("指標變數a指向的記憶體位置 = %a\n",a);
    printf("指標變數p後來自己的記憶體位置 = %p\n",&p);
    abc();
}


int abc(){
    printf("cpp plus!");
}
