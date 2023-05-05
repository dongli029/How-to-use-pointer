 #include <stdlib.h>
 #include<stdio.h>

//建立一個修改一維陣列值的函式, 把要修改陣列的地址當參數存進來
void setArrayValue(int* arr, int size, int value){
    for (int i = 0; i < size; i++ ){
        arr[i] = value;
    }
} 

//建立一個修改二維陣列值的函式, 把要修改陣列的地址當參數存進來
void set2dArrayValue(int(* arr)[3], int row, int col, int value){
    for(int i = 0; i < row; i++ ){
        for(int j = 0; j < col; j++){
            arr[i][j] = value;
        }
    }
} 

int main(){
 
    int vector [] = {1,3,5,7,9};
    printf("修改前:\n");
    for(int i = 0; i< sizeof(vector)/sizeof(int); i++){
        printf("%d ", vector[i]);
    }

    setArrayValue(vector, 5 , 45);

    printf("\n一維陣列被修改後=\n");
    //因為vectir陣列式被宣告在main函式中,故setArrayValue()函式結束後陣列沒有被釋放
    for(int i = 0; i< sizeof(vector)/sizeof(int); i++){
        printf("%d ", vector[i]);
    }
    printf("\n===========\n");

    int matrix[][3] = {{1,3,5},{2,4,6}};
    printf("二維陣 列matrix修改前:\n");
    for(int i = 0; i < sizeof(matrix)/sizeof(matrix[0]); i++ ){
        for(int j = 0; j < sizeof(matrix[0])/sizeof(matrix[0][0]);j++){
            printf("地址 = %d 值 = %d\n", *(matrix+i)+j, *(*(matrix+i)+j));
        }
    }

    set2dArrayValue(matrix,2, 3, 45);

    printf("\n二維陣列被修改後=\n");
    for(int i = 0; i < sizeof(matrix)/sizeof(matrix[0]); i++ ){
        for(int j = 0; j < sizeof(matrix[0])/sizeof(matrix[0][0]);j++){
            printf("地址 = %d 值 = %d\n", *(matrix+i)+j, *(*(matrix+i)+j));
        }
    }
}