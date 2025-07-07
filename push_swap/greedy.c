#include "push_swap.h"

// static void combined_rotations(t_stack **a, t_stack **b)
// {
//     while ((*a)->cost > 0 && (*b)->cost > 0)
//     {
//         rr(a, b);
//         (*a)->cost--;
//         (*b)->cost--;
//     }
//     while ((*a)->cost < 0 && (*b)->cost < 0)
//     {
//         rrr(a, b);
//         (*a)->cost++;
//         (*b)->cost++;
//     }
// }
// static void individual_rotations(t_stack **a, t_stack **b)
// {
//     while ((*a)->cost > 0)
//     {
//         ra(a);
//         (*a)->cost--;
//     }
//     while ((*a)->cost < 0)
//     {
//         rra(a);
//         (*a)->cost++;
//     }
//     while ((*b)->cost > 0)
//     {
//         rb(b);
//         (*b)->cost--;
//     }
//     while ((*b)->cost < 0)
//     {
//         rrb(b);
//         (*b)->cost++;
//     }
// }
// void run_cmd(t_stack **a, t_stack **b)
// {
//     combined_rotations(a, b);
//     individual_rotations(a, b);
// }
// t_costs push_cost_b(t_stack **a, t_stack **b, int value_to_push)
// {
//     t_costs result;
//     int a_idx_for_value;
//     int b_target_idx;

//     a_idx_for_value = find_index(a, value_to_push);
//     b_target_idx = find_target_index_b(b, value_to_push);
//     result.a_rot_cost = rotation_cost(a, a_idx_for_value);
//     result.b_rot_cost = rotation_cost(b, b_target_idx);

//     if ((result.a_rot_cost > 0 && result.b_rot_cost > 0) || (result.a_rot_cost < 0 && result.b_rot_cost < 0))
//     {
//         if (abs(result.a_rot_cost) > abs(result.b_rot_cost))
//             result.total_cost = abs(result.a_rot_cost);
//         else
//             result.total_cost = abs(result.b_rot_cost);
//     }
//     else
//     {
//         result.total_cost = abs(result.a_rot_cost) + abs(result.b_rot_cost);
//     }
//     return (result);
// }
// t_costs push_cost_a(t_stack **a, t_stack **b, int value_to_push)
// {
//     t_costs result;
//     int b_idx_for_value;
//     int a_target_idx;

//     b_idx_for_value = find_index(b, value_to_push);
//     a_target_idx = find_target_index_a(a, value_to_push);
//     result.a_rot_cost = rotation_cost(a, a_target_idx);
//     result.b_rot_cost = rotation_cost(b, b_idx_for_value);

//     if ((result.a_rot_cost > 0 && result.b_rot_cost > 0) || (result.a_rot_cost < 0 && result.b_rot_cost < 0))
//     {
//         if (abs(result.a_rot_cost) > abs(result.b_rot_cost))
//             result.total_cost = abs(result.a_rot_cost);
//         else
//             result.total_cost = abs(result.b_rot_cost);
//     }
//     else
//     {
//         result.total_cost = abs(result.a_rot_cost) + abs(result.b_rot_cost);
//     }
//     return (result);
// }
// void greedy_insert_b(t_stack **a, t_stack **b)
// {
//     t_stack             *current_a_node;
//     int                 min_total_cost;
//     int                 best_a_rot_cost; 
//     int                 best_b_rot_cost;
//     t_costs  current_costs;

//     min_total_cost = INT_MAX;
//     best_a_rot_cost = 0;
//     best_b_rot_cost = 0;
//     current_a_node = *a; 
//     while (current_a_node)
//     {
//         current_costs = push_cost_b(a, b, current_a_node->value);        
//         if (current_costs.total_cost < min_total_cost)
//         {
//             min_total_cost = current_costs.total_cost;
//             best_a_rot_cost = current_costs.a_rot_cost;
//             best_b_rot_cost = current_costs.b_rot_cost;
//         }
//         current_a_node = current_a_node->next;
//     }
//     if (*a)
//         (*a)->cost = best_a_rot_cost;
//     if (*b)
//         (*b)->cost = best_b_rot_cost;
//     run_cmd(a, b);
//     pb(a, b);      
// }

// void greedy_insert_a(t_stack **a, t_stack **b)
// {
//     t_stack             *current_b_node;
//     int                 min_total_cost;
//     int                 best_a_rot_cost;
//     int                 best_b_rot_cost;
//     t_costs  current_costs;

//     min_total_cost = INT_MAX;
//     best_a_rot_cost = 0;
//     best_b_rot_cost = 0;
//     current_b_node = *b;
//     while (current_b_node)
//     {
//         current_costs = push_cost_a(a, b, current_b_node->value);
        
