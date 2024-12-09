#include<stdio.h>
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
void heapify(int a[],int i,int n){
    int lc = 2*i;
    int rc = (2*i)+1;
    int lar = i;
    if(lc<=n && a[lc]>a[lar]){
        lar = lc;
    }
    if(rc<=n && a[rc]>a[lar]){
        lar = rc;
    }
    if(lar!=i){
        swap(&a[lar],&a[i]);
        heapify(a,lar,n);
    }
}
void buildheap(int a[],int n){
    for(int i = n/2;i>=1;i--){
        heapify(a,i,n);
    }
}
void heapsort(int a[],int n){
    buildheap(a,n);
    for(int i = n;i>=2;i--){
        swap(&a[1],&a[i]);
        n--;
        heapify(a,1,n);
    }
}
void main(){
    int a[20];
    int n;
    printf("Enter the array size");
    scanf("%d",&n);
    printf("Enter the array");
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    heapsort(a,n);
    printf("The sorted array is \n");
    for(int i =1;i<=n;i++){
        printf("%d ",a[i]);
    }
}