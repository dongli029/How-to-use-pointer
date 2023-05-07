#include <stdlib.h>
#include <stdio.h>
#include <string.h> //strcmp用

typedef struct island{
    char* name;
    int opens;
    struct island* next; //包含另一個island*結構體指標 next
}Island;

// 建立結構體指標
Island* create(char* name, int num){
    Island* a = (Island*)malloc(sizeof(Island));
    a ->name = name;
    a->opens = num;
    a->next = NULL;
    return a;
}

// 顯示結構體儲存的值 
void display(Island* start ){
    Island* i = start;
    while(i != NULL){
        printf("%s %d\n", i->name, i->opens);  
        i = i->next; // 打開island 結構體start裡的next(單向linkedlist指向下一個)
    }
}

// 首先傳入Island**型別結構體變數start自己的地址(linkedlist開頭)
void removeNode(Island** start, char* targetName){
    Island* current = *start; //一個 Island型別結構體指標 指向start指向的地址
    Island* pre = NULL; //建立Island結構體指標先指向null
    //當兩者名字不同時,繼續找(strcmp(char* dst, const char* src) => 若兩字串完全相同 回傳0)
    // current ->name 是字串地址
    while(current != NULL){
        //假設找到要刪除的node後, 跳出while迴圈
        if(strcmp(current ->name, targetName) == 0){
            break;
        }
        pre = current;
        current = current->next; 
    }
    //如果linkedlist沒有此值
    if(current == NULL){
        printf("Not found\n");
        return;
    }
    //如果current與*start指向同一個地址, 令*start指向下一個節點(指向island結構體的結構體指標),用來處理刪除第一個節點用
    if(current == *start){
        *start = current->next;
        free(current); //釋放current指向的記憶體
        current = NULL; //將current指向null
    }else{
        //將pre指向 current->next 然後刪除current
        pre->next = current->next;
        free(current); //釋放current指向的記憶體
        current = NULL; //將current指向null
    } 
}

//從開頭加入節點, 把指向開頭節點的指標的本身地址的指標變數傳進來
void pushFront(Island** start, char* name, int num){
    //建立一個指標指向新成立的節點的地址
    Island* newNode = create(name, num);
    //新節點的next指向開頭節點指向的地址
    newNode-> next = *start;
    //再把start指向新的節點
    *start = newNode;
}
//從linkedlist最後加入節點
void pushBack(Island** start, char* name, int num){
    Island* newNode = create(name, num);
    Island* current = *start;
    //假設start 是一個不存在的空linkedlist 
    if(*start == NULL){
        *start = newNode;
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

int main(){
    Island* i1 = create("i1", 900);
    Island* i2 = create("i2", 1400);
    Island* i3 = create("i3", 720);
    Island* i4 = create("i4", 820);
    
    i1->next =i2;
    i2->next =i3;
    i3->next =i4;

    //把起始節點本身的地址傳進來, 設定移除i4
    removeNode(&i1,"i4");
    display(i1);

    printf("=======\n");
    //在開頭加入節點
    pushFront(&i1, "i0", 1245);
    display(i1);

    printf("=======\n");
    //在尾巴加入節點
    pushBack(&i1, "i5", 6666);
    display(i1);
}