#include<stdio.h>
#include<math.h>

float f(float x){
    return sin(x)*sin(x)/sqrt((1+pow(x,4)));
}

int main(){
    int i, n;
    float a, b, s, h;
    printf("Enter a: \n");
    scanf("%f", &a);
    printf("Enter b: \n");
    scanf("%f", &b);
    printf("Enter n (even): \n");
    scanf("%d", &n);
    if(n%2 != 0){
        printf("Sorry n must be even");
    }else{
        s = f(a)+f(b);
        h = (b-a)/n;

        for(i=1;i<n;i++){
            if(i%2 == 1)
                s += 4*f(a+i*h);
            if(i%2 == 0)
                s += 2*f(a+i*h);
        }

        printf("x \t\t\t f(x)\n\n");
        for(i = 0; i<= n; i++){
            printf("%f \t\t %f\n", a+i*h, f(a+i*h));
        }
        printf("\nThe Required Value is = %f , for n = %d\n", h*s/3, n);
    }
    return 0;
}
