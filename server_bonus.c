#include "header.h"


//void check_bit(int sig)
//{
//	static unsigned int	i;
//	static int bin[8];
//	static char tab[999999999999];
//	static unsigned int j;
//	static unsigned int k;
//
//	if (sig == SIGUSR1)
//		bin[i] = 1;
//	else
//		bin[i] = 0;
//	i++;
//	if (i == 8)
//	{
//		i = 0;
//		tab[j] = convert_dicimal(bin);
//		if (tab[j] == '\0')
//		{
//			while (j > k)
//			{
//				ft_putchar(tab[k++]);
//				//write(1, "lolo \n", 7);
//			}
//		}
//		j++;
//	}
//}
//
//int	convert_dicimal(int *bin)
//{
//	int i;
//	//char *tab_dec;
//	unsigned int base;
//	unsigned int dec;
//
//	base =1;
//	dec = 0;
//	i = 7;
//	 while ( i > 0)  
//    {
//        dec = dec + bin[i] * base;
//        base = base * 2;
//		i--;
//	}
//	//printf("dec = %c \n", dec);
//	return (dec);
//}



void check_bit(int sig)
{
	static int	dec;
	static int i;
	static int j;
	static int	base = 1;
	static unsigned char tab[999999999999];
	//unsigned char c;
	static int k;
	if (sig == SIGUSR1)
	{
		//ft_putchar('1');
		dec = dec + base;
		i++;
	}
	else
	{
		//ft_putchar('0');
		i++;
	}
	base = base * 2;
	//ft_putnbr(dec);
	//ft_putchar('\n');
// 
	if (i == 8)
	{
		tab[j] = dec;
		//ft_putchar(dec);
		if (dec == 0)
		{
			while (j > k)
			{
				ft_putchar(tab[k]);
				k++;
			}
		}
			
		j++;
		base = 1;
		dec = 0;
		i = 0;
	}
}

//void	check_bit(int i)
//{
//	static char	buffer[100000000];
//	static int	counter = 0;
//	static int	bit = 7;
//
//	if (i == SIGUSR1)
//	{
//		buffer[counter] |= (1 << bit);
//			write(1, "1", 1);
//	}
//	if (i == SIGUSR2)
//		{
//		buffer[counter] &= ~(1 << bit);
//			write(1, "0", 1);
//		}
//	bit--;
//	if (bit == -1)
//	{
//		bit = 7;
//		if (buffer[counter] == '\0')
//		{
//			write(1, buffer, counter);
//			counter = 0;
//		}
//		else
//		{
//			counter++;
//		}
//	}
//}

int main()
{
	write (1, "My PID it's =     ", 19);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, check_bit);
	signal(SIGUSR2, check_bit);
	//ft_catch();
	while (1)
		pause();
}
 