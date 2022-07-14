#include<stdio.h>

//function to print the matrix
void print_mat(int n, float mat[n][n]){
    int i,j;
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%f ", mat[i][j]);
        }
    }
}

//function to get the determinant
float det(int n, float mat[n][n]){
    int i, j, k;
    float r, det = 1;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(j>i){
                r = mat[j][i]/mat[i][i];
                for(k=0; k<n; k++){
                    mat[j][k] -= r * mat[i][k];
                }
            }
        }
    }

    for(i=0; i<n; i++)
        det *= mat[i][i];
    return det;
}

//function to compare the two matrices
int cmp(int n, float mat1[n][n], float mat2[n][n]){
    int i,j,flag = 1;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(mat1[i][j] != mat2[i][j]){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int main(){
    int i,j,n,k;
    printf("Enter The Length of Your Matrix:\n");
    scanf("%d", &n);
    float user_mat[n][n], inv_mat[n][n], model_mat[n][n], det_mat[n][n];

    //Taking The Elements of The Matrix & Making Another Ideal Matrix to Compare
    printf("Enter the elements of your matrix:\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("Enter %dx%d th element:\n", i+1, j+1);
            scanf("%f", &user_mat[i][j]);
            det_mat[i][j] = user_mat[i][j];
            if(i==j){
                model_mat[i][j] = 1;
                inv_mat[i][j] = 1;
            }
            else{
                model_mat[i][j] = 0;
                inv_mat[i][j] = 0;
            }
        }
    }

    //defining b
    float b[n][1];
    printf("\n\n");
    for(i=0;i<n;i++){
        printf("Enter the b[%d]: \n", i+1);
        scanf("%f",&b[i][0]);
    }

    printf("\nThe Following is your matrix:\n");
    print_mat(n, user_mat);
    printf("\n\nb=\n");

    for(i=0;i<n;i++){
        printf("%f\n", b[i][0]);
    }
    printf("\n");

    if(det(n, det_mat) == 0)
        printf("\nSORRY. Invalid Matrix. Determinant is Zero.\n\n");
    else{
        int flag = 0;
        while(cmp(n, user_mat, model_mat) != 1){
            if(user_mat[flag][flag] == 0){
                for(i=flag; i<n; i++){
                    if(user_mat[i][flag] != 0)
                        break;
                }
                for(j=0; j<n; j++){
                    user_mat[flag][j] += user_mat[i][j];
                    inv_mat[flag][j] += inv_mat[i][j];
                }
            }
            //So we're using Augmented Matrix Method. First we reduce the rows by transforming ixi element to 1
            float t = user_mat[flag][flag];
            for(i=0; i<n; i++){
                user_mat[flag][i] = user_mat[flag][i]/t;
                inv_mat[flag][i] = inv_mat[flag][i]/t;
            }

            //next we subtract other elements from that column, and repeat this process until we get RRE matrix
            for(i=0; i<n; i++){
                float x = user_mat[i][flag];
                for(j=0; j<n; j++){
                    if(i == flag)
                        continue;
                    else{
                        user_mat[i][j] += - user_mat[flag][j]*x;
                        inv_mat[i][j] += - inv_mat[flag][j]*x;
                    }
                }
            }
            flag ++;
        }

        printf("\nThe Following Is Your Inverse Matrix:\n");
        print_mat(n, inv_mat);
    }

        printf("\n\nThe Solution: \n");
        float mat3[n][1];
        for(i=0;i<n;i++){
            for(j=0;j<1;j++){
                mat3[i][j] = 0;
                for(k=0;k<n;k++){
                    mat3[i][j] += inv_mat[i][k]*b[k][j];
                }
                printf("x[%d] = %f\n", i+1, mat3[i][j]);
            }
        }
    printf("\n--------------------------------------------------------\n\n");
    return 0;
}
