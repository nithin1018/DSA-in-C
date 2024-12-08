#include<stdio.h>
#include<stdlib.h>
int top = 0;

typedef struct Node
{
    int data;
    struct Node *llink;
    struct Node *rlink;
}node;
node* s[50],s1[50];
int isempty(){
    if(top==0){
        return 1;
    }else{
        return 0;
    }
}
void push(node* x){
        s[top++] = x;
}
node*  pop(){
    if(!isempty()){
        return s[--top];
    }else{
        printf("The stack is empty");
    }
}
node *newnode(int val){
    node *p = (node *)malloc(sizeof(node));
    p->data = val;
    p->llink = NULL;
    p->rlink = NULL;
    return p;
}
node *create(){
    int x;
    printf("Enter the value to be inserted in the node(-1 for no node) ");
    scanf("%d",&x);
    if(x == -1){
        return NULL;
    }
    node *p = newnode(x);
    printf("Enter the left node for the value of %d\n",x);
    p->llink = create();
    printf("Enter the right node for the value %d\n",x);
    p->rlink = create();
}
void display_in(node *root){
    if(root!=NULL){
        display_in(root->llink);
        printf("%d ",root->data);
        display_in(root->rlink);
    }
}
void display_in_1(node *root){
    while(root!=NULL){
        push(root);
        root = root->llink;
    }
    while(!isempty()){
        root = pop();
        printf("%d ",root->data);
        root = root->rlink;
        while(root!=NULL){
            push(root);
            root = root->llink;
        }
    }
}
void display_pre(node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        display_pre(root->llink);
        display_pre(root->rlink);
    }
}
void display_pre_1(node *root){
    push(root);
    while(!isempty()){
        root = pop();
        printf("%d ",root->data);
        if(root->rlink!=NULL){
            push(root->rlink);
        }
        if(root->llink!=NULL){
            push(root->llink);
        }
    }
}
void display_post(node *root){
    if(root!=NULL){
        display_post(root->llink);
        display_post(root->rlink);
        printf("%d ",root->data);
    }
}
void display_post_1(node *root){
     push(root);
    while(!isempty()){
        root = pop();
        while(root!=NULL){
            push(root);
            root = root->llink;
        }
        root = pop();
        printf("%d ",root->data);
    }
}
int main(){
    node *root = create();
    //printf("\n The pre order traversal for the tree is \n");
    //display_pre(root);
    //printf("\n The preorder traversal for the tree using non recursive function \n");
    //display_pre_1(root);
    //printf("\nThe inorder traversal of the tree is \n");
   // display_in(root);
   // printf("\nInorder traversal using non recursive function \n");
   // display_in_1(root);
    printf("The post order traversal of the tree is \n");
    display_post(root);
    printf("\n The post traversal for the tree using non recursive function \n");
    display_post_1(root);

}