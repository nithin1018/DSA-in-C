#include<stdio.h>
#define N 5
int q[N];
int f=-1,r=-1;
void enq(int x){
    if(f == (r+1)%N){
        printf("THe q is full");
        return;
    }
    else if(f==-1 && r==-1){
        f=r=0;
        q[f] = x;
    }
    else{
        r=(r+1)%N;
        q[r] = x;
    }
}
void dq(){
    if(f==-1 && r==-1){
        printf("The q is empty");
    }
    else if(f==r){
        printf("%d\n",q[f]);
        f=r=-1;
    }
    else{
        printf("%d\n",q[f]);
        f=(f+1)%N;
    }
}
void display(){
    if(f==-1 && r==-1){
        printf("The q is empty");
    }
    else{
      int i=f;
      while (i!=r)
      {
        printf("%d\n",q[i]);
        i=(i+1)%N;
      }
      printf("%d\n",q[r]);
      
    }
}
void main(){
    enq(10);
    enq(10);
    enq(20);
    enq(30);
    display();
    dq();
    dq();
    display();
    enq(10);
    enq(10);
    enq(20);
    enq(30);
}

