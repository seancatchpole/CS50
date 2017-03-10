#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int Height; 
    do
    {
        printf("Height:");
        Height = get_int();
    }
   while (Height<0||Height>23);
   
   int dh = Height;
    for(int i = 0; i<(Height); i++)
        {

        for (int i2 = 0; i2<(dh-1); i2++)
            {
                printf(" ");
            }
        for (int i2 = 0; i2<=i; i2++)
            {
                printf("#");
            }

        printf("  ");

        for (int i2 = 0; i2<=i; i2++)
            {
                printf("#");
            }

        printf("\n");
        
        dh--; 
        
        }

}
