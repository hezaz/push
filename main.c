/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:30:25 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 06:45:30 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stk_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index != (tmp->pos - 1))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_sort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value > (tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

t_stack	*get_stack(char **av, t_stack *stack_a, int ac)
{
	int	i;
	int	num;

	i = 1;
	while (av[i] && *av[i])
	{
		num = ft_pushatoi(av[i], stack_a);
		ft_stkadd_back(&stack_a, ft_stknew(num, i));
		i++;
	}
	check_stkdouble(&stack_a);
	if (i != ac)
	{
		ft_free_stack(stack_a);
		return (NULL);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = get_stack(av, stack_a, ac);
	ft_get_index_final(stack_a);
	ft_mini_sort(&stack_a, &stack_b);
	first(&stack_a, &stack_b);
	ft_get_cost(&stack_a, &stack_b);
	while (stack_a->index != stack_a->index_min)
	{
		rotate(&stack_a);
		ft_printf("ra\n");
	}
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
