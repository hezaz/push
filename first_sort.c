/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:31:43 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/05 17:20:02 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int still_index(t_stack *stack, int index)
{
    int limit;
    t_stack *tmp;

    tmp = stack;
    if (index == 2)
        limit = (stack->stack_size * 2) / 3;
    else if (index == 3)
        limit = stack->stack_size / 3;
    while(tmp)
    {
        if (tmp->index >= limit)
            return (1);

        tmp = tmp->next;
    }
    return (0);
}

void first_sorrt(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int rot_cpt;

    rot_cpt = 0;
    while (still_index(*stack_a, 2))
    {
        get_cost(stack_a);
        tmp = *stack_a;
        while(tmp )
        {
            if (tmp->index >= (tmp->stack_size * 2) / 3)
            {
                rot_cpt = tmp->cost;
                break ;
            }
            tmp = tmp->next;
        }
        if (rot_cpt)
            ft_rotate(stack_a, &rot_cpt, 'a');
        //if ((*stack_a)->index != 0 && (*stack_a)->index != 1)
        ft_push(stack_a, stack_b,'b');
    }
}

void second_sorrt(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int rot_cpt;

    rot_cpt = 0;
    while (still_index(*stack_a, 3))
    {
        get_cost(stack_a);
        tmp = *stack_a;
        while(tmp )
        {
            if (tmp->index >= (tmp->stack_size) / 3)
            {
                rot_cpt = tmp->cost;
                break ;
            }
            tmp = tmp->next;
        }
        if (rot_cpt)
            ft_rotate(stack_a, &rot_cpt, 'a');
        //if ((*stack_a)->index != 0 && (*stack_a)->index != 1)
        ft_push(stack_a, stack_b,'b');
    }
}

void first(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int rot_cpt;

    tmp = *stack_a;
    rot_cpt = 0;
    first_sorrt(stack_a, stack_b);
    second_sorrt(stack_a,stack_b);
    while (ft_stksize(*stack_a) > 2)
    {
        get_cost(stack_a);
        tmp = *stack_a;
        while(tmp)
        {
            if (tmp->index != (*stack_a)->index_min && tmp->index != (*stack_a)->index_min + 1)
            {
                rot_cpt = tmp->cost;
                break ;
            }
            tmp = tmp->next;
        }
        if (rot_cpt)
            ft_rotate(stack_a, &rot_cpt, 'a');
        if ((*stack_a)->index != (*stack_a)->index_min && (*stack_a)->index != (*stack_a)->index_min + 1)
            ft_push(stack_a, stack_b,'b');
    }
    ft_mini_sort(stack_a);
}






void	ft_mini_sort(t_stack **stack_a)
{
	int	un = 1;
	if ((*stack_a) && ((*stack_a)->next ))
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_rotate(stack_a,&un,'a');
	}
}