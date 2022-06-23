#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
    char data;
    struct LinkedList *next;
} LinkedList;

LinkedList *allocNode(int data) {
    LinkedList *node = (LinkedList *)malloc(sizeof(LinkedList));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList *appendList(LinkedList *head, char val) {
    LinkedList *node = allocNode(val);
    node->data = val;
    node->next = NULL;
    if (head == NULL) {
        head = node;
    } 
    else{
        LinkedList *lastNode = head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        } 
        lastNode->next = node;
    }
    return head;
}

void showList(LinkedList *head) { 
    LinkedList *temp = head;
    while (temp != NULL) {
        printf("[%c]->", temp->data);
        temp = temp->next;
    }
    printf("->NULL\n");
}

LinkedList *reverseList(LinkedList *head) {
    LinkedList *pre = NULL;
    LinkedList *now = head;
    LinkedList *next = NULL;
    while(now) {
        next = now->next;
        now->next = pre;
        pre = now;
        now = next;
    }
    return pre;
}

int main() {
    LinkedList* head = NULL;
    head = appendList(head, 'A');
    head = appendList(head, 'B');
    head = appendList(head, 'C');
    head = appendList(head, 'D');
    head = appendList(head, 'E');
    showList(head);
    head = reverseList(head);
    showList(head);
    return 0;
}
