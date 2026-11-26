#include <stdio.h>
#include "libft.h"

void	sa(t_list *stacka)
{
	t_list *temp;
 	temp = stacka;
	stacka = stacka->next;
	stacka->next = 	temp; 
	ft_lstadd_front(&stacka,temp); 
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

	sa(head);
	t_list *tmp;
	tmp = head;
	while (tmp)
	{
	printf("%s\n",(char *)tmp->content);
		tmp = tmp->next;
	}
//	printf("%s",(char *)head->content);
}
