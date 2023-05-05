 #include <stdlib.h>
 #include<stdio.h>

 int main(){
    // 陣列名稱vector是此陣列第0項的地址 => vector = &vector[0]
    // 證明: &vector[1] = &(*(vector+1))==> &*相消 ==> &vector[1] = vector+1

    int vector[] = {1,3,5,7,9};
    //u印出值
    printf("%d %d %d %d %d\n",vector[0],vector[1],vector[2],vector[3],vector[4]);
    //印出地址第一種方式
    printf("%d %d %d %d %d\n",&vector[0],&vector[1],&vector[2],&vector[3],&vector[4]);
    //印出地址第二種方式
    printf("%d %d %d %d %d\n",vector+0,vector+1,vector+2,vector+3,vector+4);
    //證明 陣列名稱vector是vector[0]的地址
    printf("vector[0]的十進位地址 = %d vector地址 = %d\n",&vector[0], vector);
    //建立一個陣列指標指向地址vector
    int* vPtr = vector;

    printf("vPtr指標變數自己的地址 = %d vPtr指向地址 = %d\n",&vPtr, vPtr);
    printf("vPtr指向地址 = %d vPtr指向地址所儲存的值 = %d\n",vPtr, *vPtr);
    //請用指標vPtr印出陣列vector的第三個位置(vector[2])的地址與值
    printf("vector[2]地址 = %d vector[2]地址所儲存的值 = %d\n",vPtr+2, *(vPtr+2));

    //用迴圈印出vPtr指向陣列裡函的值與地址
    for(int i = 0; i < sizeof(vector)/sizeof(vPtr[0]); i++ ){
        printf("地址 = %d 值 = %d\n", vPtr+i, vPtr[i]);
    }

 }
 

 