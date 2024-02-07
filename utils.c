/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:40:56 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 04:16:53 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	ft_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	exit(0);
	return (-1);
}

int	ft_exit_error(t_stack *stack_a)
{
	if (stack_a)
		ft_free_stack(stack_a);
	ft_printf("Error\n");
	exit(-1);
	return (-1);
}

t_stack	*ft_stklast(t_stack **stack)
{
	t_stack	*lst;

	lst = *stack;
	if (lst == NULL || !lst)
		return (0);
	while (lst -> next)
		lst = lst->next;
	return (lst);
}

int	ft_pushatoi(const char *str, t_stack *stack_a)
{
	int			i;
	int			s;
	int			res2;
	long long	tmp;

	res2 = 0;
	s = 1;
	i = 0;
	tmp = 0;
	if (!str[i])
		ft_exit_error(stack_a);
	while (str && str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while ((str[i] == '+' || str[i] == '-') && str && str[i])
		if (str[i++] == '-')
			s *= (-1);
	if (!str[i])
		ft_exit_error(stack_a);
	while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
		tmp = (tmp * 10) + (str[i++] - '0');
	if ((tmp > INT_MAX) || (tmp < INT_MIN)
		|| (str[i] && !(str[i] >= '0' && str[i] <= '9')))
		return (ft_exit_error(stack_a));
	res2 = (int)tmp;
	return (res2 * s);
}

int	ft_stksize(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	if (!stack)
		return (i);
	if (!(stack -> next))
		return (++i);
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	else
		return (nbr);
}
