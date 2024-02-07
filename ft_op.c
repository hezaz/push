/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 04:13:51 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 04:15:21 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	ft_swap(t_stack **stack, char c, int *i)
{
	if (c == 'a')
	{
		ft_printf("sa\n");
	}
	if (c == 'b')
	{
		ft_printf("sb\n");
	}
	if (*i > 0)
		(*i)--;
	if (*i < 0)
		(*i)++;
	swap(stack);
}

void	ft_push(t_stack **src, t_stack **dst, char c)
{
	push(src, dst);
	if (c == 'a')
	{
		ft_printf("pa\n");
	}
	if (c == 'b')
		ft_printf("pb\n");
	ft_get_pos(*src);
	ft_get_pos(*dst);
}

void	ft_rotate(t_stack **stack, int *i, char c)
{
	if (ft_stksize(*stack) == 2 && *i != 0)
	{
		ft_swap(stack, c, i);
		return ;
	}
	if (*i < 0 && *i && i)
		return (ft_reverse_rotate(stack, i, c));
	while (*i > 0)
	{
		rotate(stack);
		if (c == 'a')
			ft_printf("ra\n");
		else if (c == 'b')
			ft_printf("rb\n");
		(*i)--;
	}
	ft_get_pos(*stack);
}

void	ft_reverse_rotate(t_stack **stack, int *i, char c)
{
	while (*i < 0)
	{
		reverse_rotate(stack);
		if (c == 'a')
			ft_printf("rra\n");
		else if (c == 'b')
			ft_printf("rrb\n");
		(*i)++;
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int *i, int *j)
{
	if (*i < 0 && *j < 0)
	{
		while (*i < 0 && *j < 0)
		{
			rrr(stack_a, stack_b);
			(*i)++;
			(*j)++;
		}
	}
	else if (*i > 0 && *j > 0)
	{
		while (*i > 0 && *j > 0)
		{
			rr(stack_a, stack_b);
			(*i)--;
			(*j)--;
		}
	}
	ft_get_pos(*stack_a);
	ft_get_pos(*stack_b);
}
