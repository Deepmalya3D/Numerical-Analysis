#include<stdio.h>
#include<math.h>

float f(float x){
    return pow(x,3) + x - 1;
}
float f1(float x){
    return 3*pow(x,2) + 1;
}

int main(){
    float x;
    int n, i = 0;
    printf("Enter decimal places: \n");
    scanf("%d", &n);
    printf("Enter x(0):\n");
    scanf("%f", &x);

    float y = x - 1;
    printf("\n\tn\tx(n)\t\tx(n+1)\n\n");
    while(fabs(x-y)>= pow(10,-n)){
        y = x;
        x = x - f(x)/f1(x);
        printf("\t%d\t%f\t%f\n",i, y, x);
        i++;
        if(i>100){
            printf("\nConvergence is Slow\n\n");
            break;
        }
    }
    printf("\nThe root of the equation is %f correct upto %d dp within %d iterations\n", x ,n, i);
    return 0;
}

