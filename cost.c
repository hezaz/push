/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:39:57 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/06 01:22:19 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_get_cost(t_stack **stack_a, t_stack **stack_b)
{

	if (!(*stack_b))
		return ;

	//ft_print_stack(stack_a, stack_b, ft_stksize(*stack_b));
	get_cost(stack_a);
	get_cost(stack_b);
	get_absolute_cost(stack_a, stack_b);
	find_best_op(stack_a, stack_b);
}

void	get_cost(t_stack **stack)
{
	t_stack			*tmp;
	int				len;

	len = ft_stksize(*stack);
	ft_get_pos(*stack);
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

	else
	{
	tmp = *stack;
		while (tmp)
		{
			if ((tmp->pos - 1) > len / 2)
				tmp->cost= tmp->pos - len - 1;
			else
				tmp->cost = tmp->pos - 1;
			tmp = tmp->next;
		}
	}

}

t_stack *find_place(t_stack *element_b, t_stack **stack_a)
{
    t_stack *current;
    t_stack *last_valid_position = NULL;

	current = *stack_a;
	    // Si stack_a est vide, retourner NULL (aucun placement possible)
    if (current == NULL)
    {
        return NULL;
    }
	get_cost(stack_a);

	if (current->index > element_b->index && ft_stklast(&current)->index < element_b->index)
		return (current);
	else if (element_b->index < ft_stkmin(&current)->index)
		return (ft_stkmin(&current));
	else if (element_b->index > ft_stkmax(stack_a)->index)
	{
		if (ft_stkmax(stack_a)->next)
			return (ft_stkmax(stack_a)->next);
		return (*stack_a);
	}

    // Recherche de la position où element_b doit être inséré
    while (current->next != NULL)
    {
        if (current->value < element_b->value && current->next->value > element_b->value)
        {
            last_valid_position = current->next;
            break;
        }
        current = current->next;
    }
	current = *stack_a;
	//if (current->value )

    // Gérer le cas où l'élément doit être placé en fin de stack_a
    if (last_valid_position == NULL)
    {
		current = *stack_a;
        while (current->index !=element_b->index_min && current)
        {
            current = current->next; // Placer au début si element_b est le plus grand
        }
		if (current->index == current->index_min)
			last_valid_position = current;
    }
	element_b->cost_a = last_valid_position->cost;
    return last_valid_position;
}



void		get_absolute_cost(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_b = *stack_b;

    while (current_b != NULL)
    {

        t_stack *placement_a = find_place(current_b, stack_a);

        // Assigner le coût de placement_a à cost_a de l'élément de stack_b
        current_b->cost_a = (placement_a != NULL) ? placement_a->cost : 0;
		//printf("\n%d\n", current_b->cost_a);
        // Calculer le coût absolu
        int cost_b = current_b->cost;

        // Si les coûts sont de signes différents, additionner leurs valeurs absolues
        if ((current_b->cost_a < 0 && cost_b >= 0) || (current_b->cost_a >= 0 && cost_b < 0))
        {
            current_b->absolute_cost = abs(current_b->cost_a) + abs(cost_b);
        }
        else
        {
            // Si les coûts sont de même signe, prendre la valeur absolue la plus élevée
            current_b->absolute_cost = abs(current_b->cost_a) > abs(cost_b) ? abs(current_b->cost_a) : abs(cost_b);
        }

        current_b = current_b->next;
    }
}


void find_best_op(t_stack **stack_a,t_stack **stack_b)
{
	t_stack		*tmp_b;
	int			rot_b;
	int			rot_a;
	int			cpr;

	tmp_b = *stack_b;
	cpr = tmp_b->absolute_cost;
	rot_b = 0;
	while (tmp_b)
	{
		if (tmp_b->absolute_cost <= cpr)
		{
			cpr = tmp_b->absolute_cost;
			rot_b = tmp_b->cost;
			rot_a = (find_place(tmp_b, stack_a))->cost;

		}
		tmp_b = tmp_b->next;

	}

	ft_pushwap(stack_a, stack_b, &rot_a, &rot_b);

}

void	ft_pushwap(t_stack **stack_a, t_stack **stack_b, int *rot_a, int *rot_b)
{
	int rota;
	int rotb;
	t_stack *tmp_b;

	rota = *rot_a;
	rotb = *rot_b;
	tmp_b = *stack_b;
	if (!tmp_b)
		return ; ///////// LEAKS LEAKS LEAKS LEAKS LEAKS STACK A & B NO FREED have to impkement ft_error with stack a and b and not just stack a
	while (rota != 0 || rotb != 0)
	{
		if ((rota > 0 && rotb <= 0) || (rota < 0 && rotb >= 0))
			ft_rotate(stack_a, &rota, 'a');
		else if ((rotb < 0 && rota >= 0) || (rotb > 0 && rota <= 0))
			ft_rotate(stack_b, &rotb, 'b');
		else if ((rota > 0 && rotb > 0 )||(rota < 0 && rotb < 0))
			ft_rr(stack_a, stack_b, &rota, &rotb);

	}
	ft_push(stack_b, stack_a,'a');
	//get_cost(stack_a);
	//get_cost(stack_b);
	//int l = get_absolute_cost(stack_a, stack_b);
	//find_best_op(stack_a, stack_b, &l);
	//ft_print_stack(stack_a, stack_b, ft_stksize(*stack_b));
	ft_get_cost(stack_a, stack_b);

}

