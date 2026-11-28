/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:29:25 by moait-mo          #+#    #+#             */
/*   Updated: 2026/11/28 06:38:51 by moait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_flags(char *s)
{
	if (!s)
		return (0);
	if (!ft_strncmp(s, "--simple", 8))
		return (0);
	else if (!ft_strncmp(s, "--medium", 8))
		return (1);
	else if (!ft_strncmp(s, "--complex",9))
		return (2);
	else if (!ft_strncmp(s, "--adaptive",10))
		return (3);
	else
		return (4);
}

int	check_arg(char **argv, int argc)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				sign = 0;
			else if (argv[i][j] == ' ' && sign == 0)
				sign = 0;
			else if (argv[i][j] == '-' && sign == 0)
				sign = 1;
			else if (argv[i][j] == '-' && sign == 1)
				return (1);
			else
				return (1);	
			j++;
		}
		i ++;
	}
	return (0);
}

int	check_duplecate(t_list *stack, size_t size)
{
	int	tmp[size];
	int	i;
	int	j;

	i = 0;
	tmp[i] = *(((int *)stack->content));
	stack = stack->next;
	i ++;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tmp[j] == *((int *)(stack->content)))
				return (1);
			j ++;
		}
		tmp[i] = *(((int *)stack->content));
		stack = stack->next;
		i ++;
	}
	return (0);
}

// kolshi imshi l check_arg(fill_stack)
t_list	*fill_stack(char **arg, int argc)
{
 	char 	**arr;
        int	i;
	int	j;
        t_list	*stack;
        t_list	*new;
	int	*n;

        stack = NULL;
        i = 0;
	if (check_arg(arg, argc))
		return (NULL);
        while (argc > i)
        {
		arr = ft_split(arg[i], ' ');
         	j = 0;
		while (arr[j])
		{
			n = malloc (sizeof(int));
			if (n == NULL)
				return (NULL);
			*n = ft_atoi(arr[j]);
			new = ft_lstnew(n);
        	        ft_lstadd_front(&stack, new);
			j++;
		}
		i++;
	}
	if (check_duplecate(stack, ft_lstsize(stack)))
		return (NULL);
	return (stack);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	enum flags {simple, medium, complex, adaptive, none};
	enum flags flag;
	t_list *stack;

	i = 1;
	flag = check_flags(argv[i]);
	if (flag != none)
		i ++;
	stack = fill_stack(argv + i, argc - i);
//	if (flag == simple)
		//do somthine;
//	else if (flag == medium)
		//do medium
//	else if (flag == complex)
		//do coplex
//	else if (flag == adaptive || flag == none)
		// do adaptive
	if (stack == NULL)
		printf("error");	
	while (stack)
	{
		printf ("%d\n", *((int *)(stack->content)));
		stack = stack->next;
	}
	printf ("%f", compute_disorder(stack));
	return (0);
}
