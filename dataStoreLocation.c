// 資料存儲位置概念

#include <stdlib.h>
#include<stdio.h>

//在此函式製造的陣列 因為是創造在stack區域, 在此函式結束執行後會自動被釋放消失,造成segmentation lose 
// int* allocateArray(int size, int value){
//     int arr [5];
//     for(int i =0; i <size; i++){
//         arr[i] = value;
//     }
//     return arr;
// }

int* allocateArray(int size, int value){
    // 加上static前綴 則創造的arr陣列被放到全域靜態區域, 故函數執行完畢後仍會存在在static區域
    static int arr [5];
    for(int i =0; i <size; i++){
        arr[i] = value;
    }
    return arr;
}

int main(){
    int* mainArr = allocateArray(5,66);
    for(int i =0; i < 5; i++){
        printf("%d\n", mainArr[i]);
    }
}