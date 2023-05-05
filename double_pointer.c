#include <stdlib.h>
#include <stdio.h>


int abc();

int * assigMem(int **p){
    printf("%p\n",&p);
    p = (int *)malloc(sizeof(int));
    *p = 10;
    return p;
}

int main(){
    //建立一個指標變數p 指向null
    int *p = NULL;

    int *a = assigMem(p);
    printf("%a\n",&a);
    printf("%p\n",&p);
    abc();

}


int abc(){
    printf("cpp plus!");
}
