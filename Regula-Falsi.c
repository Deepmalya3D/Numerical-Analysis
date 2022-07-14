#include<stdio.h>
#include<math.h>

float f(float x){
    return cos(x) - x*exp(x);
}

int main(){
    float a,b,x;
    int n, i = 0;
    printf("Enter decimal places: \n");
    scanf("%d", &n);
    input:
    printf("Enter a:\n");
    scanf("%f", &a);
    printf("Enter b:\n");
    scanf("%f", &b);


    if(f(a)*f(b)<0){
        printf("\n\tn\ta(n)\t\tb(n)\t\tf(a(n))\t\tf(b(n))\t\tx(n+1)\t\tf(x(n+1))\th(n)\n\n");
        while(fabs(a-b)>= pow(10,-n)){
            x = a + fabs(f(a))*(b-a)/(fabs(f(a))+fabs(f(b)));
            printf("\t%d\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",i, a, b, f(a), f(b), x, f(x), fabs(x-a));
            if(fabs(f(x)) < pow(10,-n))
                break;
            else if(f(a)*f(x)<0)
                b = x;
            else
                a=x;
            i++;
            if(i>100){
                printf("\nConvergence is Slow\n\n");
                break;
            }
        }
        printf("\nThe root of the equation is %f correct upto %d dp within %d iterations\n", x ,n, i);
    }
    else if(fabs(f(a)) < pow(10,-n))
        printf("\nThe root of the equation is %f with %d dp\n", a ,n);
    else if(fabs(f(b)) < pow(10,-n))
        printf("\nThe root of the equation is %f with %d dp\n", b ,n);
    else{
        printf("There doesn't exist any root in this interval\n\n");
        goto input;
    }
    return 0;
}

