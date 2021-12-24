#include<stdio.h>
int fact(int n);
int main(){
    int n;
     int res;
    printf("Enter a number \n");
    scanf("%d", &n);
    res = fact(n);
    //res = res % 10000007;
    printf("factorial : %d \n",res);
}
int fact(int n){
    if(n == 1)
    return 1;
    return n*fact(n-1);
}