 #include <stdlib.h>
 #include<stdio.h>

 int main(){
    // 陣列名稱matrix是此陣列第0項的地址 => matrix = &matrix[0]
    // 證明: &matrix[1] = &(*(matrix+1))==> &*相消 ==> &matrix[1] = matrix+1

    int matrix[][3] = {{1,3,5},{ 7,9,11}};
    //u印出值
    printf("%d %d %d %d %d %d\n",matrix[0][0],matrix[0][1],matrix[0][2],matrix[1][0],matrix[1][1],matrix[1][2]);
    //印出地址第一種方式
    printf("%d %d %d %d %d %d\n",&matrix[0][0],&matrix[0][1],&matrix[0][2],&matrix[1][0],&matrix[1][1],&matrix[1][2]);
    //印出地址第二種方式
    //證明: 值 => matrix[0][0] = *(*(matrix+0)+0); 位址 => &matrix[0][0] = &(*(*(matrix+0)+0)) = *(matrix+0)+0
    printf("%d %d %d %d %d %d\n",*(matrix+0)+0,*(matrix+0)+1,*(matrix+0)+2,*(matrix+1)+0,*(matrix+1)+1,*(matrix+1)+2);
    //證明 陣列名稱matrix是matrix[0]的地址
    printf("matrix[0][0]的十進位地址 = %d matrix地址 = %d\n",&matrix[0][0], *(matrix+0)+0);
    //建立一個二維陣列指標指向地址matrix,注意固定的格式(星號在裡面)
    int(* vPtr)[3] = matrix;
    printf("vPtr指向地址 = %d vPtr指向地址所儲存的值 = %d\n",vPtr+0, *(vPtr+0));
    //請用指標vPtr印出陣列matrix[1][2])的地址與值 *(*(vPtr+1)+2) == vPtr[1][2]
    printf("matrix[1][2]地址 = %d matrix[1][2]地址所儲存的值 = %d\n",*(vPtr+1)+2, vPtr[1][2]);

    //用迴圈印出vPtr指向陣列裡函的值與地址
    for(int i = 0; i < sizeof(matrix)/sizeof(vPtr[0]); i++ ){
        for(int j = 0; j < sizeof(matrix[0])/sizeof(matrix[0][0]);j++){
            printf("地址 = %d 值 = %d\n", *(vPtr+i)+j, *(*(vPtr+i)+j));
        }
    }
 }
 

 