//Problem Statement : https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    if (llist == nullptr) return new DoublyLinkedListNode(data);
    
    DoublyLinkedListNode *ptr = llist;
    while (ptr->next != nullptr && ptr->next->data < data) {
        ptr = ptr->next;
    }
    
    DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
    
    if (ptr == llist && data < ptr->data){
        node->next = llist;
        llist->prev = node;
        llist = node;
    }
    
    else if (ptr->next == nullptr){
        ptr->next = node;
        node->prev = ptr;
    }
    
    else if (ptr->next->data >= data){
        node->next = ptr->next;
        ptr->next->prev = node;
        node->prev = ptr;
        ptr->next = node;
    }
    return llist;   
}
