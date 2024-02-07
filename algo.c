/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:39:57 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 05:36:20 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_b))
		return ;
	get_cost(stack_a);
	get_cost(stack_b);
	get_absolute_cost(stack_b, stack_a);
	find_best_op(stack_a, stack_b);
}

t_stack	*find_place(t_stack *stack_b, t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*last_valid_position;

	current = *stack_a;
	last_valid_position = NULL;
	if (norm_findplace(stack_b, stack_a))
		return (norm_findplace(stack_b, stack_a));
	while (current->next != NULL)
	{
		if (current->value < stack_b->value
			&& current->next->value > stack_b->value)
		{
			last_valid_position = current->next;
			break ;
		}
		current = current->next;
	}
	stack_b->cost_a = last_valid_position->cost;
	return (last_valid_position);
}

void	get_absolute_cost( t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*current_b;
	int		cost_b;
	int		abs_cost_a;
	int		abs_cost_b;

	current_b = *stack_b;
	while (current_b != NULL)
	{
		cost_b = current_b->cost;
		abs_cost_a = ft_abs(find_place(current_b, stack_a)->cost);
		abs_cost_b = ft_abs(cost_b);
		if ((find_place(current_b, stack_a)->cost <= 0 && cost_b >= 0)
			|| (find_place(current_b, stack_a)->cost >= 0 && cost_b <= 0))
			current_b->absolute_cost = abs_cost_a + abs_cost_b;
		else
		{
			if (abs_cost_a > abs_cost_b)
				current_b->absolute_cost = abs_cost_a;
			else
				current_b->absolute_cost = abs_cost_b;
		}
		current_b = current_b->next;
	}
}

void	find_best_op(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*tmp_b;
	t_stack		*ret;
	int			cpr;

	tmp_b = *stack_b;
	cpr = tmp_b->absolute_cost;
	ret = NULL;
	while (tmp_b)
	{
		if (tmp_b->absolute_cost <= cpr)
		{
			cpr = tmp_b->absolute_cost;
			ret = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	ft_pushwap(stack_a, stack_b, ret);
}

void	ft_pushwap(t_stack **stack_a, t_stack **stack_b, t_stack *ret)
{
	int		rota;
	int		rotb;
	t_stack	*tmp_b;

	rota = find_place(ret, stack_a)->cost;
	rotb = ret->cost;
	tmp_b = *stack_b;
	if (!tmp_b)
		return ;
	while (rota != 0 || rotb != 0)
	{
		if ((rota > 0 && rotb <= 0) || (rota < 0 && rotb >= 0))
			ft_rotate(stack_a, &rota, 'a');
		else if ((rotb < 0 && rota >= 0) || (rotb > 0 && rota <= 0))
			ft_rotate(stack_b, &rotb, 'b');
		else if ((rota > 0 && rotb > 0) || (rota < 0 && rotb < 0))
			ft_rr(stack_a, stack_b, &rota, &rotb);
	}
	ft_push(stack_b, stack_a, 'a');
	ft_get_cost(stack_a, stack_b);
}
