#include <iostream>
#include "headers/linked_list.h"
using namespace std;

int LinkedList::create_head(int data){
    LinkedListNode new_node(data);
    new_node->next = this->head;
    this->head = new_node;
}

int LinkedList::append_list(int data){
    LinkedListNode* new_node = data;
    LinkedListNode* last= this->head;

    new_node->next = NULL;

    if(this->head == null){
        this->head = data;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;

    free(new_node);
    free(last);

}

LinkedList::search(LinkedListNode* node=this, int data){
    if(node == NULL){
        return NULL;
    }

    if(node->data == data){
        return true;
    }
    else{
        return search(node->next, x);
    }
}

LinkedList::print_list(){
    node *current=start;

    while(current != NULL){
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}