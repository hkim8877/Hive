#include "push_swap.h"

static void combined_rotations(t_stack **a, t_stack **b)
{
    while ((*a)->cost > 0 && (*b)->cost > 0)
    {
        rr(a, b);
        (*a)->cost--;
        (*b)->cost--;
    }
    while ((*a)->cost < 0 && (*b)->cost < 0)
    {
        rrr(a, b);
        (*a)->cost++;
        (*b)->cost++;
    }
}
static void individual_rotations(t_stack **a, t_stack **b)
{
    while ((*a)->cost > 0)
    {
        ra(a);
        (*a)->cost--;
    }
    while ((*a)->cost < 0)
    {
        rra(a);
        (*a)->cost++;
    }
    while ((*b)->cost > 0)
    {
        rb(b);
        (*b)->cost--;
    }
    while ((*b)->cost < 0)
    {
        rrb(b);
        (*b)->cost++;
    }
}
void run_cmd(t_stack **a, t_stack **b)
{
    int tmp_a;
    int tmp_b;

    tmp_a = (*a)->cost;
    tmp_b = (*b)->cost;;
    combined_rotations(a, b);
    individual_rotations(a, b);
}
int push_cost(t_stack **a, t_stack **b, int value)
{
    int push_cost;

    (*b)->index = find_index(b, value);
    (*a)->index = find_target_index(a, value);
    (*a)->cost = rotation_cost(a, (*a)->index);
    (*b)->cost = rotation_cost(b, (*b)->index);
    if (((*a)->cost > 0 && (*b)->cost > 0) || ((*a)->cost < 0 && (*b)->cost < 0))
    {
        if (abs((*a)->cost) > abs((*b)->cost))
            push_cost = abs((*a)->cost);
        else
            push_cost = abs((*b)->cost);
    }
    else
        push_cost = abs((*a)->cost) + abs((*b)->cost);
    return (push_cost);
}
void greedy_insert(t_stack **a, t_stack **b)
{
    int best;
    int tmp;
    t_stack *current;
    int min_cost;
    
    min_cost = INT_MAX;
    current = *b;
    while (current)
    {
        tmp = push_cost(&a, &b, current->value);
        if (tmp < min_cost)
        {
            min_cost = tmp;
            best = tmp;
        }
        current = current->next;
    }
    run_cmd(&a, &b);
    pa(a, b);
}