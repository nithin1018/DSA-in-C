#include<stdio.h>
void swap(int *p,int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void selection(int a[],int n){
    for(int i = 0;i<n;i++){
        int large = a[0];
        int k = 0;
        for(int j = 1;j<n-i;j++){
            if(large<a[j]){
                large = a[j];
                k=j;
            }
        }
        swap(&a[n-i-1],&a[k]);
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
    selection(a,n);
    printf("The sorted array is \n");
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
}