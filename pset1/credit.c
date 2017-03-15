#include <cs50.h>
#include <stdio.h>


long long digit(long long n, long long credit);
long long expon(long long x, long long y);

int main(void)
	{
	long long cr;
    printf("Number:");
    cr = get_long_long();
		do
		{
 						int i = 0;
						long long d;
						d = digit((i+1),cr);
						int cr_a[i] = (int)d;
						printf("Element[%i] = %i\n", i, cr_a[i] );
						i++;
		}
		while(i>20);

		//printf("%lld\n", d);
    }


//returns nth digit (credit mod 10^(n-1))/(10^(n-2))
long long digit(long long  n, long long credit)
    {
        long long digi;
        if (n>1)
            {
                digi = ((credit%(expon(10,n-1)))/(expon(10,(n-2))));
                //printf("%lld\n", digi);
            }
        else
            {
                digi = credit%(10);
                //printf("%lld\n", digi);
            }
            //printf("%lld\n", digi);
     return digi;
    }


//exponentiation
long long expon(long long x, long long y)
    {
        long long nx = x;
        for(int i = 0; i < y; i++)
            {
                nx = nx*x;
            }
        //printf("%lld\n", nx);
        return nx;
    }
