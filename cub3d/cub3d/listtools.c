#include "tools.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lptr;

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

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst)
	{
		lst->content = content;
		lst->next = NULL;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	if (!lst)
		return (0);
	if (lst->next == NULL)
		return (1);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
