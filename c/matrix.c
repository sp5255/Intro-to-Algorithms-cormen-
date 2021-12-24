#include<stdio.h>
#include<malloc.h>
int ** mul(int r1, int c1, int **mat1 , int r2, int c2, int **mat2){
   int **arr, sum =0;
   arr = (int **)malloc(r1 * sizeof(int *));
   for (int i = 0; i < r1; i++){
       arr[i] = (int *)malloc(c2 * sizeof(int));
   }

       for (int i = 0; i < r1; i++)
       {
           for (int j = 0; j < c2; j++)
           {
               sum = 0;
               for (int k = 0; k < r2; k++)
               {
                   sum += mat1[i][k] * mat2[k][j];
               }
               arr[i][j] = sum;
           }
       }
   return arr;
}
int main(){
    int r, c, **arr, r1,c1,**mat ,**res,**final,r2,c2,**third;
    printf("Enter r, c\n");
    scanf("%d %d", &r,& c);
    arr = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++){
        arr[i] = (int *)malloc(c * sizeof(int));        
        for (int j = 0; j < c; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("enter r1,c1\n");
    scanf("%d %d", &r1, &c1);
    mat = (int **)malloc(r1 * sizeof(int *));
    for (int i = 0; i < r1; i++){
        mat[i] = (int *)malloc(c1 * sizeof(int));
        for (int j = 0; j < c1; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("mat1 : \n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
    printf("mat2 : \n");
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    /* mul(r, c, arr, r1, c1, mat); */
    res = mul(r, c, arr, r1, c1, mat);

        printf("res : \n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c1; j++){
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < r1; i++){
        free((void *)mat[i]);
    }

    for (int i = 0; i < r; i++)
    {
        free((void *)arr[i]);
    }
    free((void *)arr);


    printf("r2, c2\n");
    scanf("%d %d", &r2, &c2);

    third = (int **)malloc(r2 * sizeof(int *));
    
    for (int i = 0; i < r2; i++){
        third[i] = (int *)malloc(c2 * sizeof(int));
        for (int j = 0; j < c2; j++){
            scanf("%d", &third[i][j]);
        }
    }

    final = mul(r, c2, res, r2, c2, third);
      printf("final : \n");
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c2; j++){
            printf("%d\t", final[i][j]);
        }
        printf("\n");
    }
}