#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		temp;
	t_list	*lst_save;

	lst_save = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = lst_save;
		}
		else
			lst = lst->next;
	}
	lst = lst_save;
	return (lst);
}
