#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *lptr;

	if ((*lst) && new)
	{
		lptr = *lst;
		while (lptr)
		{
			if (lptr->next == NULL)
				break ;
			lptr = lptr->next;
		}
		lptr->next = new;
	}
	else if (!(*lst) && new)
		ft_lstadd_front(lst, new);
}