//         if (current_costs.total_cost < min_total_cost)
//         {
//             min_total_cost = current_costs.total_cost;
//             best_a_rot_cost = current_costs.a_rot_cost;
//             best_b_rot_cost = current_costs.b_rot_cost;
//         }
//         current_b_node = current_b_node->next;
//     }
//     if (*a)
//         (*a)->cost = best_a_rot_cost;
//     if (*b)
//         (*b)->cost = best_b_rot_cost;
//     run_cmd(a, b);
//     pa(a, b);
// }
// Helper function to calculate the cost logic (similar to is_better_move's cost calculation)
static int calculate_total_cost(int a_steps, int b_steps)
{
    if ((a_steps > 0 && b_steps > 0) || (a_steps < 0 && b_steps < 0))
    {
        // Same direction rotations (rr or rrr)
        if (ft_abs(a_steps) > ft_abs(b_steps))
            return ft_abs(a_steps);
        else
            return ft_abs(b_steps);
    }
    else
    {
        // Opposite direction rotations (ra/rrb or rra/rb)
        return ft_abs(a_steps) + ft_abs(b_steps);
    }
}

// This function calculates the costs for pushing a specific value from b to a
t_costs calculate_push_costs(t_stack **a, t_stack **b, int value_to_push)
{
    t_costs result;
    int b_idx_for_value;
    int a_target_idx;

    // These functions need to be robust and return correct indices/costs
    b_idx_for_value = find_index(b, value_to_push); // Index of the value in stack B
    a_target_idx = find_target_index_a(a, value_to_push); // Target position in stack A

    result.a_rot_cost = rotation_cost(a, a_target_idx); // Rotations to bring target pos to top of A
    result.b_rot_cost = rotation_cost(b, b_idx_for_value); // Rotations to bring value to top of B

    result.total_cost = calculate_total_cost(result.a_rot_cost, result.b_rot_cost);

    return result;
}
static void execute_best_move(t_stack **a, t_stack **b, int a_steps, int b_steps)
{
    // Perform joint rotations first (rr or rrr)
    while (a_steps > 0 && b_steps > 0)
    {
        rr(a, b); // Assuming rr takes both stack pointers
        a_steps--;
        b_steps--;
    }
    while (a_steps < 0 && b_steps < 0)
    {
        rrr(a, b); // Assuming rrr takes both stack pointers
        a_steps++;
        b_steps++;
    }

    // Perform remaining individual rotations for stack A
    while (a_steps > 0)
    {
        ra(a); // Assuming ra takes only stack a pointer
        a_steps--;
    }
    while (a_steps < 0)
    {
        rra(a); // Assuming rra takes only stack a pointer
        a_steps++;
    }

    // Perform remaining individual rotations for stack B
    while (b_steps > 0)
    {
        rb(b); // Assuming rb takes only stack b pointer
        b_steps--;
    }
    while (b_steps < 0)
    {
        rrb(b); // Assuming rrb takes only stack b pointer
        b_steps++;
    }

    // Finally, push the element from B to A
    pa(a, b);
}


void greedy_insert_a(t_stack **a, t_stack **b)
{
    t_stack    *current_b_node;
    int        min_total_cost;
    int        best_a_rot_cost;
    int        best_b_rot_cost;
    t_costs    current_costs;
    t_stack    *best_b_node =NULL;
    min_total_cost = INT_MAX;
    best_a_rot_cost = 0;
    best_b_rot_cost = 0;

    // Check if stack b is empty before proceeding
    if (!*b)
        return;

    current_b_node = *b; // Start from the head of stack b
    while (current_b_node) // Iterate through each element in stack b
    {
        current_costs = calculate_push_costs(a, b, current_b_node->value);

        // This effectively replaces your 'is_better_move' logic
        if (current_costs.total_cost < min_total_cost)
        {
            min_total_cost = current_costs.total_cost;
            best_a_rot_cost = current_costs.a_rot_cost;
            best_b_rot_cost = current_costs.b_rot_cost;
            best_b_node = current_b_node;
        }
        current_b_node = current_b_node->next; // Move to the next element in b
    }
   if (best_b_node) {
        printf("Best element to push: %d, min_total_cost: %d, best_a_rot_cost: %d, best_b_rot_cost: %d\n",
               best_b_node->value, min_total_cost, best_a_rot_cost, best_b_rot_cost);
    } else {
        printf("Error: No best element found in B (should not happen if B is not empty)\n");
    }
    // After finding the best move, execute it
    execute_best_move(a, b, best_a_rot_cost, best_b_rot_cost);
}