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
    printf("Enter n (6 divides): \n");
    scanf("%d", &n);
    if(n%6 != 0)
        printf("6 must divide n");
    else{
        s = f(a)+f(b);
        h = (b-a)/n;

        for(i=1;i<n;i++){
            if(i%6 == 0)
                s += 2*f(a+i*h);
            else if(i%2 == 0)
                s += f(a+i*h);
            else if(i%6 == 3)
                s += 6*f(a+i*h);
            else
                s += 5*f(a+i*h);
        }

        printf("x \t\t\t f(x)\n\n");
        for(i = 0; i<= n; i+= 6){
            printf("%f \t\t %f\n", a+i*h, f(a+i*h));
        }
        printf("\nThe Required Value is = %f , for n = %d\n", 3*h*s/10, n);
    }
    return 0;
}
