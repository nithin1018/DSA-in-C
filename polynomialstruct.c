#include<stdio.h>
typedef struct Poly{
    int coef; 
    int expo;
}poly;

int readpoly(poly s[]){
    int ch;
    int i = 0;
    do{
        printf("Enter the exponent");
        scanf("%d",&s[i].expo);
        printf("Enter the coeffeicient ");
        scanf("%d",&s[i++].coef);
        printf("do you want to enter more values (-1 for no)");
        scanf("%d",&ch);
    }while(ch!=-1);
    return i;
}
int addpoly(poly a[],poly b[], poly c[], int m, int n){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<m && j<n){
        if(a[i].expo == b[j].expo){
            c[k].expo = a[i].expo;
            c[k].coef = a[i++].coef + b[j++].coef;
        }else if(a[i].expo > b[j].expo){
            c[k].expo = a[i].expo;
            c[k].coef = a[i++].coef;
        }else{
            c[k].expo = b[j].expo;
            c[k].coef = b[j++].coef;
        }
        k++;
    }
    while(i<m){
        c[k].expo = a[i].expo;
        c[k++].coef = c[i++].coef;
    }
    while (j<n)
    {
        c[k].expo = b[j].expo;
        c[k++].coef = b[j++].coef;
    } 
    return k;
}
void displaypoly(poly s[],int m){
    int i = 0;
    while(i<m){
        if(i!=0 && s[i].coef>=0){
            printf(" + ");
        }else if(s[i].coef<0){
            printf(" - ");
            s[i].coef = -s[i].coef;
        }
        printf("%dx^%d",s[i].coef,s[i].expo);
        i++;
    }
}
int main(){
    poly s[10];
    poly s1[10];
    poly s2[10];
    printf("ENter the first polynomail \n");
    int m = readpoly(s);
    printf("\n Enter the seocnd polynomail");
    int n = readpoly(s1);
    int k = addpoly(s,s1,s2,m,n);
    displaypoly(s2,k);
}