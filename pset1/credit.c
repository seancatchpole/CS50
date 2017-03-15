#include <cs50.h>
#include <stdio.h>


long long digit(long long n, long long credit);
long long expon(long long x, long long y);
int luhn(int *cr_a);

int main(void)
	{
	long long cr;
    printf("Number:");
    cr = get_long_long();

		int cr_a[16];
		for (int i = 0; i < 16; i++)
			{
				long long d;
				d = digit((i+1),cr);
				cr_a[i] = (int)d;
				//				printf("Element[%i] = %i\n", i, cr_a[i] );
			}
	if (luhn(cr_a) == 1)
		{
			if ((cr_a[15] == 0) && (cr_a[14] == 3))
				{
					printf("AMEX\n");
				}
			else if ((cr_a[15] == 5) && (cr_a[14] == 1 || cr_a[14] == 2 || cr_a[14] == 3 || cr_a[14] == 4 || cr_a[14] == 5))
				{
					printf("MASTERCARD\n");
				}
			else  if (cr_a[15] == 4 || (cr_a[15] == 0 && cr_a[14] == 0 && cr_a[13] == 0 && cr_a[12] == 4))
				{
					printf("VISA\n");
				}
			else
				{
					printf("INVALID\n");
				}
		}
		else
			{
				printf("INVALID\n");
			}
	}


int luhn(int *cra)
	{
//-----------------------------------------------------------
	
		for (int j2 = 0; j2 < 16; j2++ ) 
		{
	//		 printf("Element[%d] = %d\n", j2, cra[j2] );
		}
	//	printf("\n");
	int even[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int odd = 0;
	for (int i = 0; i < 16; )
		{
		//	int j = 1;
			if (cra[i+1] > 4)
				{
					even[i]=1;
					even[i+1]=((2*cra[i+1])%10);
				//	printf("Element[%i] = %i\n", i, even[i] );
				//	printf("Element[%i] = %i\n", i+1, even[i+1] );
			//	printf("IF\n");
				i = i + 2;
				}
			else
				{
					even[i] = ((cra[i+1])*2);
				//	even[i+1] = 0;
				//	for (int j2 = 0; j2 < 16; j2++ ) 
				//		{
				//			 printf("Element[%d] = %d\n", j2, even[j2] );
				//		}
			//	printf("ELSE\n");
				i = i + 2;
				}
			
		} 

//-------------------------------------------------------
/*
		do 
		{
			int i = 0;
			int j = 1;
			if ((cra[j]*2) > 9 )
				{
					even[i]=((2*cra[j])/10);
					even[i+1]=((2*cra[j])%10);
					printf("Element[%i] = %i\n", i, even[i] );
					printf("Element[%i] = %i\n", i+1, even[i+1] );
				}
			else
				{
					even[i] = ((cra[j])*2);
					even[i+1] = 0;
				}
			j = j + 2;
			i=i+2;
		} 
				while(i<16);
*/
//----------------------------------------------------------

				
		for (int j = 0; j < 16; j++ ) {
    //   printf("Element[%d] = %d\n", j, even[j] );
    }
		int es = 0;
		for (int i = 0; i < 16; i++)
			{
				es = es + even[i];
			//printf("EVEN: %i, %i\n", es, i);
			}
			//printf("EVEN: %i\n", es);
	for (int i = 0; i < 16; i=i+2)
		{
			odd = odd + cra[i];
		}
	//	printf("ODD: %i\n", odd);
		int sum = 0;
		sum = es + odd;
	//	printf("SUM: %i\n", sum);
		if (sum%10 == 0) {
			return 1;
		} else {
			return 0;
		}

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
