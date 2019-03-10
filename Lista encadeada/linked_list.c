#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dataNode{
    int id;
} DataNode;

typedef struct node{
    DataNode data;
    struct node* next;
} Node;

typedef struct list{
    int size;
    Node* head;
} List;

List* createList();
void insertIni(List* list, DataNode data);
void printList(List* list);
void insertEnd(List* list, DataNode data);
int indexOf(List* list, Node* node);
void removeIni(List* list);
void removeEnd(List* list);
void removeNode(List* list, int data);
bool isEmpty(List *list);

List* createList(){
    List* l = (List*) malloc(sizeof(List));
    l->size = 0;
    l->head = NULL;

    return l;
}
void insertIni(List* list, DataNode data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}
void insertEnd(List* list, DataNode data){
    if(list->head == NULL){
        insertIni(list, data);
    }else{
        Node* pointer = (Node*) malloc(sizeof(Node));
        pointer = list->head;
        while(pointer->next != NULL){
            pointer = pointer->next;
        }
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        pointer->next = newNode;
        newNode->next = NULL;
    }
}
void printList(List* list){
    Node* pointer = list->head;
    if(pointer == NULL)
        printf("Lista vazia!\n");
    while(pointer != NULL){
        printf("%d ", pointer->data.id);
        pointer = pointer->next;
    }
}
bool isEmpty(List* list){
        return (list->size == 0);
}
void removeIni(List* list){
    if(!isEmpty(list)){
        Node* pointer = list->head;
        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}
void removeEnd(List* list){
    if(!isEmpty(list)){
        Node* pointer = list->head;
        Node* prev;
        while(pointer->next != NULL){
            prev = pointer;
            pointer = pointer->next;
        }
        prev->next = NULL;
        free(pointer);
        list->size--;
    }
}
void removeNode(List* list, int data){
   if(!isEmpty(list)){
       Node* pointer = list->head;
       Node* prev;
       while(pointer != NULL && pointer->data.id != data){
           prev = pointer;
           pointer = pointer->next;
       }
       if(pointer == NULL)
           return;
       if(pointer == list->head){
           list->head = pointer->next;
       }
       else
           prev->next = pointer->next;
       free(pointer);
   }
}
int main(int argc, char *argv[]){
    List* l = createList();
    DataNode data;
    data.id = 5;
    insertEnd(l, data);
    data.id = 9;
    insertEnd(l, data);
    data.id = 7;
    insertEnd(l, data);
    data.id = 2;
    insertEnd(l, data);
    printList(l);
    printf("\n");
    removeNode(l, 5);
    printList(l);
    return 0;
}
