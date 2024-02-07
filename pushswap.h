/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzaz <hzaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:47:43 by hzaz              #+#    #+#             */
/*   Updated: 2024/02/07 19:09:31 by hzaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				index_max;
	int				index_min;
	int				pos;
	int				cost;
	int				cost_a;
	int				stack_size;
	int				absolute_cost;
	struct s_stack	*next;
}	t_stack;

//------------------	 Algo.c   ------------------//

void		ft_get_cost(t_stack **stack_a, t_stack **stack_b);
t_stack		*find_place(t_stack *stack_b, t_stack **stack_a);
void		get_absolute_cost( t_stack **stack_b, t_stack **stack_a);
void		find_best_op(t_stack **stack_a, t_stack **stack_b);
void		ft_pushwap(t_stack **stack_a, t_stack **stack_b, t_stack *ret);

//------------------	 Cost.c   ------------------//

void		norm_getcost(t_stack **stack, int len);
void		get_cost(t_stack **stack);
t_stack		*norm_findplace(t_stack *stack_b, t_stack **stack_a);

//------------------	 op.c   ------------------//

void		swap(t_stack **stack);
void		push(t_stack **src, t_stack **dst);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);

//------------------	 ft_op.c   ------------------//

void		ft_swap(t_stack **stack, char c, int *i);
void		ft_push(t_stack **src, t_stack **dst, char c);
void		ft_rotate(t_stack **stack, int *i, char c);
void		ft_reverse_rotate(t_stack **stack, int *i, char c);
void		ft_rr(t_stack **stack_a, t_stack **stack_b, int *i, int *j);

//------------------	 double_op.c   ------------------//
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

//------------------	 fist_sort.c   ------------------//

int			still_index(t_stack *stack, int index);
void		first_sorrt(t_stack **stack_a, t_stack **stack_b);
void		second_sorrt(t_stack **stack_a, t_stack **stack_b);
void		first(t_stack **stack_a, t_stack **stack_b);

//------------------	 index.c   ------------------//

void		ft_getsize(t_stack **stack);
void		ft_get_index_final(t_stack *stack_a);
void		get_index_max_min(t_stack *stack);
void		ft_get_pos(t_stack *stack);

//------------------	 main.c   ------------------//
int			ft_exit(t_stack *stack_a, t_stack *stack_b);
int			check_sort(t_stack **stack);
void		ft_free_stack(t_stack *stack);
t_stack		*get_stack(char **av, t_stack *stack_a, int ac);

//------------------	 mini_sort.c   ------------------//

void		ft_mini_sort(t_stack **stack_a, t_stack **stack_b);
void		micro_sort(t_stack **stack_a);
void		mini_sort(t_stack **stack_a, t_stack **stack_b);

//------------------	 stack.c   ------------------//

t_stack		*ft_stknew(int value, int pos);
t_stack		*ft_stkmax(t_stack **stack_a);
t_stack		*ft_stkmin(t_stack **stack_a);
void		check_stkdouble(t_stack **stack);
void		ft_stkadd_back(t_stack **lst, t_stack *new);

//------------------	 utils.c   ------------------//

int			ft_exit_error(t_stack *stack_a);
t_stack		*ft_stklast(t_stack **stack);
int			ft_pushatoi(const char *str, t_stack *stack_a);
int			ft_stksize(t_stack *stack);
int			ft_abs(int nbr);
#endif