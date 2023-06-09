#include<stdlib.h>
#include<stdio.h>

// int main(){
//     // p1指標變數指向null   
//     int * p1 = NULL;
//     //設定p2指向p1變數本身記憶體位址
//     int * p2 = &p1 ;
//     //幫p2指向的位置配置一個記憶體
//     p2 = (int *)malloc(sizeof(int));
//     // 實驗證明,int* p2 = &p1的方式就算後來配置記憶體給p2指向的位置 不代表配置記憶體給指標p1指向的記憶體位址
//     printf("p1 location = %d\, p2 location = %d",p1, p2);
// }

//指標變數只存取位址
// 如何修改? ==> 利用雙重指標取得p1本身的記憶體
int main(){
    // p1指標變數指向null   
    int * p1;
    // p1
    p1 = NULL;
    //設定p2雙重指標儲存p1本身記憶體位址
    int ** p2;
    // p2 指向p1本身記憶體位址
    p2 = &p1;
    //幫p2指向的位址(此時p2指向p1本身記憶體位址)配置一個記憶體
    //*p2打開一層 代表取出p1本身記憶體位址 **p2打開兩層(**p2 = *p1 = p1指向記憶體位址存放的值) 代表取出p1指向記憶體位址存放的值
    //以下程式碼代表幫p1指標函數本身位址(p2雙重指標變數指向的位置)配置記憶體 
    *p2 = (int *)malloc(sizeof(int));
    //p1指向記憶體位置內存放整數10;
    *p1 = 10;
    // 

    printf("p1本身記憶體位址&p1 = %d \, p2本身記憶體位址&p2 = %d\n", &p1, &p2);

    printf("p1本身記憶體位址&p1 = %d \, p2指向的記憶體位址(p2 = &p1) = %d\n", &p1, p2);

    printf("p1指向記憶體位址 = %d\, p2指向記憶體位址= %d\n", p1, p2 );

    printf("p1指向記憶體位置存取的值 = %d\, p2指向記憶體位址存取的值= %d\n", *p1, *p2 );

    printf("p2雙重指標變數存取的位址裡的指標變數p1指向的位址儲存的值 = %d\n", **p2);

    printf("number in p1指向記憶體位置 = %d \, number in p2指向的記憶體位址存放的指標變數p1所指向的記憶體位址 = %d\n",*p1, **p2);

    //觀念辯證: &p1代表印出p1自身記憶體位址, p1代表印出p1指向的記憶體位址
    // &p1 代表取出p1指向記憶體裡存放的值
    printf("p1指標函數的位址 = %d p1指標函數指向的位址 = %d",p1, &p1);

}