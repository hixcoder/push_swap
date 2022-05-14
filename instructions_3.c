/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:41:39 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/14 12:13:41 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ft_rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	ft_rra(t_stack *s, int w)
{
	int	len;
	int	temp;

	if (s->stack_a_len > 1)
	{
		len = s->stack_a_len;
		temp = s->stack_a[len - 1];
		while (--len > 0)
			s->stack_a[len] = s->stack_a[len - 1];
		s->stack_a[0] = temp;
		if (w == 1)
			ft_printf("rra\n");
	}
	else
		return ;
}

/*
	ft_rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
*/
void	ft_rrb(t_stack *s, int w)
{
	int	len;
	int	temp;

	if (s->stack_b_len > 1)
	{
		len = s->stack_b_len;
		temp = s->stack_b[len - 1];
		while (--len > 0)
			s->stack_b[len] = s->stack_b[len - 1];
		s->stack_b[0] = temp;
		if (w == 1)
			ft_printf("rrb\n");
	}
	else
		return ;
}

/*
	ft_rrr : ft_rra and ft_rrb at the same time.
*/
void	ft_rrr(t_stack *s, int w)
{
	int	len;
	int	temp;

	if ((s->stack_a_len > 1 || s->stack_b_len > 1) && w == 1)
		ft_printf("rrr\n");
	if (s->stack_a_len > 1)
	{
		len = s->stack_a_len;
		temp = s->stack_a[len - 1];
		while (--len > 0)
			s->stack_a[len] = s->stack_a[len - 1];
		s->stack_a[0] = temp;
	}
	if (s->stack_b_len > 1)
	{
		len = s->stack_b_len;
		temp = s->stack_b[len - 1];
		while (--len > 0)
			s->stack_b[len] = s->stack_b[len - 1];
		s->stack_b[0] = temp;
	}
	else
		return ;
}
