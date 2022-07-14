#include<stdio.h>
#include<math.h>

float f(float x){
    return cos(x)-x*exp(x) ;
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
        printf("\nn\ta\t\tb\t\tx\t\tf(x)\n\n");
        while(fabs(a-b)>= pow(10,-n)){
            x = (a+b)/2;
            printf("%d\t%f\t%f\t%f\t%f\n",i, a, b, x, f(x));
            if(fabs(f(x)) < pow(10,-n))
                break;
            else if(f(a)*f(x)<0){
                b = x;
            }
            else
                a=x;
            i++;
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
