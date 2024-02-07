/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 04:24:56 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 04:33:19 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	norm_getcost(t_stack **stack, int len)
{
	if (len == 0)
		return ;
	else if (len == 1)
		(*stack)->cost = 0;
	else if (len == 2)
	{
		(*stack)->cost = 0;
		(*stack)->next->cost = 1;
	}
	else if (len == 3)
	{
		(*stack)->cost = 0;
		(*stack)->next->cost = 1;
		(*stack)->next->next->cost = -1;
	}
}

void	get_cost(t_stack **stack)
{
	t_stack			*tmp;
	int				len;

	len = ft_stksize(*stack);
	ft_get_pos(*stack);
	if (len >= 0 && len <= 3)
		return (norm_getcost(stack, len));
	else
	{
	tmp = *stack;
		while (tmp)
		{
			if ((tmp->pos - 1) > len / 2)
				tmp->cost = tmp->pos - len - 1;
			else
				tmp->cost = tmp->pos - 1;
			tmp = tmp->next;
		}
	}
}

t_stack	*norm_findplace(t_stack *stack_b, t_stack **stack_a)
{
	t_stack	*current;

	current = *stack_a;
	if (current->index > stack_b->index
		&& ft_stklast(&current)->index < stack_b->index)
		return (current);
	else if (stack_b->index < ft_stkmin(&current)->index)
		return (ft_stkmin(&current));
	else if (stack_b->index > ft_stkmax(stack_a)->index)
	{
		if (ft_stkmax(stack_a)->next)
			return (ft_stkmax(stack_a)->next);
		return (*stack_a);
	}
	return (NULL);
}
