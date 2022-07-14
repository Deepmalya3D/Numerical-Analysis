#include<stdio.h>


int main(){
    int n,i,j;
    printf("Enter n: \n");
    scanf("%d", &n);
    float x[n], y[n], z, s=0;
    for(i=0;i<=n;i++){
        printf("Enter x[%d] :\n", i);
        scanf("%f", &x[i]);
        printf("Enter y[%d] :\n", i);
        scanf("%f", &y[i]);
    }
    printf("Enter x: \n");
    scanf("%f", &z);
    for(i=0;i<=n;i++){
        float p=1;
        for(j=0;j<=n;j++){
            if(i==j){
                continue;
            }
            p *= (z-x[j])/(x[i]-x[j]);
        }
        s += p*y[i];
    }
    printf("The Value is %f", s);
    return 0;
}

