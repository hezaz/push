/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 06:16:15 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 18:43:22 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_mini_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	un;

	un = 1;
	if (check_sort(stack_a) && !(*stack_b))
		ft_exit(*stack_a, *stack_b);
	if (ft_stksize(*stack_a) < 3 && (*stack_a)->next)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			ft_rotate(stack_a, &un, 'a');
	}
	if (ft_stksize(*stack_a) > 2 && ft_stksize(*stack_a) < 6)
		mini_sort(stack_a, stack_b);
}

void	micro_sort(t_stack **stack_a)
{
	t_stack	*max;
	int		un;

	un = 1;
	if (check_sort(stack_a))
		return ;
	max = ft_stkmax(stack_a);
	if (max->pos == 1)
		ft_rotate(stack_a, &un, 'a');
	if (max->pos == 2)
	{
		un *= -1;
		ft_rotate(stack_a, &un, 'a');
	}
	if (max->pos == 3 && !check_sort(stack_a))
		ft_swap(stack_a, 'a', &un);
	ft_get_pos(*stack_a);
	if (!check_sort(stack_a))
		micro_sort(stack_a);
}

void	mini_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		un;

	while (*stack_a && ft_stksize(*stack_a) > 3)
	{
		min = ft_stkmin(stack_a);
		while (min->pos != 1)
		{
			un = 1;
			if (min->pos > (ft_stksize(*stack_a) / 2))
			{
				un *= -1;
				ft_rotate(stack_a, &un, 'a');
			}
			else
				ft_rotate(stack_a, &un, 'a');
			ft_get_pos(*stack_a);
		}
		ft_push(stack_a, stack_b, 'b');
	}
	micro_sort(stack_a);
	ft_push(stack_b, stack_a, 'a');
	ft_push(stack_b, stack_a, 'a');
	if (check_sort(stack_a))
		ft_exit(*stack_a, *stack_b);
}
