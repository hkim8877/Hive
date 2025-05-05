#include "libft.h"

int ft_lstsize(t_list *lst)
{
    size_t  list_len;

    list_len = 0;
    while (lst)
    {
        lst = lst->next;
        list_len++;
    }
    return (list_len);
}
