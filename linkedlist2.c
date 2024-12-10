#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *link;
};
typedef struct Node node;
node *newnode(int val){
    node *p = (node *)malloc(sizeof(node));
    if(p == NULL){
        printf("THe memory allocation failed\n\n");
        exit(1);
    }else{
        p->info = val;
        p->link = NULL;
        return p;
    }
}
int calc_len(node *head){
    node *temp = head;
    int i = 0;
    while(temp != NULL){
        temp = temp->link;
        i++;
    }
    return i;
}
void insert_beg(node **head,int val){
    node *p = newnode(val);
    p->link = *head;
    *head = p;
}
void insert_end(node **head,int val){
    node *p = newnode(val);
    if(*head == NULL){
        *head = p;
        return;
    }
    node *temp = *head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = p;
}
void insert_pos(node **head, int val) {
    int pos;
    printf("At which position do you want to enter the new node? ");
    scanf("%d", &pos);
    int len = calc_len(*head);
    if (pos < 1 || pos > len + 1) {
        printf("Invalid position! List length is %d.\n", len);
        return;
    }
    node *p = newnode(val);
    if (pos == 1) {
        p->link = *head;
        *head = p;
        return;
    }
    node *temp = *head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->link;
    }
    p->link = temp->link;
    temp->link = p;
}
void display(node *head){
    node *temp = head;
    if(head == NULL){
        printf("THe list is empty");
        return;
    }else{
        while(temp != NULL){
            printf("%-5d",temp->info);
            temp = temp->link;
        }
         printf("\nEND\n");
    }
}
void delete_beg(node **head){
    if(*head == NULL){
        printf("Ther is no elements in the list");
        return;
    }
    node *temp = *head;
    *head = temp->link;
    free(temp);
}
void delete_end(node** head) {
    if (*head == NULL) {  // Check if the list is empty
        printf("There are no elements in the list\n");
        return;
    }
    if ((*head)->link == NULL) {  // If there is only one node
        free(*head);
        *head = NULL;
        return;
    }
    node *temp = *head;
    node *prevnode = NULL;
    while (temp->link != NULL) {  // Traverse to the last node
        prevnode = temp;
        temp = temp->link;
    }
    prevnode->link = NULL;  // Disconnect the last node
    free(temp);  // Free the memory of the last node
}

void delete_pos(node **head){
    if(*head == NULL){
        printf("Ther is no elements in the list");
        return;
    }
    node *temp = *head;
     if (temp->link == NULL) {
        free(temp);
        *head = NULL;  
        return;
    }
    int len = calc_len(*head);
    int pos,i=1;
    printf("Enter the position you want to delete");
    scanf("%d",&pos);
     if (pos < 1 || pos > len) {
        printf("Invalid position! The position must be between 1 and %d\n", len);
        return;
    }
     if (pos == 1) {
        *head = temp->link;
        free(temp);
        return;
    }
    while(i<pos-1){
        temp = temp->link;
        i++;
    }
    node* nextnode = temp->link;
    temp->link = nextnode->link;
    free(nextnode);
}
void insert_before(node** head, int val) {
    node* p = newnode(val);

    if (*head == NULL) {  // If the list is empty
        *head = p;  // New node becomes the head
        return;
    }

    int value;
    printf("Enter the value before which we need to insert: ");
    scanf("%d", &value);

    node* temp = *head;
    node* prevnode = NULL;

    // Traverse the list to find the node with `value`
    while (temp != NULL && temp->info != value) {
        prevnode = temp;
        temp = temp->link;
    }

    if (temp == NULL) {  // Value not found
        printf("There is no such value in the list\n");
        free(p);
        return;
    }

    if (prevnode == NULL) {  // Insert before the head node
        p->link = *head;
        *head = p;
    } else {  // Insert before the found node
        prevnode->link = p;
        p->link = temp;
    }
}

