#include<stdio.h>

int main(){
    int n, i, j, k;
    printf("Enter number of rows of the Square Matrix:\n");
    scanf("%d", &n);
    float a[n+1][n+1], b[n+1], c[n+1];

    //taking the matrix as the input
    for(i=1;i<=n;i++){
        float s = 0;
        for(j=1;j<=n;j++){
            printf("Enter A[%d][%d]\n", i, j);
            scanf("%f", &a[i][j]);
            s += a[i][j];
        }
        printf("Enter b[%d]\n", i);
        scanf("%f", &b[i]);
        c[i] = b[i] + s;
    }

    //printing the matrix
    printf("\nThe Matrix is :\n\n");
    for(i=1;i<=n;i++){printf("A[%d]\t\t",i);}
    printf("b\t\t c\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f\t", a[i][j]);
        }
        printf("%f\t%f\n",b[i], c[i]);
    }

    //upper triangularization
    //k = stage no, i = row no, j = column no
    for(k=1;k<n;k++){
        for(i=k+1;i<=n;i++){
            float m = - a[i][k]/a[k][k];
            for(j=1;j<=n+1;j++){
                a[i][j] += m*a[k][j];
            }
        b[i] += m*b[k];
        c[i] += m*c[k];
        }
    }

    //printing the matrix
    printf("\nThe Upper Triangular Matrix is :\n\n");
    for(i=1;i<=n;i++){printf("A[%d]\t\t",i);}
    printf("b\t\t c\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f\t", a[i][j]);
        }
        printf("%f\t%f\n",b[i],c[i]);
    }

    //back substitution
    float x[n+1], y[n+1];
    x[n] = b[n]/a[n][n];
    y[n] = c[n]/a[n][n];

    printf("\nThe Solutions Are:\n");
    for(j = n-1;j>0; j--){
        float s1=0,s2 = 0;
        for(k=j+1; k<=n;k++){
            s1 += a[j][k]*x[k];
            s2 += a[j][k]*y[k];
        }
    x[j] = (b[j]-s1)/a[j][j];
    y[j] = (c[j]-s2)/a[j][j];
    }

    for(i=1;i<=n;i++){printf("%f\t",x[i]);}

    printf("\n\nThe Check Solutions Are:\n");
    for(i=1;i<=n;i++){printf("%f\t",y[i]);}
    printf("\n\n------------------------------------------\n");

    return 0;
}

