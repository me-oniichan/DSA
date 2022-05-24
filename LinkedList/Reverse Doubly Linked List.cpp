//Probelem Statement: https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    if (llist == nullptr) return llist;
    
    DoublyLinkedListNode *ptr = llist;
    
    while(ptr != nullptr){
        DoublyLinkedListNode* node = ptr;
        node = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = node;
        if (node == nullptr) llist = ptr;
        ptr = node;
    }
    return llist;
}
