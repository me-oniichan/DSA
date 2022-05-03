#include <iostream>
using namespace std;

class LinkedList{
    public:
        int val;
        LinkedList *next = (LinkedList*)malloc(sizeof(LinkedList));

        void append(int, LinkedList**);
        void insert(int, int, LinkedList**);
        void pop(LinkedList**, int index = -1);
        int at(int index, LinkedList**);
};

void LinkedList :: append(int value, LinkedList **head){
    LinkedList *newElem = new LinkedList;
    newElem->val = value;
    newElem->next = NULL;

    LinkedList *ref = *head;
    //if first elemnt is NULL
    if (*head == NULL) 
    {*head = newElem; return;}
    
    while (ref->next != NULL) 
    {ref = ref->next;}
    
    ref->next = newElem;
}

void LinkedList :: insert(int value, int index, LinkedList** head){
    LinkedList *newElem = new LinkedList;
    newElem->val = value;

    LinkedList *ref = *head;
    
    for (int i = 1; i < index; i++)
    {
        ref = ref->next;
    }
    
    if (index == 0){  //to insert at begining
        newElem->next = *head;
        *head = newElem;   //set head at new first value
        return;
        }
    
    newElem->next = ref->next;
    ref->next = newElem;

}


void LinkedList :: pop(LinkedList**head, int index){
    //to delete first elemnt
    if (index == 0){
        LinkedList *temp = (*head)->next;
        delete *head;
        *head = temp;
        return;
    }
    
    int i = 1;
    for(LinkedList *ptr = *head; ptr->next != NULL; ptr = ptr->next){
        if (i == index)
        {
            LinkedList *temp = ptr->next->next;
            delete ptr->next;
            ptr->next = temp;
            return;
        }
        
        i++;
    }
}

int LinkedList :: at(int index, LinkedList**head){
    int i = 0;
    for (LinkedList*ptr = *head; ptr !=NULL; ptr = ptr->next)
    {
        if (i == index) return ptr->val;
        i++;
    }
    return -1;
}

int main(){
    LinkedList *list = NULL;

    list->append(5, &list);
    list->append(6, &list);
    list->append(7, &list);
    list->append(8, &list);
    list->append(9, &list);
    // list->insert(0, 0, &list);
    // list->insert(2, 3, &list);
    // list->insert(6, 4, &list);
    list->pop(&list, 10);

    cout<<"Linked List is as follows:"<<endl;
    for (LinkedList *i = list; i != NULL; i = i->next)
    {
        cout<<i->val<<" ";
    }
    cout<<endl;
    cout<<"Value at 3 is : "<< list->at(3, &list)<<endl;
    
return 0;

}