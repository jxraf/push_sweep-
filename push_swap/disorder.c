/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 12:02:23 by moait-mo          #+#    #+#             */
/*   Updated: 2026/11/28 17:55:56 by moait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	*stack_to_arr(t_list *a, int stack_size)
{
	int	i;
	int	*arr;

	i = 0;
	 arr = malloc(stack_size * sizeof(int));
	 if (arr == NULL)
		 return (NULL);
	 while (a)
	 {
		 arr[i] = *((int *)(a->content));
		 i ++;
		 a = a->next;
	 }
	 return (arr);
}

double	compute_disorder(t_list *a)
{
	 float	mistakes;
	 float	total_pairs;
	 int	i;
	 int	j;
	 size_t	stack_size;
	 int	*arr;

	 mistakes = 0;
	 i = 0;
	 total_pairs = 0;
	 stack_size = ft_lstsize(a);
	 arr = stack_to_arr(a, stack_size);
	 while (i < stack_size)
	 {
		 j = i + 1;
		 while (j < stack_size)
		 {
			 total_pairs ++;
			 if (arr[i] > arr[j])
				 mistakes += 1;
			 j ++;
		 }
		 i ++;
	 }
	 return (mistakes / total_pairs);
}

#include <stdio.h>
void    print_stacks(t_list *a, t_list *b)
{
        while (a || b)
        {
                if (a)
                {
                        printf("%d  ", *((int *)a->content));
                        a = a->next;
                }
                if (b)
                {
                        printf("%d", *((int *)b->content));
                        b = b->next;
                }
                printf("\n");
        }
        printf ("_  _\na  b\n--------------\n");
}

int	main (void )
{
	 t_list  *stacka;
	int i;

	 i = 5;
        int a[6] = {2, 1, 3, 6, 5, 8};
        t_list *new = ft_lstnew(&a[i]);
        stacka = new;
        i --;
        while (i >= 0)
        {
                new = ft_lstnew(&a[i]);
                ft_lstadd_front(&stacka,new);
                i --;
        }
	print_stacks(stacka, stacka);
	float disorder = compute_disorder(stacka);

	printf ("%f", disorder);
}
