#include<stdio.h>
void function(char **ptr);
int main()
{
    char *arr[] = {"one", "two", "three", "four"};
    for (int i = 0; i < 4; i++){
        printf("%d \t", arr[i]);
    }
    printf("%d \n", *arr);
        function(arr);
    return 0;
}
void function(char **ptr){ // **ptr = *arr, *ptr = arr,*(base_address+1)
    char *ptr1;
    //printf("ptr : %d\n ptr[1] : %s", ptr,*(ptr+1)); 

    ptr1 = (ptr += sizeof(int))[-3];        // (ptr += 4)[-3], (ptr = ptr+4)[-3] , ptr = ptr + 1 which is address of two
    printf("%s\n", ptr1);
    
}