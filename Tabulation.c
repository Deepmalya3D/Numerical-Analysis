#include<stdio.h>
#include<math.h>

float f(float x){
    return pow(x,3)-0.26 ;
}

int main(){
    float a,b,i, j = 0.1;
    int n;
    printf("Enter a:\n");
    scanf("%f", &a);
    printf("Enter b:\n");
    scanf("%f", &b);
    printf("Enter decimal places: \n");
    scanf("%d", &n);

    if(f(a)*f(b)<0){
        printf("\na\t\tb\t\tf(x)\t\tf(a)*f(b)\n\n");
        while(fabs(a-b)>= pow(10,-n)){
            for(i=1;i<=10;i++){
                if(f(a+(i-1)*j)*f(a+i*j)<0){-
                    printf("%f\t%f\t%f\t%f\n\n", a+(i-1)*j, a+i*j,f(a+(i)*j), f(a+(i-1)*j)*f(a+i*j));
                    b = a+i*j;
                    j = j/10;
                    break;
                }
                printf("%f\t%f\t%f\t%f\n", a+(i-1)*j, a+i*j,f(a+(i)*j), f(a+(i-1)*j)*f(a+i*j));
            }
            a = a+(i-1)*j*10;
        }
        printf("\nThe root of the equation lies in (%f, %f) with %d dp\n",a,b ,n);
    if(fabs(f(a))<fabs(f(b)))
        printf("\nThe root of the equation is %f with %d dp\n", a, n);
    else
        printf("\nThe root of the equation is %f with %d dp\n", b,n);
    }
    else
        printf("There doesn't exist any root in this interval");
    return 0;
}
