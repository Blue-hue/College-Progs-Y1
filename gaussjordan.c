#include<stdio.h>

int n;
void gauss(float a[][n+1], int n) {
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++) {
      for(j=0;j<n;j++) {
         if(j>i) {
             ratio=a[j][i]/a[i][i];
             for(k=0;k<n+1;k++){
                a[j][k] = a[j][k] - ( ratio * a[i][k]);
             }}}}}

void BackSub(float a[][n+1],float value[],int n ) {   
    int i,j;
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1]; 
    for(i=n-2;i>=0;i--) {
        sum=0;
        for(j=i+1;j<n;j++) {
            sum=sum+a[i][j]*value[j]; } 
        value[i] = (a[i][n]-sum)/a[i][i];
    }
}

void print(float value[],int n)
{  
   int i;
   printf("Values of unknowns are:\n");
   for(i=0;i<n;i++)
      printf("x%d = %f\n",i+1,value[i]);
   
}

void gaussJordan(float a[][n+1],int n)
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++) {
      for(j=0;j<n;j++) {
         if(j!=i) {
             ratio=a[j][i]/a[i][i];
             for(k=0;k<n+1;k++)
                {a[j][k]=a[j][k] -( ratio * a[i][k]);}
                }}}}

void display(float a[][n+1], int n) {
    int i, j;
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            printf("%.3f\t", a[i][j]);
        } printf("\n");
    }
}

int main() {
 int i,j,k,x,y,choice;
    float sum,ratio;
    printf("Enter no of Unknowns :\n");
    scanf("%d",&n);
    float arr[n][n+1],value[n];
    printf("Enter the Augmented Matrix :\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
        scanf("%f",&arr[i][j]);
    }
    printf("Enter desired method:\n1. Gauss Elimination\n2. Gauss-Jordan Method\n3. Jacobi's Method\n4. Gauss-Seidal Method\n5. Matrix Inversion\nChoose : ");
    scanf("%d", &choice);
    if (choice == 1) {
        gauss(arr, n);
        BackSub(arr, value, n);
        display(arr, n);
        print(value, n);
   } else if (choice == 2) {
        gaussJordan(arr, n);
        BackSub(arr, value, n);
        display(arr, n);
        print(value, n);
    } /*else if (choice == 3) {

    } else if (choice == 4) {

    } else {
        printf("Invalid choice. Please enter a valid choice.\n");
    }*/
    return 0;}