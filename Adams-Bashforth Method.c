#include<stdio.h>
#include<math.h>

float f(float x, float y){
    return sin(x*y+1)/(exp(x)*log(x*x+x*y+y*y));
}

int main(){
    float x0=0, y0=1.2,x,y, k,k1,k2,k3,k4, h=0.1;
    int i,n;
    printf("Enter n: \n");
    scanf("%d", &n);
    float a[n+1], b[n+1], z[n+1];
    a[0] = x0;
    b[0] = y0;
    z[0] = f(x0,y0);
    printf("\nk\tx\t\ty\t\tf(x,y)\n");
    printf("\n0\t%f\t%f\t%f",x0,y0,z[0]);
    for(i=1;i<=n;i++){

        x = x0 + h;
        if(i<4){
            k1 = h*f(x0,y0);
            k2 = h*f(x0+h/2,y0+k1/2);
            k3 = h*f(x0+h/2,y0+k2/2);
            k4 = h*f(x0+h,y0+k3);
            k = (k1+2*k2+2*k3+k4)/6;
            y = y0 + k;
        }
        else{
            y += h*(55*z[i-1]-59*z[i-2]+37*z[i-3]-9*z[i-4])/24;
        }

        a[i] = x;
        b[i] = y;
        z[i] = f(x,y);
        printf("\n%d\t%f\t%f\t%f",i,a[i],b[i],z[i]);
        x0 = x;
        y0 = y;
    }

    printf("\n\n--------------------------------------------\n");
    return 0;
}


