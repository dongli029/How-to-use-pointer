 #include <stdlib.h>
 #include<stdio.h>

//建立一個設定一維陣列值的函式, 把宣告陣列的地址當參數存進來
void setArrayValue(int* arr, int size, int value){
    for (int i = 0; i < size; i++ ){
        arr[i] = value;
    }
} 

//建立一個設定二維陣列值的函式, 把陣列的地址當參數存進來
// void set2dArrayValue(int(* arr)[3], int row, int col, int value){
//     for(int i = 0; i < row; i++ ){
//         for(int j = 0; j < col; j++){
//             arr[i][j] = value;
//         }
//     }
// } 

int main(){
    //建立一個陣列指標並配置記憶體
    int* vector = (int *)malloc( sizeof(int) * 5 );

    setArrayValue(vector, 5 , 45);

    printf("\n一維陣列被附值後=\n");
    //因為vectir陣列式被宣告在main函式中,故setArrayValue()函式結束後陣列沒有被釋放
    for(int i = 0; i< 5; i++){
        printf("%d ", vector[i]);
    }
    printf("\n===========\n");
    
    printf("\n==\n");
    int row = 2, col = 3;

    int** vector2d;
    //因為vector2d指向的也是一塊包含兩個地址的記憶體 故裡面要配置int *型態
    vector2d = (int**)malloc(sizeof(int *)*row);
    // vector2d第一列記憶體(*(vector2d+0))指向的記憶體裡又包含col個記憶體
    *(vector2d+0) = (int*)malloc(sizeof(int)*col);
    // vector2d第二列記憶體 vector2d[1] == (*(vector2d+1))指向的記憶體裡又包含col個記憶體
    vector2d[1] = (int*)malloc(sizeof(int)*col);

    // printf("\n二維陣列被修改後=\n");
    // for(int i = 0; i < row; i++ ){
    //     for(int j = 0; j < col;j++){
    //         printf("地址 = %d 值 = %d\n", vector2d[i], *(*(vector2d+i)+j));
    //     }
    // }
}