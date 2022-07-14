#include<stdio.h>
#include<math.h>

float f(float x){
    return sqrt(tan(x))*cos(x)*exp(-x);
}

int main(){
    int i,n;
    float a,b,h,s;
    printf("Enter a = \n");
    scanf("%f", &a);
    printf("Enter b = \n");
    scanf("%f", &b);
    printf("Enter n = \n");
    scanf("%d", &n);
    s = f(a) + f(b);
    h = (b-a)/n;
    for(i=1;i<n;i++){
        s += 2*f(a+i*h);
    }
    printf("x \t\t\t f(x)\n\n");
    for(i=0;i<=n;i++){
        printf("%f \t\t %f\n", a+i*h, f(a+i*h));
    }
    printf("\nThe Integral Value is = %f\n", h*s/2);
    return 0;
}
