#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList{
private:
    int head;

    class Node{
        Node* next = NULL;
        int data;

        Node(int data){
            this->data = data;
        }
    };

public:
    int create_head(int data);
    int append_list(int data);
    int delete_data(int data);
    bool search(int data);
    bool search(int first_node, 
                int second_node);
    int print_list();
};

#endif