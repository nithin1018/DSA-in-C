#include<stdio.h>
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
int partition(int a[],int lb,int ub){
    int start = lb;
    int end = ub;
    int pivot = a[lb];
    while(start<end){
        while(start<ub && a[start]<=pivot){
            start++;
        }
        while(end>lb && a[end]>=pivot){
            end--;
        }
        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[end],&a[lb]);
    return end;
}
void quicksort(int a[],int lb, int ub){
    if(lb<ub){
        int loc = partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
void main(){
    int a[20];
    int n;
    printf("Enter the array size");
    scanf("%d",&n);
    printf("Enter the array");
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("The sorted array is \n");
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
}