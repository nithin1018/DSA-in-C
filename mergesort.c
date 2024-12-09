#include<stdio.h>

void merge(int a[],int l, int m, int r){
    int i = l;
    int j = m+1;
    int k = 0;
    int b[20];
    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            b[k] = a[i++];
        }else{
            b[k] = a[j++];
        }
        k++;
    }
    while(i<=m){
        b[k++] = a[i++];
    }
    while(j<=r){
        b[k++] = a[j++];
    }
    for(int x=0;x<k;x++){
        a[l+x] = b[x];
    }
}
void mergesort(int a[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
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
    mergesort(a,0,n-1);
    printf("The sorted array is \n");
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
}