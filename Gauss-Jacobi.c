#include<stdio.h>
#include<math.h>

float max(float num[], int size)
{
    int i;
    float max;
    max=num[1];

    for(i=2; i<size; i++){
        if(num[i] > max)
            max=num[i];
        }
    return max;
}

int main(){
    int n, i, j, k;
    printf("Enter order of the Square Matrix:\n");
    scanf("%d", &n);
    float a[n+1][n+1], b[n+1], x[n+1], y[n+1],d[n+1], s, e;
    printf("Enter epsilon: \n");
    scanf("%f", &e);

    //taking the matrix as the input
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("Enter A[%d][%d]: \n", i, j);
            scanf("%f", &a[i][j]);
        }
        printf("Enter b[%d]: \n", i);
        scanf("%f", &b[i]);
        x[i] = 0;
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
    printf("\nk\t");
    for(i=1;i<=n;i++){printf("x[%d]\t\t",i);}
    k = 1;


    //iterative steps
    do{
        for(i=1;i<=n;i++){
            s = b[i];
            for(j=1;j<=n;j++){
                if(i == j)
                    continue;
                s -= a[i][j]*x[j];
            }
            y[i] = s/a[i][i];
            d[i] = fabs(x[i]-y[i]);
        }
        printf("\n%d",k);
        for(i=1;i<=n;i++){
            printf("\t%f",x[i]);
            x[i] = y[i];
        }
        k++;
    }while(max(d,n+1) > e);

    //printing the solutions
    printf("\n\nThe Solutions Are: \n\n");
    for(i=1;i<=n;i++){
        printf("\tx[%d] = %f\t",i,y[i]);
    }
    printf("\n\n-------------------------------------\n");

    return 0;
}
