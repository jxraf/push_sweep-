#include "libft.h" 
#include <stdio.h>
int check_arg(char **argv, int argc)
{
	int i = 1;
	int j = 0;
	int sign = 0;
	while (i < argc - 1)
	{
		while(argv[i][j])
		{
		if (argv[i][j] == ' ')
		{
			j++;
			sign = 0;
		}
		else if ((argv[i][j] == '-' || argv[i][j] == '+') && sign == 0)
		{
			j++;
			sign = 1;
		}
		else if (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			j++;
			sign = 0;
		}
		else
			return (0);
		}
		i++;
		sign = 0;
	}
	return (1);
}
int main (int argc, char **argv)
{
 printf("%d \n",check_arg(argv, argc));
	
}
