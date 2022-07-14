#include<stdio.h>
#include<math.h>


int main(){
    int n,i,j,m;
    printf("Enter the number of points:\n");
    scanf("%d",&n);
    float d[n][n+1], x, h, s, v, y;

    //input USER data
    for(i = 0; i<n; i++){
        printf("Enter x[%d]: \n", i+1);
        scanf("%f", &d[i][0]);
        printf("Enter y[%d]: \n", i+1);
        scanf("%f", &d[i][1]);
    }
    printf("Enter x: \n");
    scanf("%f", &x);

    h = d[1][0]-d[0][0];
    s = d[n-1][1];
    v = (x-d[n-1][0])/h;

    //calculating coefficients
    m = 0;
    for(j=2;j<=n;j++){
        for(i = n-1; i>m; i--){
            d[i][j] = d[i][j-1] - d[i-1][j-1];
        }
        m++;
    }

    //column names
    printf("\n\nx\t\ty\t\t");
    for(i=1;i<=n-1;i++){
        printf("d%dy\t\t",i);
    }

    //printing the table
    for(i = 0; i<n; i++){
        printf("\n");
        for(j=0;j<=n;j++){
            printf("%.6f\t", d[i][j]);
            if(i+1 == j){
                break;
            }
        }
    }

    //calculating the estimated value
    y = v;
    for(i=1;i<n;i++){
        s += y*d[n-1][i+1];
        y *= (v+i)/(i+1);

    }
    printf("\n\nThe required value of y at given x is = %.6f\n", s);
    printf("----------------------------------------------\n");
    return 0;
}

