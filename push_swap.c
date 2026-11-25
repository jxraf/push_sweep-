/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:29:25 by moait-mo          #+#    #+#             */
/*   Updated: 2026/11/25 16:58:21 by moait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_flags(char *s)
{
	if (!ft_strncmp(s, "--simple", 8))
		return (0);
	else if (!ft_strncmp(s, "--medium", 8))
		return (1);
	else if (!ft_strncmp(s, "--complex",9))
		return (2);
	else if (!ft_strncmp(s, "--adaptive",10))
		return (3);
	else
		return (3);
}
int	check_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (!ft_isdigit(c[i]))
				return (0);
			j++;
		}
	}
	return (1);
}
// kolshi imshi l check_arg(fill_stack)
t_list	fill_stack(char **arg)
{
 	char 	**arr;
        int	i;
	int	j;
        t_list	*stack;
        t_list	*new;
	int	n;

        stack = NULL;
        i = 0;
        while (arg[i] != NULL)
        {
		arr = ft_split(arg[i], ' ');
         	j = 0;
	  	while (arr[j])
	       {
		       n = ft_atoi(arr[j]);
			new = ft_lstnew(&n);
        	        ft_lstadd_back(&stack, new);
			j++;
	       }
		i++;
	}        
		return (stack);
}
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	enum flags {simple, medium, complex, adaptive, none};
	enum flags flag;

	i = 1
	flag = check_flags(argv[i]);
	if (flag != none)
		i ++;
	stack = fill_stack();
	if (flag == simple)
		//do somthine;
	else if (flag == medium)
		//do medium
	else if (flag == complex)
		//do coplex
	else if (flag == adaptive || flag == none)
		// do adaptive 
		

		printf ("%d", flag);
}
