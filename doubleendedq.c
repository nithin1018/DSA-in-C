#include<stdio.h>
# define N 5
int q[N];
int f = -1, r = -1;
int isfull() {
  if (f == (r + 1) % N) {
    printf("The q is full\n");
    return 1;
  }
  else {
    return 0;
  }
}
int isempty() {
  if (f == -1 && r == -1) {
    printf("q is empty\n");
    return 1;
  }
  else {
    return 0;
  }
}
void enqfront(int x) {
  if (isfull()) {
    printf("The queue is full\n");
  }
  else if (f == -1 && r == -1) {
    f = r = 0;
    q[r] = x;
  }
  else {
    f = (f - 1 + N) % N;
    q[f] = x;
  }

}
void enqrear(int x) {
  if (isfull()) {
    printf("The queue is full\n");
  }
  else if (f == -1 && r == -1) {
    f = r = 0;
    q[r] = x;
  }
  else {
    r = (r + 1) % N;
    q[r] = x;
  }
}
void dqfront() {
  if (isempty()) {
    printf("queue is empty\n");
  }
  else if (f == r) {
    printf("dequeue value is %d\n", q[f]);
    f = r = -1;
  }
  else {
    printf("dequeue value is %d\n", q[f]);
    f = (f + 1) % N;
  }
}
void dqrear() {
  if (isempty()) {
    printf("queue is empty\n");
  }
  else if (f == r) {
    printf("dequeue value is %d\n", q[r]);
    f = r = -1;
  }
  else {
    printf("dequeue value is %d\n", q[r]);
    r = (r - 1 + N) % N;
  }
}
void display() {
  int i = f;
  if (isempty()) {
    printf("queue is empty\n");
  }
  else {
    while (i != r) {
      printf("%d\n", q[i]);
      i = (i + 1) % N;
    }
    printf("%d\n", q[r]);
  }
}
void main() {
  int x, choice;
  do {
    printf("\n1.enqueuefront\n2.enqueuerear\n3.dqfront\n4.dqrear\n5.display\n6.isfull\n7.isempty\n8.Quit\n");
    printf("Enter your choice");
    scanf("%d", &choice);
    x = 0;
    switch (choice) {
    case 1: printf("enter the number to be inserted");
      scanf("%d", &x);
      enqfront(x);
      break;
    case 2: printf("enter the number to be inserted");
      scanf("%d", &x);
      enqrear(x);
      break;
    case 3:dqfront();
      break;
    case 4:dqrear();
      break;
    case 5:display();
      break;
    case 6:if (isfull()) {
      printf("The queue is full");
    }
          else {
      printf("The queue is not full");
    }
          break;
    case 7:if (isempty()) {
      printf("The queue is empty");
    }
          else {
      printf("The queue is not empty");
    }
          break;
    case 8:break;
    }
  } while (choice != 8);
}
