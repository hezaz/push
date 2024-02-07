/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:34:23 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 04:18:17 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

t_stack	*ft_stknew(int value, int pos)
{
	t_stack	*ret;

	ret = malloc(sizeof(t_stack));
	if (!ret)
		return (NULL);
	(*ret).value = value;
	(*ret).pos = pos;
	(*ret).index = -1;
	(*ret).cost = 0;
	ret->next = NULL;
	return (ret);
}

t_stack	*ft_stkmax(t_stack **stack_a)
{
	t_stack	*max;
	t_stack	*tmp;

	tmp = *stack_a;
	max = *stack_a;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*ft_stkmin(t_stack **stack_a)
{
	t_stack	*min;
	t_stack	*tmp;

	tmp = *stack_a;
	min = *stack_a;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	check_stkdouble(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cur;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		cur = tmp->next;
		while (cur)
		{
			if (tmp->value == cur->value)
				ft_exit(*stack);
			cur = cur->next;
		}
		tmp = tmp->next;
	}
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new)
		return ;
	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
	return ;
}
