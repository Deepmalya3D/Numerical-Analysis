#include<stdio.h>
#include<math.h>

//numerically maximum value of a row vector
float max(float num[], int size)
{
    int i;
    float max;
    max=fabs(num[1]);

    for(i=2; i<size; i++){
        if(fabs(num[i]) > max)
            max=fabs(num[i]);
        }
    return max;
}

//function to print the matrix
void print_mat(int n, float mat[n][n]){
    int i,j;
    for(i=1;i<=n-1;i++){
        printf("\n");
        for(j=1;j<=n-1;j++){
            printf("%f ", mat[i][j]);
        }
    }
}

int main(){
    int i, j, n, k=1;
    printf("Enter Order of The Matrix: \n");
    scanf("%d", &n);
    float a[n+1][n+1], x[n+1], x_n[n+1], d[n+1];
    float s, lambda, e, m;
    printf("Enter Tolerable Error: \n");
    scanf("%f", &e);

    //taking the matrix as user input
    printf("Enter elements of Matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("a[%d][%d]= \n",i,j);
            scanf("%f", &a[i][j]);
        }
    }

    //printing the matrix
    printf("\nThe Matrix: \n");
    print_mat(n+1, a);

    //taking the initial vector
    printf("\n\nEnter Initial Guess Vector:\n");
    for(i=1;i<=n;i++){
        printf("x[%d]= \n",i);
        scanf("%f", &x[i]);
    }

	printf("\nstep");
	for(i=1;i<=n;i++){printf("\tx[%d]\t",i);}
	printf("\tlambda\n");
	printf("-------------------------------------------------------------------\n");

    do{
        //calculating Y = AX and new vector
        for(i=1;i<=n;i++){
            s = 0;
            for(j=1;j<=n;j++){
                s += a[i][j]*x[j];
            }
            x_n[i] = s;
        }

        lambda = max(x_n, n+1);
        //normalizing the vector
        for(i=1;i<=n;i++){
            x_n[i] = x_n[i]/lambda;
        }

        //calculating difference between new and old vectors
        for(i=1;i<=n;i++){
            d[i]=fabs(x[i]-x_n[i]);
        }

        //printing the iterations
        printf("\n%d", k);
        for(i=1;i<=n;i++){printf("\t%f",x_n[i]);}
        printf("\t%f", lambda);
        k++;

        m = max(d, n+1);
        for(i=1;i<=n;i++){
            x[i]=x_n[i];
        }
	 }while(m>=e);

	 printf("\n\nThe Dominant Eigen Value is = %f\n",lambda);
	 printf("\nThe Eigen Vector: \n\n");
	 for(i=1;i<=n;i++){
        printf("%f\n", x_n[i]);
	 }
	 printf("---------------------------------------------------\n");
	 return(0);
}
