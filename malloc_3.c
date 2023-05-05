#include <stdlib.h>
#include <stdio.h>

int* assignMem(int* a){
    //malloc分配的記憶體是在heap區域, 需要被free後才會被釋放
    a = (int*)malloc(sizeof(int));
    *a = 10;
    printf("函數內assignment => a指向記憶體位址 = %d\n", a);
    return a;
}

// 丟進來的特定指標變數要先在main中宣告, 但丟進來後在函數內配置指向的記憶體 在跳出此函式後會丟失, 和在main函式內定義的指向記憶體位置不同
void assignMem2(int* n){
    //malloc分配的記憶體是在heap區域, 需要被free後才會被釋放
    n = (int*)malloc(sizeof(int));
    printf("assignMem2函數內接到傳進來的指標變數本身位置 = %d\n", &n);
    *n = 10;
    printf("assignMem2函數內傳進來的指標變數 => 指向記憶體位址 = %d\n", n);
}

//傳進來指向指標參數記憶體位址的雙重指標參數d(傳進來的是一個特定記憶體位址的位址)
void assignMem3(int** d){
    //malloc分配的記憶體是在heap區域, 需要被free後才會被釋放
    //打開一次 給予此雙重指標參數內儲存位址內儲存的地址所指向的的位址分配記憶體位置 
    *d = (int*)malloc(sizeof(int));
    //把10放進去此位置
    **d = 10;
    printf("assignMem3函數內存放值的記憶體位址 = %d\n", *d);
    printf("assignMem3函數內存放的值 = %d\n", **d);
}

// 設計一個釋放記憶體的函式
//傳入存放指標參數位址的雙重指標參數p 
void saferFree(int** p){
    // 如果此雙重指標參數p指向的參數位址指向的記憶體位址不為null 且其本身指向的位址也不為null
    if(*p != NULL && p != NULL){
        //將此雙重指標參數p指向的參數位址指向的記憶體釋放
        free(*p);
        //此雙重指標參數p指向的參數位址指向null
        *p = NULL;
    }
}

int main(){
    int* p = NULL;
    printf("p指向null的記憶體位址 = %d\n", p);
    // 重新指定指標變數p指向的記憶體位址
    p = assignMem(p);
    printf("after assignment => p指向記憶體位址 = %d\n", p);
    printf("===========\n");
    int* c;
    printf("main函數內宣告指標變數c本身位置 = %d\n", &c);
    printf("main函數內宣告的指標變數c指向位址 = %d\n",c);
    assignMem2(c);
    printf("main函數內宣告的指標變數c在被丟進去assignMem2(c)處理後本身的位址 = %d\n",&c);
    printf("main函數內宣告的指標變數c在被丟進去assignMem2(c)處理後指向的位址 = %d\n",c);

    printf("===========\n");
    //宣告一個指標變數e
    int* e;
    printf("宣告一個指標變數e, 此e指向的記憶體位址 = %d\n", e);
    //把指標參數e本身的位址當作參數傳進去函式assignMem3(&e)
    assignMem3(&e);

    printf("指標變數e經assignMem3(&e)分配記憶體後的記憶體位址= %d\n", e);
    printf("指標變數e經assignMem3(&e)後e存放的值= %d\n", *e);

    printf("===========\n");
    // 釋放記憶體後將指標參數e指向null
    saferFree(&e);
    printf("釋放指標參數e指向的記憶體後 e指向 = %d\n", e);

}