#include<stdio.h>
#include<stdbool.h>
#include<math.h>

float f(float x){
    return cos(x) - x*exp(x) ;
}

float phi(float x){
    return cos(x)*exp(-x);
}
float dphi(float x){
    return -sin(x)*exp(-x) - cos(x)*exp(-x);
}

int main(){
    float a, x;
    int n, i = 0;
    printf("Enter x(0) :\n");
    scanf("%f", &a);
    printf("Enter decimal places: \n");
    scanf("%d", &n);
    x = a;

    printf("\n  n\t\tx(n)\t\tphi(x(n))\t\tdphi(x(n))\t\tf(x(n))\n\n");
    while(true){
        if(fabs(x-phi(x)) < pow(10,-n))
            break;
        printf("  %d\t%f\t\t%f\t\t%f\t\t%f\n",i, x,dphi(x), phi(x), f(phi(x)));
        x = phi(x);
        i++;
        if(i>500){
            break;
            printf("Convergence is either Slow or Not Convergent \n\n");
        }
    }
    printf("\n\nThe root of the equation is %f correct upto %d dp within %d iterations\n", x ,n, i);
    printf("---------------------------------------------------------------------\n");
    return 0;
}

