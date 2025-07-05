#include "push_swap.h"

void greedy_insert(t_stack *a, t_stack *b)
{
    t_cost best;
    t_node *current;
    t_cost cost;
    int min_cost;
    
    min_cost = INT_MAX;
    current = b->top;
    while (current)
    {
        cost = calculate_move(a, b, current->value);
        if (cost.push_cost < min_cost)
        {
            min_cost = cost.push_cost;
            best = cost;
        }
        current = current->next;
    }
    run_cmd(a, b, best);
    pa(&a, &b);
}

t_cost calculate_move(t_stack *a, t_stack *b, int value)
{
    t_cost cost;

    cost.b_index = find_index(b, value);
    cost.a_index = find_target_index(a, value);
    cost.a_cost = rotation_cost(a, cost.a_index);
    cost.b_cost = rotation_cost(b, cost.b_index);
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
    int tmp_a;
    int tmp_b;

    tmp_a = cost.a_cost;
    tmp_b = cost.b_cost;;
    combined_rotations(a, b, &tmp_a, &tmp_b);
    individual_rotations(a, b, tmp_a, tmp_b);
}

void combined_rotations(t_stack *a, t_stack *b, int *a_cost, int *b_cost)
{
    while (*a_cost > 0 && *b_cost > 0)
    {
        rr(a, b);
        (*a_cost)--;
        (*b_cost)--;
    }
    while (*a_cost < 0 && *b_cost < 0)
    {
        rrr(a, b);
        (*a_cost)++;
        (*b_cost)++;
    }
}

void individual_rotations(t_stack *a, t_stack *b, int a_cost, int b_cost)
{
    while (a_cost > 0)
    {
        ra(a);
        a_cost--;
    }
    while (a_cost < 0)
    {
        rra(a);
        a_cost++;
    }
    while (b_cost > 0)
    {
        rb(b);
        b_cost--;
    }
    while (b_cost < 0)
    {
        rrb(b);
        b_cost++;
    }
}

// void run_cmd(t_stack *a, t_stack *b, t_cost cost)
// {
//     while (cost.a_cost > 0) 
//     {
//         ra(a);
//         cost.a_cost--;
//     }
//     while (cost.a_cost < 0)
//     {
//         rra(a);
//         cost.a_cost++;
//     }
//     while (cost.b_cost > 0)
//     {
//         rb(b);
//         cost.b_cost--;
//     }
//     while (cost.b_cost < 0)
//     {
//         rrb(b);
//         cost.b_cost++;
//     }
// }