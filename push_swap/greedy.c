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
    combined_rotations(a, b);
    individual_rotations(a, b);
}
t_costs push_cost_b(t_stack **a, t_stack **b, int value_to_push)
{
    t_costs result;
    int a_idx_for_value;
    int b_target_idx;

    a_idx_for_value = find_index(a, value_to_push);
    b_target_idx = find_target_index_b(b, value_to_push);
    result.a_rot_cost = rotation_cost(a, a_idx_for_value);
    result.b_rot_cost = rotation_cost(b, b_target_idx);

    if ((result.a_rot_cost > 0 && result.b_rot_cost > 0) || (result.a_rot_cost < 0 && result.b_rot_cost < 0))
    {
        if (abs(result.a_rot_cost) > abs(result.b_rot_cost))
            result.total_cost = abs(result.a_rot_cost);
        else
            result.total_cost = abs(result.b_rot_cost);
    }
    else
    {
        result.total_cost = abs(result.a_rot_cost) + abs(result.b_rot_cost);
    }
    return (result);
}
t_costs push_cost_a(t_stack **a, t_stack **b, int value_to_push)
{
    t_costs result;
    int b_idx_for_value;
    int a_target_idx;

    b_idx_for_value = find_index(b, value_to_push);
    a_target_idx = find_target_index_a(a, value_to_push);
    result.a_rot_cost = rotation_cost(a, a_target_idx);
    result.b_rot_cost = rotation_cost(b, b_idx_for_value);

    if ((result.a_rot_cost > 0 && result.b_rot_cost > 0) || (result.a_rot_cost < 0 && result.b_rot_cost < 0))
    {
        if (abs(result.a_rot_cost) > abs(result.b_rot_cost))
            result.total_cost = abs(result.a_rot_cost);
        else
            result.total_cost = abs(result.b_rot_cost);
    }
    else
    {
        result.total_cost = abs(result.a_rot_cost) + abs(result.b_rot_cost);
    }
    return (result);
}
void greedy_insert_b(t_stack **a, t_stack **b)
{
    t_stack             *current_a_node;
    int                 min_total_cost;
    int                 best_a_rot_cost; 
    int                 best_b_rot_cost;
    t_costs  current_costs;

    min_total_cost = INT_MAX;
    best_a_rot_cost = 0;
    best_b_rot_cost = 0;
    current_a_node = *a; 
    while (current_a_node)
    {
        current_costs = push_cost_b(a, b, current_a_node->value);        
        if (current_costs.total_cost < min_total_cost)
        {
            min_total_cost = current_costs.total_cost;
            best_a_rot_cost = current_costs.a_rot_cost;
            best_b_rot_cost = current_costs.b_rot_cost;
        }
        current_a_node = current_a_node->next;
    }
    if (*a)
        (*a)->cost = best_a_rot_cost;
    if (*b)
        (*b)->cost = best_b_rot_cost;
    run_cmd(a, b);
    pb(a, b);      
}

void greedy_insert_a(t_stack **a, t_stack **b)
{
    t_stack             *current_b_node;
    int                 min_total_cost;
    int                 best_a_rot_cost;
    int                 best_b_rot_cost;
    t_costs  current_costs;

    min_total_cost = INT_MAX;
    best_a_rot_cost = 0;
    best_b_rot_cost = 0;
    current_b_node = *b;
    while (current_b_node)
    {
        current_costs = push_cost_a(a, b, current_b_node->value);
        
        if (current_costs.total_cost < min_total_cost)
        {
            min_total_cost = current_costs.total_cost;
            best_a_rot_cost = current_costs.a_rot_cost;
            best_b_rot_cost = current_costs.b_rot_cost;
        }
        current_b_node = current_b_node->next;
    }
    if (*a)
        (*a)->cost = best_a_rot_cost;
    if (*b)
        (*b)->cost = best_b_rot_cost;
    run_cmd(a, b);
    pa(a, b);
}