void insert_after(node **head,int val){
    node *p = newnode(val);
    if(*head == NULL){
        *head = p;
    }else{
        int pos;
        node *temp = *head;
         if (*head == NULL) {
        *head = p; // New node becomes the head
        return;
    }
        printf("Enter the value from before we need to insert");
        scanf("%d",&pos);
        while(temp!=NULL && temp->info != pos){
            temp = temp->link;
        }
        if(temp == NULL){
            printf("there is no such value in the list");
            free(p);
            return;
        }
        else{
             p->link = temp->link;
            temp->link = p;
           
            }
        
}
}
void insert_after(node** head, int val) {
    node* p = newnode(val);

    if (*head == NULL) {  // If the list is empty
        *head = p;  // New node becomes the head
        return;
    }

    int pos;
    printf("Enter the value after which we need to insert: ");
    scanf("%d", &pos);

    node* temp = *head;

    // Traverse the list to find the node with `pos`
    while (temp != NULL && temp->info != pos) {
        temp = temp->link;
    }

    if (temp == NULL) {  // Value not found
        printf("There is no such value in the list\n");
        free(p);  // Free the new node
        return;
    }
    // Insert the new node after the found node
    p->link = temp->link;
    temp->link = p;
}

void delete_after(node** head, int val) {
    if (*head == NULL) {  // If the list is empty
        printf("The list is empty\n");
        return;
    }

    int pos;
    printf("Enter the value after which we need to delete: ");
    scanf("%d", &pos);

    node* temp = *head;
    
    // Traverse the list to find the node with `pos`
    while (temp != NULL && temp->info != pos) {
        temp = temp->link;
    }

    if (temp == NULL || temp->link == NULL) {  // If value is not found or no node after it
        printf("There is no such value or no node to delete after it\n");
        return;
    }

    // Deleting the node after the found node
    node* node_to_delete = temp->link;
    temp->link = node_to_delete->link;
    free(node_to_delete);
    printf("Node deleted after %d\n", pos);
}
void delete_before(node** head, int val) {
    if (*head == NULL || (*head)->link == NULL) {  // If the list is empty or has only one node
        printf("The list is empty or doesn't have enough nodes to delete before\n");
        return;
    }

    int pos;
    printf("Enter the value before which we need to delete: ");
    scanf("%d", &pos);

    node* temp = *head;
    node* prevnode = NULL;
    
    // Traverse the list to find the node with `pos`
    while (temp != NULL && temp->info != pos) {
        prevnode = temp;
        temp = temp->link;
    }

    if (temp == NULL || prevnode == NULL) {  // Value not found or no node before it
        printf("There is no such value or no node to delete before it\n");
        return;
    }

    // Deleting the node before the found node
    if (prevnode == *head) {  // If the node to delete before is the head node
        *head = temp;
    } else {
        node* node_to_delete = prevnode;
        prevnode = prevnode->link;
        free(node_to_delete);
    }

    printf("Node deleted before %d\n", pos);
}
void delete_node(node** head, int val) {
    if (*head == NULL) {  // If the list is empty
        printf("The list is empty\n");
        return;
    }

    node* temp = *head;

    // If the head node is the node to delete
    if (temp != NULL && temp->info == val) {
        *head = temp->link;
        free(temp);
        printf("Node with value %d deleted\n", val);
        return;
    }

    node* prevnode = NULL;

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->info != val) {
        prevnode = temp;
        temp = temp->link;
    }

    if (temp == NULL) {  // Node not found
        printf("Node with value %d not found\n", val);
        return;
    }

    // Deleting the node
    prevnode->link = temp->link;
    free(temp);
    printf("Node with value %d deleted\n", val);
}

int main() {
    node* head = NULL; // Initialize an empty list
    int choice, value;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at the desigred position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the End\n");
        printf("6. Delete at the desigred position\n");
        printf("7. Display linked list\n");
        printf("8. Exit\n");
        printf("9. Insert at the befor a desigred value\n");
        printf("9. Insert at the after a desigred value\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_beg(&head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_end(&head, value);
                break;
            case 3:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_pos(&head, value);
                break;
            case 4:
                delete_beg(&head);
                printf("New Linked List: ");
                display(head);
                break;
            case 5:
                delete_end(&head);
                printf("New Linked List: ");
                display(head);
                break;
            case 6:
                delete_pos(&head);
                printf("New Linked List: ");
                display(head);
                break;
            case 7:
                printf("Linked List: ");
                display(head);
                break;
            case 8:
                exit(0);
            case 9:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_before(&head, value);
                break;
            case 10:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_after(&head, value);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}