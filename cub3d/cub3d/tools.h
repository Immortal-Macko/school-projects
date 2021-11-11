#ifndef TOOLS_H
# define TOOLS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_to_int(char *str);
void				ft_error(int flag);
void				*ft_calloc(size_t num, size_t size);
void				ft_putstr_fd(char *s, int fd);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *node);
void				ft_lstadd_back(t_list **lst, t_list *node);
void				ft_bzero(void *s, size_t n);

#endif
