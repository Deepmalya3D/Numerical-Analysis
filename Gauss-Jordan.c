#include<stdio.h>

int main(){
    int n, i, j, k;
    printf("Enter the size of the Square Matrix:\n");
    scanf("%d", &n);
    float a[n+1][n+1], b[n+1];

    //taking the matrix as the input
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("Enter A[%d][%d]\n", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("Enter b[%d]\n", i);
        scanf("%f", &b[i]);
    }

    //printing the matrix
    printf("\nThe Matrix is :\n\n");
    for(i=1;i<=n;i++){printf("A[%d]\t\t",i);}
    printf("b\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f\t", a[i][j]);
        }
        printf("%f\n",b[i]);
    }

    //diagonalization
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            if(i==k)
                continue;
            float m = - a[i][k]/a[k][k];
            for(j=1;j<=n;j++){
                a[i][j] += m*a[k][j];
            }
        b[i] += m*b[k];
        }
    }

    //printing the matrix
    printf("\nThe Diagonal Matrix is :\n\n");
    for(i=1;i<=n;i++){printf("A[%d]\t\t",i);}
    printf("b\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f\t", a[i][j]);
        }
        printf("%f\n",b[i]);
    }

    printf("\nThe Solutions Are:\n\n");
    for(i=1;i<=n;i++){printf("%f\t",b[i]/a[i][i]);}
    printf("\n------------------------------------------\n");

    return 0;
}

