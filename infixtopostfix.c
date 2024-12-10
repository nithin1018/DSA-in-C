#include<stdio.h>
#include<string.h>
int top = 0;
#define N 20
char s[N];
int isempty(){
    if(top == 0){
        return 1;
    }else{
        return 0;
    }
}
int isfull(){
    if(top==N){
        return 1;
    }else{
        return 0;
    }
}
void push(char a){
    if(isfull()){
        printf("the stack is full");
    }else{
        s[top++] = a;
    }
}
char pop(){
    if(isempty()){
        printf("THe stack is empty");
    }else{
        return s[--top];
    }
}
char peek(){{
    if(isempty()){
        printf("THe stack is empty");
    }else{
        return s[top-1];
    }
}}
int instack(char opr){
    switch (opr)
    {
    case '+':
    case '-': return 2;      
        break;
    case '*':
    case '/': return 4;
                break;
    case '^': return 5;
        break;
    default:
        break; 
    }
}
int inprecedence(char opr){
    switch (opr)
    {
    case '+':
    case '-': return 1;      
        break;
    case '*':
    case '/': return 3;
                break;
    case '^': return 6;
        break;
    default:
        break;
    }
}
int main() {
    int len,i,j,k=0;
    char infix[100],postfix[100];
    printf("Enter the infix operator\n");
    scanf("%s",infix);
    len = strlen(infix);
    for(i=0;i<len;i++){
        if(infix[i] >= 'a' && infix[i] <= 'z'){
            postfix[k++] = infix[i];
        }
        else if(infix[i] == '('){
             push(infix[i]);
            }else if(infix[i] ==')'){
                while (!isempty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
            }else { 
            while (!isempty() && instack(peek()) >= inprecedence(infix[i])) {
                postfix[k++] = pop();
            }
             push(infix[i]);
        }
    }
        while (!isempty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 

    printf("Postfix expression: %s\n", postfix);

    return 0;
    
}
 
