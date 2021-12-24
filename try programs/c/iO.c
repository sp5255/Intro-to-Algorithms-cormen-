#include<stdio.h>
int main(){
    char ch;
    printf("test getchar \n");
    //printf("ok\n");
    while (ch != '\n')
    {
        ch = getchar();
        /* code */
    }
    //fflush(stdin);
    printf("ch = %c", ch);
}