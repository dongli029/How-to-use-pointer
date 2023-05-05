 #include <stdlib.h>
 #include<stdio.h>

//建立一個設定一維陣列值的函式, 把宣告陣列的地址當參數存進來
void setArrayValue(int* arr, int size, int value){
    for (int i = 0; i < size; i++ ){
        arr[i] = value+i;
    }
} 

//建立一個設定二維陣列值的函式
void set2dArrayValue(int** arr, int row, int col, int value){
    for(int i = 0; i < row; i++ ){
        for(int j = 0; j < col; j++){
            arr[i][j] = value+j;
        }
    }
} 

//一維第一種方式 在此函式中建立指標指向一個分配的記憶體, 並把指標回傳
int* allocaMemo1(int size){
    //建立一個一維指標變數 並分配記憶體
    int* arr = (int*)malloc(sizeof(int)*size);
    return arr;
}

//一維第二種方式 把在main中宣告的指標變數本身地址傳進來,
int* allocaMemo2(int** arr,int size){
    //在指標變數指向的地址分配記憶體
    *arr = (int*)malloc(sizeof(int)*size);
}

//二維陣列第一種方式 在此函式中建立雙重指標指向分配的記憶體, 並把指標回傳
int** allocMem2D1(int row, int col){
    int** vector2D;
    vector2D = (int **)malloc(sizeof(int*)*row);
    for(int i =0; i< row; i++){
        *(vector2D+i) =  (int*)malloc(sizeof(int)* col);
    }
    return vector2D;
}

//二維陣列第二種方式 把三重指標變數當參數傳進來
void allocMem2D2(int*** vector2D, int row, int col){
    /*
    目前vector2D 指向 &array2DD
    */
    //打開一層 為其指向的地址分配記憶體
    *vector2D = (int **)malloc(sizeof(int*)*row);
    //打開第二層 為其指向的地址指向的地址分配記憶體
    for(int i =0; i< row; i++){
        *((*vector2D)+i) =  (int*)malloc(sizeof(int)* col);
    }
}

int main(){

    printf("一維第一種方式\n");
    //建立一個一維陣列指標
    int* array1;
    //接收allocaMemo函式配置記憶體後傳回的指標
    array1 = allocaMemo1(5);

    setArrayValue(array1, 5 , 45);

    printf("\narray1指向位置被附值後=\n");
    //因為array1D陣列指標指向allocaMemo函式malloc的記憶體(在heap區),故setArrayValue()函式結束後陣列沒有被釋放
    for(int i = 0; i< 5; i++){
        printf("%d ", array1[i]);
    }
    printf("\n===========\n");

    printf("一維第二種方式\n");

    int* array2;
    allocaMemo2(&array2, 5);

    setArrayValue(array2, 5 , 21);

    printf("\narray2指向位置被附值後=\n");
    //因為array1D陣列指標指向allocaMemo函式malloc的記憶體(在heap區),故setArrayValue()函式結束後陣列沒有被釋放
    for(int i = 0; i< 5; i++){
        printf("%d ", array2[i]);
    }

    printf("\n===========\n");

    printf("二維第一種方式\n");
    // 用來接住 allocMem2D1函式建立的記憶體
    int ** array2D;

    int row = 2, col = 3;
    //配置記憶體
    array2D = allocMem2D1(row, col);
    //設定值
    set2dArrayValue(array2D, row,col, 30);
    //印出二維陣列儲存的值
    for(int i =0; i< row; i++){
        for(int j =0; j< col; j++){
            printf("值 = %d 地址 = %d\n", array2D[i][j], *(array2D+i)+j);
        }
    }

    printf("\n===========\n");

    printf("二維第二種方式\n");
    //設立一個雙重指標變數指向一個指標變數的地址(設定一開始為NULL)
    int** array2DD = NULL;
    //把雙重指標變數本身地址當參數傳入
    allocMem2D2(&array2DD, row, col);
    //設定值
    set2dArrayValue(array2DD, row,col, 35);
    //印出二維陣列儲存的值
    for(int i =0; i< row; i++){
        for(int j =0; j< col; j++){
            printf("值 = %d 地址 = %d\n", array2DD[i][j], *(array2DD+i)+j);
        }
    }
}