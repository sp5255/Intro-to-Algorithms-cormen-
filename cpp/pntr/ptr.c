#include<stdio.h>
int main(){
    
    int *a[4] = {5, 32, 54, 64};
    for (int i = 0; i < 4;i++)
        printf("%d\t", &a[i]);
    int *p = &a + 1;                // here &a means address of whole array i.e,address of last element and +1  gives the address of next element to it thats not present

    printf("\n%d", p-1);
}