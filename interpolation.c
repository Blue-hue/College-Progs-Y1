#include<stdio.h>
#include<math.h>

float x,u1,u,y;
int i,j,n,fact;

int main()
{
    printf("Enter no. of terms : ");
    scanf("%d",&n);
    float a[n][n+1];
    printf("\nEnter Values of x : ");
    for(i=0;i<n;i++)
          scanf("%f",&a[i][0]);
    printf("\nEnter Values of y : ");
    for(i=0;i<n;i++)
          scanf("%f",&a[i][1]); 
    printf("\nEnter value of x for which you want y : ");
    scanf("%f",&x);

    if (x > a[0][0] && x < a[1][0]) newton_forward(a, n);
    else if (x < a[n-1][0] && x > a[n-2][0]) newton_backward(a, n);
    else printf("Lagrange interpolation needs to be used."); 
    }    
   
void newton_forward(float a[][n+1], int n) {
       for(j=2;j<n+1;j++) {
        for(i=0;i<n-j+1;i++)
            a[i][j] = a[i+1][j-1]-a[i][j-1];
    }
    printf("The Difference Table is as follows:\n");
    for(i=0;i<n;i++) {
     for(j=0;j<=n-i;j++)
        printf("%f \t|",a[i][j]);
     printf("\n");
    }
 
    u= (x - a[0][0])/(a[1][0]-a[0][0]);
    y=a[0][1]; 
    u1=u;
    fact=1;
    for(i=2;i<=n;i++)
    {
        y=y+(u1*a[0][i])/fact;
        fact=fact*i; 
        u1=u1*(u-(i-1));
    }
    printf("\nValue at x = %f is = %f", x, y);
    }

void newton_backward(float a[][n+1], int n) {
       for(j=2;j<n+1;j++) {
        for(i=0;i<n-j+1;i++)
            a[i][j] = a[i+1][j-1]-a[i][j-1];
    }
    printf("The Difference Table is as follows:\n");
    for(i=0;i<n;i++) {
     for(j=0;j<=n-i;j++)
        printf("%f \t|",a[i][j]);
     printf("\n");
    }
 
 u= (x - a[n-1][0])/(a[1][0]-a[0][0]);
    y=a[n-1][1]; 
    u1=u;
    fact=1;
    j=2;  
    for(i=n-2;i>=0;i--)
    {
        y=y+(u1*a[i][j])/fact;
        fact=fact*j; 
        u1=u1*(u+(j-1));
        j++;
    }
    printf("\nValue at x = %f is = %f", x, y);
}
