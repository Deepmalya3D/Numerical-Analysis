#include<stdio.h>
#include<math.h>

float f(float x, float y){
    return sin(x+y)/log(2+x*y);
}

int main(){
    float x0=0, y0=2.5, x, y, y1, h=0.1, e,d;
    int i=1,n,j;
    printf("Enter n: \n");
    scanf("%d", &n);
    printf("Enter error: \n");
    scanf("%f", &e);
    float a[n+1],b[n+1];
    printf("\nk\tx(k)\t\ty(k)\n");

    for(j=1;j<=n;j++){
        x = x0 + h;
        y1 = y0 + h*f(x0,y0);       //Euler
        do{
            y = y0 + h/2*(f(x0,y0)+f(x,y1));
            printf("\n%d\t%f\t%f",i,x,y);
            d = y-y1;
            y1 = y;
            i++;
        }while(fabs(d)>=e);
        a[j] = x;
        b[j] = y;
        printf("\n--------------------------------------\n\n");
        i = 1;
        x0 = x;
        y0 = y;
    }
    printf("\n\tx(k)\t\ty(k)\n\n");
    for(i=1;i<=n;i++){
        printf("\t%f\t%f\n",a[i],b[i]);
    }

    printf("\n--------------------------------------------\n");
    return 0;
}



