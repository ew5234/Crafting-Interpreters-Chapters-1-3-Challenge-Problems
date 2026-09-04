
#include <stdio.h>
#include <stdlib.h>

//defining node
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* previous;
} Node;

//node creation function
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void insertNode(Node** head, int data, int position){
    Node* newNode = createNode(data);

    //if position is at the front
    if (position == 0){
        //if list is empty
        if (*head == NULL){
            *head = newNode;
            return;
        }
        else{
            //if list is not empty
            newNode->next = *head;
            (*head)-> previous = newNode;
            *head = newNode;
            return;
        }
    }

    //find the node before the position indicated
    Node* temp = *head;
    for (int i=1; temp != NULL && i < position; i++){
        temp = temp->next;
    }

    //if temp == Null, out of bound
    if (temp == NULL){
        printf("Position %d is greater than number of nodes.\n", position);
        return;
    }

    //insert new node
    else{
        newNode->next = temp->next;
        newNode->previous = temp;

        //update the position's old node if not last in list
        if (temp->next != NULL){
            temp->next->previous = newNode;
        }

        temp->next = newNode;
    }
}

void deleteNode(Node** head, int position){
    //if list is empty
    if((*head == NULL)){
        printf("List is Empty.\n");
        return;
    }

    Node* temp = *head;

    //deleting head
    if (position == 0){
        *head = (*head)->next;
        //if a node still exists
        if (*head != NULL){
            (*head)->previous = NULL;
        }
        free(temp);
        return;
    }

    //find the position indicated
    for (int i = 1; temp != NULL && i < position; i++){
        temp = temp->next;
    }

    //if temp==Null, out of bound
    if (temp == NULL){
        printf("Position %d is greater than number of nodes.\n", position);
        return;
    }

    if(temp->next != NULL){
        temp->next->previous = temp-> previous;
    }
    if(temp->previous != NULL){
        temp->previous->next = temp->next;
    }
}

void findNode(Node** head, int data){
    Node* temp = *head;

    //find the data indicated
    for (int i = 0; temp != NULL; i++){
        if (temp->data == data){
            printf("%d at position %d\n", data, i);
            return;
        }
        temp = temp->next;
    }

    //if temp==Null, data not in list
    if (temp == NULL){
        printf("Inputted Data is not in list\n");
        return;
    }
}

void printList(Node* head)
{
    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 1);
    insertNode(&head, 3, 2);
    
    printList(head);
    
    deleteNode(&head, 2);
    
    findNode(&head, 1);
    findNode(&head, 2);
    findNode(&head, 3);
}