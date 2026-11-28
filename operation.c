#include <stdio.h>
#include "libft.h"

void	sa(t_list *stacka)
{
	t_list *temp;
	if (!stacka)
		return ;
 	temp = (stacka)->content;
	(stacka)->content = (stacka)->next->content;
	(stacka)->next->content = 	temp; 
}
void pa(t_list **stacka, t_list **stackb)
{
	t_list	*temp;
	if (!stackb)
		return ;
	temp = *stackb;
	*stackb = (*stackb)->next;
	temp->next = *stacka;
	*stacka = temp;
}
void    ra(t_list **stacka)
{
    t_list  *temp;
    t_list  *last;

    if (!stacka)
        return ;
    temp = *stacka;
    *stacka = (*stacka)->next;
    last = *stacka;
    while (last->next)
        last = last->next;
    temp->next = NULL;
    last->next = temp;
}
int main ()
{
	t_list *head2 = NULL;
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
