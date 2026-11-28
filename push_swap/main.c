#include "libft.h"
#include <stdio.h>

t_list  *fill_stack(char **arg)
{
        char **arr;
        int i;
        t_list  *stack;
        t_list  *new;

        stack = NULL;
        i = 0;
	int j = 0;
        while (arg[i] != NULL)
        {
		arr = ft_split(arg[i], ' ');
         j = 0;
	  	while (arr[j])
	       {
		new = ft_lstnew(arr[j]);
                ft_lstadd_back(&stack, new);
		j++;
	       }
	       	i++;
	}        

		return (stack);
}

int	main (void )
{
	t_list	*stack;
	char *argv[] = {"1 3 42", "12 44", "77", NULL};

	stack = NULL;
	stack = fill_stack(argv);
	while (stack != NULL)
	{
		printf("%s",(char*)stack->content);
		printf ("\n");
		stack = stack->next;
	}
}

