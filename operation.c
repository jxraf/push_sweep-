#include <stdio.h>
#include "libft.h"

void	sa(t_list *stacka)
{
	
}
int main ()
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew("1");
	t_list *node2= ft_lstnew("2");
	t_list *node3 = ft_lstnew("3");

	head = node1;
	node1->next = node2;
	node2->next = node3;

	t_list *tmp;
	while (tmp)
	{
		printf("%d",(int)tmp->content);
		tmp = head->next;
	}
}
