#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//建立 node

typedef struct node{
    char* name; //data1 名字     
    int salary;
    struct  node* next; //node指標指向下一個node    
}Node;   //別名

// 配置記憶體函式
Node* create(char* name, int salary){
    Node* i = (Node*)malloc(sizeof(Node)); //配置記憶體給建立的Node* 指標 i

    //打開Node i 將資料存進去
    i->name = name;    // i->name = name; == (*i).name = name;
    i->salary = salary;
    i->next = NULL;  //初始化先指向空值
    return i;
}

//走訪節點  
void lookup( Node* start){
    Node* ptr = start; //指標指向第一個節點
    while( ptr != NULL){
        printf("%s %d %d\n",ptr->name, ptr->salary, ptr->next);
        ptr = ptr->next;  //指標指向下一個節點
    }
}


//刪除節點
void deleteNode(Node** start, char* deleteName){ // Node** start =傳進來的指標變數本身位址 
    Node* ptr = *start;  // *start = 指標變數start指向的位址
    Node* pre = NULL;  //用來記錄要被刪除節點的前一個節點
    while ( ptr != NULL){   
        if(strcmp(ptr->name, deleteName) == 0){ // 當Node.name == deleteName時
            break;
        }
        pre = ptr;
        ptr = ptr->next;
    }
    //如果遍歷完沒有找到目標node的情況
    if(ptr == NULL){
        printf("Not found!\n");
        return;
    }
    //如果第一個node就是要刪除的節點
    if(ptr == *start){  
        *start = ptr->next;
        free(ptr);
        ptr = NULL;
    }else{
        pre->next = ptr->next;
        free(ptr); //釋放刪除Node記憶體
        ptr = NULL;  //養成好習慣指向Null
    }
}

//新增node
//從開頭新增
Node* pushFront( Node** start, char* newName, int salary){
    Node* newNode = create(newName, salary);
    newNode->next = *start;
    *start = newNode;
}
//從後頭新增
Node* pushBack(Node** start, char* newName, int salary){
    Node* newNode = create(newName, salary);
    Node* current = *start;
    if (*start == NULL){
        *start =newNode;
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}

int main(){
    Node* i1 = create("Mary", 2000);;
    Node* i2 = create("Mike", 3500);
    Node* i3 = create("Mikky", 3000);
    Node* i4 = create("Merica", 3200);

    i1->next = i2;
    i2->next = i3;
    i3->next = i4;
    // printf("%s %d %d\n", (*(i1)).name, i1->salary, i1->next);
    // printf("%d\n", i2); //印出i2指向地址  malloc出來的地址
    // printf("%d\n", i1->next);
    // printf("%d\n", i3);
    // printf("%d\n", i1->next->next);
    // printf("%s %d\n", (*(i2)).name, i2->salary);
    // printf("%s %d\n", (*(i3)).name, i3->salary);

    lookup(i1);   //傳入start的點  
    printf("\n");
    deleteNode(&i1, "Merica");
    lookup(i1);
    printf("\n");
    pushFront(&i1,"Miyoca", 3150);
    lookup(i1);
    printf("\n");
    pushBack(&i1,"Mikasa", 3333);
    lookup(i1);
}
