#include "push_swap.h"

t_cost calculate_move(t_stack *a, t_stack *b, int value)
{
    t_cost cost;
    cost.b_index = find_index(b, value);
    cost.a_index = find_target_index(a, value);

    cost.a_cost = compute_rotation_cost(a, cost.a_index);
    cost.b_cost = compute_rotation_cost(b, cost.b_index);

    if ((cost.a_cost > 0 && cost.b_cost > 0) || (cost.a_cost < 0 && cost.b_cost < 0))
    {
        if (abs(cost.a_cost) > abs(cost.b_cost))
            cost.push_cost = abs(cost.a_cost);
        else
            cost.push_cost = abs(cost.b_cost);
    }
    else
        cost.push_cost = abs(cost.a_cost) + abs(cost.b_cost);
    return (cost);
}

void run_cmd(t_stack *a, t_stack *b, t_cost cost)
{
    while (cost.a_cost > 0) 
    {
        ra(a);
        cost.a_cost--;
    }
    while (cost.a_cost < 0)
    {
        rra(a);
        cost.a_cost++;
    }
    while (cost.b_cost > 0)
    {
        rb(b);
        cost.b_cost--;
    }
    while (cost.b_cost < 0)
    {
        rrb(b);
        cost.b_cost++;
    }
}

void greedy_insert(t_stack *a, t_stack *b)
{
    t_cost best_move;
    int min_cost;
    
    min_cost = INT_MAX;

    t_node *current = b->top;
    while (current)
    {
        t_cost cost = calculate_move(a, b, current->value);
        if (cost.push_cost < min_cost)
        {
            min_cost = cost.push_cost;
            best_move = cost;
        }
        current = current->next;
    }
    run_cmd(a, b, best_move);
    pa(&a, &b);
}
