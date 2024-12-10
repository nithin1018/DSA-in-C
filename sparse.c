#include<stdio.h>
int nonZero1 = 0;
int nonZero2 = 0;
int readmat(int a[][10],int m,int n){
    printf("Enter the matrix");
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
int sparseConversion(int a[][10],int b[][3], int m, int n){
    int k1 = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0){
                b[k1][0] = i;
                b[k1][1] = j;
                b[k1][2] = a[i][j];
                k1++;
            }
        }
    }
}
int k3 = 0;
int sparseAdd(int s1[][3], int s2[][3],int s3[][3]){
    int i=0,j=0;
    while(i<nonZero1 &&j<nonZero2){
        if(s1[i][0]<s2[j][0] || (s1[i][0]) == s2[j][0] && s1[i][1] < s2[j][1]){
            s3[k3][0] = s1[i][0];
            s3[k3][1] = s1[i][1];
            s3[k3][2] = s1[i][2];
            i++;
        }
        else if(s1[i][0] > s2[j][0] || (s1[i][0]) == s2[j][0] && s1[i][1] > s2[j][1]){
            s3[k3][0] = s2[j][0];
            s3[k3][1] = s2[j][1];
            s3[k3][2] = s2[j][2];
            j++;
        }
        else{
            s3[k3][0] = s1[i][0];
            s3[k3][1] = s1[i][1];
            s3[k3][2] = s1[i][2] + s2[j][2];
            i++;
            j++;
        }
        k3++;
    }
    while (i < nonZero1) {
        s3[k3][0] = s1[i][0];
        s3[k3][1] = s1[i][1];
        s3[k3][2] = s1[i][2];
        i++;
        k3++;
}

while (j < nonZero2) {
        s3[k3][0] = s2[j][0];
        s3[k3][1] = s2[j][1];
        s3[k3][2] = s2[j][2];
        j++;
        k3++;
}

}
void printSparse(int s3[][3]){
    for (int i = 0; i < k3; i++) {
    printf("%d    %d     %d\n", s3[i][0], s3[i][1], s3[i][2]);
}

}
void main(){
    int row1,col1,row2,col2;
    printf("Enter the row of the first matrix\t");
    scanf("%d",&row1);
    printf("Enter the col of the first matrix\t");
    scanf("%d",&col1);
    printf("Enter the row of the second matrix\t");
    scanf("%d",&row2);
    printf("Enter the col of the second matrix\t");
    scanf("%d",&col2);
    int mat1[10][10];
    readmat(mat1,row1,col1);
    int mat2[10][10];
    readmat(mat2,row2,col2);
    for (int i = 0; i < row1; i++) {
    for (int j = 0; j < col1; j++) {
        if (mat1[i][j] != 0) nonZero1++;
        if (mat2[i][j] != 0) nonZero2++;
    }
}
    int sparse1[10][3],sparse2[10][3],sparse3[20][3];
    sparseConversion(mat1,sparse1,row1,col1);
    sparseConversion(mat2,sparse2,row2,col2);
    printf("The converted mtri is\n");
    printSparse(sparse1);
    printf("The converted mtri is\n");
    printSparse(sparse2);
}