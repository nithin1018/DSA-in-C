#include<stdio.h>

int binarysearch(int a[],int n,int top,int bot,int ele);
int bubblesort(int a[],int n);

int bubblesort(int a[],int n){
    int temp;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int binarysearch(int a[],int n, int top, int bot, int ele) {
    while (top <= bot) {
        int mid = (top + bot) / 2;
        if (a[mid] == ele) {
            return mid + 1; 
        } else if (a[mid] > ele) {
            bot = mid - 1;
        } else {
            top = mid + 1;
        }
    }
    return 0; 
}

int recbinary(int a[],int n, int top, int bot, int ele) {
    if(top <= bot) {
        int mid = (top + bot) / 2;
        if (a[mid] == ele) {
            return mid + 1; 
        } else if (a[mid] > ele) {
           return recbinary(a,n,top,mid-1,ele);
        } else {
           return recbinary(a,n,mid+1,bot,ele);
        }
    }
    return 0; 
}

void main(){
    int a[100],n,i,top,bot,ele,found;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the numbers of the array\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    top=0;
    bot=n-1;
    bubblesort(a,n);
   printf("sorted Array\n");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
   printf("the element to be searched\n");
   scanf("%d",&ele);
   found = binarysearch(a,n,top,bot,ele);
   if(found){
    printf("The element is found at %d ",found);
   }else{
    printf("The element is not found");
   }
}