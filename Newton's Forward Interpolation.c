#include<stdio.h>
#include<math.h>

int main(){
    int n,i,j,m;
    printf("Enter no of columns in the data:\n");
    scanf("%d",&n);
    float d[n][n+1], x, h, s, u, y;

    //input given data
    for(i = 0; i<n; i++){
        printf("Enter x[%d]: \n", i+1);
        scanf("%f", &d[i][0]);
        printf("Enter y[%d]: \n", i+1);
        scanf("%f", &d[i][1]);
    }
    printf("Enter x: \n");
    scanf("%f", &x);

    h = d[1][0]-d[0][0];
    s = d[0][1];
    u = (x-d[0][0])/h;

    //calculating coefficients
    m = n-1;
    for(j=2;j<=n;j++){
        for(i = 0; i<m; i++){
            d[i][j] = d[i+1][j-1] - d[i][j-1];
        }
        m--;
    }

    //column names
    printf("\nx\ty\t");
    for(i=1;i<=n-1;i++){
        printf("d%dy\t",i);
    }

    //printing the table
    for(i = 0; i<n; i++){
        printf("\n");
        for(j=0;j<=n;j++){
            printf("%.4f\t", d[i][j]);
            if(i+j==n){
                break;
            }
        }
    }

    //calculating the estimated value
    y = u;
    for(i=1;i<n;i++){
        s += y*d[0][i+1];
        y *= (u-i)/(i+1);

    }
    printf("\nRequired value: %.4f\n", s);
    return 0;
}
