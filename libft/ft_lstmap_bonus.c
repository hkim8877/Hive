#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *result;
    t_list  *temp;

    if (!lst || !f)
        return (NULL);
    result = ft_lstnew(f(lst->content));
    if (!result)
        return (NULL);
    temp = result;
    lst = lst->next;
    while (lst)
    {
        temp->next = ft_lstnew(f(lst->content))
        if (!temp->next)
        {
            ft_lstclear(&result, del);
            return (NULL);
        }
        temp = temp->next;
        lst = lst->next;
    }
    return (result);
}
