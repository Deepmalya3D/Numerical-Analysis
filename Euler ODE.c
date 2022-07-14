#include<stdio.h>
#include<math.h>

float f(float x, float y){
    return sin(x+y)/log(2+x*y);
}

int main(){
    float x0=0, y0=2.5, x, y, h=0.1;
    int i,n;
    printf("Enter n: \n");
    scanf("%d", &n);
    printf("\nk\tx(k)\t\ty(k)\n");
    for(i=1;i<=n;i++){
        x = x0 + h;
        y = y0 + h*f(x0,y0);
        printf("\n%d\t%f\t%f",i,x,y);
        x0 = x;
        y0 = y;
    }
    printf("\n\n--------------------------------------------\n");
    return 0;
}


