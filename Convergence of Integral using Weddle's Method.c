#include<stdio.h>
#include<math.h>

float f(float x){
    return sqrt(tan(x));
}
float in(float a, float b, int n){
    int i;
    float s, h;
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

    return s*3*h/10;
}

int main(){
    int n,i=6;
    float e, a, b;
    printf("Enter a:\n");
    scanf("%f", &a);
    printf("Enter b:\n");
    scanf("%f", &b);
    printf("Enter e: \n");
    scanf("%f", &e);
    printf("\nIntegral values : \n");
    while(i<100000){
        if(fabs(in(a,b,i)-in(a,b,i+6))<e){
            printf("\nThe integral converges to = %f, with accuracy = %f, & no of subintervals = %d\n",in(a,b,i), e, i);
            break;
        }
        printf("%d\t%f\n",i, in(a,b,i));
        i+=6;
    }
    if(i>100000)
        printf("\nThe integral doesn't converge upto %d subintervals\n", i);
    return 0;
}

