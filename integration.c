#include<stdio.h>

float f(float x) {
    return x*x*x;
}

int n;
float i, a, b, sum = 0, h;

void trapezoidal_rule() {
    for(i = a+h; i<b; i = i+h)
       sum = sum + 2*f(i);
    sum = (h * sum)/2;
    printf("\nValue of The integral = %f", sum);
}

void simpson3_8() {
    int position_of_term = 1;
    for(i=a+h;i<b;i=i+h) {
       if(position_of_term % 3 ==0)
         sum = sum + 2*f(i);
       else
         sum = sum + 3*f(i); 
       position_of_term++;   
    }
    sum = 3*h*sum/8;
    printf("\nValue of The integral = %f",sum);
}

void simpson1_3(){
    int position_of_term = 1;
    for(i=a+h;i<b;i=i+h) {
       if(position_of_term % 2 ==0)
         sum = sum + 2*f(i);
       else
         sum = sum + 4*f(i); 
       position_of_term++;  
    }
    sum = (h * sum)/3;
    printf("\nValue of The integral = %f",sum);   
}
 
int main() {
    int ch;
    printf("Enter desired method :\n1. Trapezoidal Rule\n2. Simpson's 1/3rd Rule\n3. Simpson's 3/8th Rule\nChoice : ");
    scanf("%d", &ch);
    printf("Enter Value of a and b : ");
    scanf("%f%f", &a, &b);
    printf("\nEnter no. of Intervals : ");
    scanf("%d", &n);
    h = (b-a)/n;
    sum = f(a) + f(b);
    switch (ch)
    {
    case 1: trapezoidal_rule();
        break;
    case 2: simpson1_3();
        break;
    case 3: simpson3_8();
        break;
    default:
        printf("Enter a valid choice.");
    }
}