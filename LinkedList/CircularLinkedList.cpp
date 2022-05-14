#include <iostream>
#include <stdlib.h>
using namespace std;

//circular Linked List

class CLinkedList{
    public:
        int val;
        CLinkedList * next = (CLinkedList*)malloc(sizeof(CLinkedList));

        void append(int, CLinkedList**);
};

void CLinkedList :: append(int value, CLinkedList**head){
    if(*head == NULL){
        CLinkedList newelem;
        newelem.val = value;

        *head = &newelem;
        (*head)->next = *head;
        return;
    }

    CLinkedList *newelem = new CLinkedList;
    newelem->val = value;
    newelem->next = *head;
    
    CLinkedList*ptr = *head;
    while (ptr->next != *head)
    {
        ptr = ptr->next;
    }
    
    ptr->next = newelem;
}

int main(){
    CLinkedList *list;
    list = NULL;
    
    list->append(5, &list);
    list->append(6, &list);
    list->append(7, &list);
    list->append(8, &list);
    list->append(9, &list);

    //print list
    CLinkedList *ptr = list;
    do
    {
        cout<<ptr->val<<' ';
        ptr = ptr->next;
    } while (ptr != list);
return 0;
}