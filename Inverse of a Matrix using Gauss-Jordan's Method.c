#include<stdio.h>

int main(){
    int n, i, j, k;
    printf("Enter the size of the Square Matrix:\n");
    scanf("%d", &n);
    float a[n+1][n+1], In[n+1][n+1];

    //taking the matrix as the input
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("Enter A[%d][%d]\n", i, j);
            scanf("%f", &a[i][j]);
            if(i==j)
                In[i][j] = 1;
            else
                In[i][j] = 0;
        }
    }

    //printing the matrix
    printf("\nThe Augmented Matrix is :\n\n");
    for(i=1;i<=2*n;i++){printf("A[%d]\t\t",i);}
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f\t", a[i][j]);
        }
        for(j=n+1;j<=2*n;j++){
            printf("%f\t", In[i][j-n]);
        }
        printf("\n");
    }

    //diagonalization
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            if(i==k)
                continue;
            float m = - a[i][k]/a[k][k];
            for(j=1;j<=n;j++){
                a[i][j] += m*a[k][j];
                In[i][j] += m*In[k][j];
            }
        }
    }

    //printing the matrix
    printf("\nThe Diagonal Matrix is :\n\n");
    for(i=1;i<=2*n;i++){printf("A[%d]\t\t",i);}
    printf("\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f\t", a[i][j]);
        }
        for(j=n+1;j<=2*n;j++){
            printf("%f\t", In[i][j-n]);
        }
        printf("\n");
    }

    printf("\nThe Inverse Matrix Is: \n\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%f\t",In[i][j]/a[i][i]);
        }
        printf("\n");
    }

    printf("\n------------------------------------------\n");

    return 0;
}


