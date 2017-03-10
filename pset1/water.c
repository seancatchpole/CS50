#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int minutes; 
    printf("Minutes:");
    do
    {
        int minutes = get_int();
    }
   while (minutes<1);

   printf("Bottles: %i\n, minutes*6");

}
