#include "push_swap.h"



static void partition(t_stack *a, t_stack *b, int len, int *pushed, int *rotations)
{
    int count;
    int pivot;
    
    pivot = get_pivot(a, len);
    count = len;
    while (count--)
    {
        if (a->top->value <= pivot)
        {
            pb(&a, &b);
            (*pushed)++;
        }
        else
        {
            ra(a);
            (*rotations)++;
        }
    }
}

static void quick_rotations(t_stack *a, int len, int rotations)
{
    int j;

    if (rotations <= len / 2)
    {
        while (rotations--)
            rra(a);
    }
    else
    { 
        j = len - rotations;
        while (j--)
            ra(a);
    }
}

void quicksort(t_stack *a, t_stack *b, int len)
{
    int pivot; 
    int pushed;
    int rotations;

    if (len <= 1 || is_sorted(a))
        return;
    pivot = get_pivot(a, len);
    pushed = 0;
    rotations = 0;
    partition(a, b, len, &pushed, &rotations);
    quick_rotations(a, len, rotations);
    quicksort(a, b, len - pushed);
    if (pushed <= 3)
        sort_small(b);
    else
        quicksort(b, a, pushed);
    
    while (pushed--)
        pa(&a, &b);
}

// void quicksort(t_stack *a, t_stack *b, int len)
// {
//     if (len <= 1 || is_sorted(a))
//         return;
//     int pivot; 
//     int pushed;
//     int rotations;
//     int count;make 
//     int j;

//     pivot = = get_pivot(a, len);
//     pushed = 0;
//     rotations = 0;
//     count = len;
//     while (count--)
//     {
//         if (a->top->value <= pivot)
//         {
//             pb(&a, &b);
//             pushed++;
//         }
//         else
//         {
//             ra(a);
//             rotations++;
//         }
//     }
//     if (rotations <= len / 2)
//         while (rotations--)
//             rra(a);
//     else
//     { 
//         j = len -rotations;
//         while (j--)
//             ra(a);
//     }
//     quicksort(a, b, len - pushed);
//     if (pushed <= 3)
//         sort_small_stack(b);
//     else
//         quicksort(b, a, pushed);
//     while (pushed--)
//         pa(&a, &b);
// }



// int ascending(int a, int b) {
//     return (a > b);
// }

// t_node *create_node(int value)
// {
//     t_node *new_node = (t_node *)malloc(sizeof(t_node));
//     if (!new_node)
//         return ;
//     new_node->value = value;
//     new_node->next = NULL;
//     return (new_node);
// }
// t_stack *stack_copy(t_stack *a)
// {
//     if (!a)
//         return (NULL);
//     t_stack *copy = stack_create();
//     if (!copy)
//         return (NULL);
//     t_node *current = a->top;
//     while (current)
//     {
//         stack_init(copy, current->value);
//         current = current->next;
//     }
//     return (copy);
// }

// void	ft_swap(int *a, int *b)
// {
// 	int	tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

// t_node	*sort_list(t_node *lst, int (*cmp)(int, int))
// {
// 	if (!lst || !lst->next)
//         return (lst);
//     t_node	*tmp;

// 	tmp = lst;
// 	while (lst->next != NULL)
// 	{
// 		if (((*cmp)(lst->value, lst->next->value)) == 0)
// 		{
// 			ft_swap(&lst->value, &lst->next->value);
// 			lst = tmp;
// 		}
// 		else
// 			lst = lst->next;
// 	}
// 	lst = tmp;
// 	return (lst);
// }

// int get_pivot(t_stack *a, int c)
// {
//     if (!a | !a->top) 
//         return (0);
//     int pivot;
//     int len = stack_size(a);
//     t_stack *copy = stack_copy(a);
//     copy->top = sort_list(copy->top, ascending);
//     t_node *current = copy->top;
//     int i;
//     if (c == 1)
//     {   
//         i = 0;
//         while (i < (len / 3) && copy)
//         {
//            current = current->next;
//            i++;
//         }
//         if (copy)
//             pivot = current->value; 
//     }
//     if (c == 2)
//     {
//          i = 0;
//         while (i < (len / 3 * 2) && copy)
//         {
//            current = current->next;
//            i++;
//         }
//         if (copy)
//             pivot = current->value;
//     }
//     return (pivot);
// }

// void quicksort(t_stack *a, t_stack *b, int len)
// {
//     if (len <= 1 || is_sorted(a))
//         return;
//     int pivot_big = get_pivot(a, 1);
//     int pivot_small = get_pivot(a, 2);
//     int pushed_big = 0;
//     int pushed_small = 0;
//     int middle = 0;
       
//     while (len-- > 0)
//     {
//         if (a->top->value < pivot_small) 
//         {
//             pb(&a, &b);
//             pushed_small++;
//         }
//         else if (a->top->value > pivot_big)
//         {
//             pb(&a, &b);
//             rb(b);
//             pushed_big++;
//         }
//         else
//         {
//             ra(a);
//             middle++;
//         }
//     }
//     while (middle--)
//         rra(a);
//     quicksort(a, b, middle);
//     quicksort(b, a, pushed_small);
//     while (pushed_small--)
//         pa(&a, &b);
//     quicksort(b, a, pushed_big);
//     while (pushed_big--)
//         pa(&a, &b);
// }
