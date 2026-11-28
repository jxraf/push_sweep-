/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 11:55:10 by moait-mo          #+#    #+#             */
/*   Updated: 2026/11/28 06:16:09 by moait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	pb(t_list **stacka, t_list **stackb)
{
	t_list *tmp;

	tmp = NULL;
	if (*stacka)
		tmp = (*stacka)->next;
	ft_lstadd_front(stackb, *stacka);
	*stacka = tmp;

}

void	sb(t_list **stackb)
{
	t_list	*tmp;
	t_list	*top_element;
	if (*stackb == NULL || (*stackb)->next == NULL)
		return ;
	tmp = (*stackb)->next;
	(*stackb)->next = (*stackb)->next->next;
	tmp->next= *stackb;
	*stackb = tmp;
}

void	rrb(t_list **stackb)
{
	t_list	*befor_last;
	t_list	*last;

	befor_last = *stackb;
	last = ft_lstlast(*stackb);
	while (befor_last->next->next)
		befor_last = befor_last->next;
	last->next = *stackb;
    	*stackb = last;
	befor_last->next = NULL;
}

void	rb(t_list **stackb)
{
	t_list	*last;

	last = ft_lstlast(*stackb);
	last->next = *stackb;
	*stackb = (*stackb)->next;
	last->next->next = NULL;
}

#include <stdio.h>
void	print_stacks(t_list *a, t_list *b)
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
/*
int	main(void )
{
	t_list	*stackb;
	t_list	*stacka;
	int	i;

	stackb = NULL;
	stacka = NULL;
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
	print_stacks(stacka, stackb);

	sb(&stacka);
	print_stacks(stacka, stackb);

	pb(&stacka, &stackb);
	pb(&stacka, &stackb);
	pb(&stacka, &stackb);
	print_stacks(stacka, stackb);

	rb(&stacka);
	rb(&stackb);
	print_stacks(stacka, stackb);

	rrb(&stacka);
	rrb(&stackb);
	print_stacks(stacka, stackb);

	sb(&stacka);
	print_stacks(stacka, stackb);
	
	pb(&stackb, &stacka);
	pb(&stackb, &stacka);
	pb(&stackb, &stacka);
	print_stacks(stacka, stackb);

}*/
