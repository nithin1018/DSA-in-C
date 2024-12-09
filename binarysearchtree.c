#include<stdio.h>
#include<stdlib.h>
int top = 0;
typedef struct Node{
    int data;
    struct Node *rlink;
    struct Node *llink;
}node;
node *root = NULL;
node *create(int val){
    node *p = (node *)malloc(sizeof(node));
    p->data = val;
    p->rlink = NULL;
    p->llink = NULL;
    return p;
}
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
void insert(int val){
    node *p = create(val);
    if(root == NULL){
        root = p;
    }else{
        node *par = NULL;
        node *curr = root;
        while(curr!=NULL){
            par = curr;
            if(val<curr->data){
                curr = curr->llink;
            }else{
                curr = curr->rlink;
            }
        }
        if(val<par->data){
            par->llink = p;
        }else{
            par->rlink = p;
        }
    }
}
void search(int val){
    node *curr = root;
    while(curr!=NULL && curr->data != val){
        if(curr->data<val){
            curr = curr->rlink;
        }else{
            curr = curr->llink;
        }
    }
    if(curr!=NULL  && curr->data == val){
        printf("The value is found");
    }else{
        printf("The values is not found in the bst");
    }
}
void display_in(node *root){
    if(root!=NULL){
        display_in(root->llink);
        printf("%d ",root->data);
        display_in(root->rlink);
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
void delete(int item){
    node *par = NULL;
    node *curr = root;
    node *parsucc,*insucc,*subtree;
    while(curr != NULL){
        if(curr->data == item){
            break;
        }else{
            par = curr;
            if(item<curr->data){
                curr = curr->llink;
            }else{
                curr = curr->rlink;
            }
        }
    }
    if(curr == NULL){
        printf("No such node in the tree");
    }else{
        if(curr->llink!=NULL && curr->rlink!=NULL){
            parsucc = curr;
            insucc = curr->rlink;
        while(insucc->llink !=NULL){
            parsucc = insucc;
            insucc = insucc->llink;
        }
        curr->data = insucc->data;
        if(parsucc!=curr){
            parsucc->llink = insucc->rlink;
        }else{
            parsucc->rlink = insucc->rlink;
        }
        free(insucc);
        }else{
            if(curr->llink == NULL){
                subtree = curr->rlink;
            }else{
                subtree = curr->llink;
            }
            if(par == NULL){
                root = subtree;
            }else{
                if(curr == par->llink){
                    par->llink = subtree;
                }else{
                    par->rlink = subtree;
                }
                free(curr);
            }
        }
    }
}
int main(){
    int val = 1;
    while(val!=-1){
        printf("Enter your node (-1 for exit)");
        scanf("%d",&val);
        if(val != -1)
        insert(val);
    }
    delete(10);
    printf("The binary tree inorder traversal is \n");
    display_in(root);
    printf("\nThe binary tree preorder traversal is\n");
    display_pre_1(root);
    search(20);
    search(10);
}