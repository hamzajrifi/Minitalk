#include <stdio.h>  
 
/**
 * C program to convert decimal to binary number system
 */

#include <stdio.h>
#define INT_SIZE sizeof(int) * 8 /* Size of int in bits */

int main(int ac, char **av)
{
    int  index, i;
    int bin[INT_SIZE];
    char num;

    index = INT_SIZE - 1;
    index = 7;
    i = 0;
    while(index >= 0)
    {
     
        bin[index] = av[2][i] & 1;
        index--;
        i++;
        av[2][i] >>= 1;
    }
    index = 0;
    while (index < 8)
    {
       printf("%d", bin[index++]);
    }
}