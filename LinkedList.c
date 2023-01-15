#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int insert_node_end(int data){
    if(head == NULL)
    {
        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        head = tail = new;
        return 0;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    tail->next = new;

    tail = new;
}

int insert_node_head(int data)
{
    if(head == NULL)
    {
        struct node *new = (struct node *) malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        head = tail = new;
        return 0;
    }

    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->data = data;
    new->next = head;

    head = new;
}

int print_linked_list()
{
    struct node *current_element = head;
    while (current_element != NULL)
    {
        printf("%d\n", current_element->data);
        current_element = current_element->next;
    }
}

int delete_node(int data)
{
    struct node *before = NULL;
    struct node *current = head;

    if(head == NULL){
        return 0;
    }

    if(head -> data == data)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);

        return 0;
    }

    while (current != NULL && current->data != data){
        before = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return -1;
    }

    before->next = current->next;

    if(tail->data == data){
        tail = before;
    }

    free(current);
    return 0;

}

int main() {
    insert_node_end(32);
    insert_node_end(31);
    insert_node_end(3111);
    insert_node_head(1);

    print_linked_list();
    return 0;
}
