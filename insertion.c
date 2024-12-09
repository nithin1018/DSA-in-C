#include<stdio.h>
void insertion(int a[],int n){
    for(int i = 1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
    insertion(a,n);
    printf("The sorted array is \n");
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
}