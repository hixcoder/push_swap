/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:18:01 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/14 12:02:51 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ft_sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
*/
void	ft_sa(t_stack *s, int w)
{
	int	temp;

	if (s->stack_a_len > 1)
	{
		temp = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = temp;
		if (w == 1)
			ft_printf("sa\n");
	}
	else
		return ;
}

/*
	ft_sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
*/
void	ft_sb(t_stack *s, int w)
{
	int	temp;

	if (s->stack_b_len > 1)
	{
		temp = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = temp;
		if (w == 1)
			ft_printf("sb\n");
	}
	else
		return ;
}

/*
	ft_ss : ft_sa and ft_sb at the same time.
*/
void	ft_ss(t_stack *s, int w)
{
	int	temp;

	if ((s->stack_a_len > 1 || s->stack_b_len > 1) && w == 1)
		ft_printf("ss\n");
	if (s->stack_a_len > 1)
	{
		temp = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = temp;
	}
	if (s->stack_b_len > 1)
	{
		temp = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = temp;
	}
	else
		return ;
}
