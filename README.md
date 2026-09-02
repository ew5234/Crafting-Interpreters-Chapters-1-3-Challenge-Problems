Chapter 1 Challenge Problems

1. There are at least six domain-specific languages used in the little system I cobbled together to write and publish this book. What are they?
	
    HTML - Hypertext Markup Language: made for displaying and structuring web pages
    CSS
    Make
    Sass
    Jinja2
    Markdown

2. Get a “Hello, world!” program written and running in Java. Set up whatever makefiles or IDE projects you need to get it working. If you have a debugger, get comfortable with it and step through your program as it runs.
```sh
public class HelloWorld {
    public static void main(String[] args){
        System.out.println("Hello World");
    }
}
```

3. Do the same thing for C. To get some practice with pointers, define a doubly linked list of heap-allocated strings. Write functions to insert, find, and delete items from it. Test them.
```sh
#include <stdio.h>
#include <stdlib.h>

//defining node
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

//node creation function
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = data;
    newNode->previous = data;
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
    for (int i=1; temp != NULL && i < position - 1; i++){
        temp = temp->next;
    }

    //if temp == Null, out of bound
    if (temp == NULL){
        printf("Position is greater than number of nodes.");
        return;
    }

    //insert new node
    else{
        newNode->next = temp->next;
        newNode->previous = temp;

        //update the old node if not last in list
        if (temp->next != NULL){
            temp->next->previous = newNode;
        }

        temp->next = newNode;
        free(temp);
    }
}

void deleteNode(Node** head, int position){
    //if list is empty
    if((*head == NULL)){
        printf("List is Empty.");
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
        printf("Position is greater than number of nodes.");
        return;
    }

    if(temp->next != NULL){
        temp->next->previous = temp-> previous;
    }
    if(temp->previous != NULL){
        temp->previous->next = temp->next;
    }
    free(temp);
}

void findNode(Node** head, int data){
    Node* temp = *head;

    //find the data indicated
    for (int i = 0; temp != NULL; i++){
        if (temp->data == data){
            printf("%d at position %d", data, i);
            return;
        }
        temp = temp->next;
    }

    //if temp==Null, data not in list
    if (temp == NULL){
        printf("Inputted Data is not in list");
        return;
    }
}

int main(){
    Node* head = NULL;
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 1);
    insertNode(&head, 3, 2);
    insertNode(&head, 4, 3);
}
```
