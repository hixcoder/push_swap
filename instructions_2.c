/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:34 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/05 12:07:59 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ft_ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one
*/
void    ft_ra(t_stack *s)
{
    int i;
    int temp;

	if (s->stack_a_len > 1)
	{
        temp = s->stack_a[0];
        i = -1;
        while (++i < (s->stack_a_len - 1))
		    s->stack_a[i] = s->stack_a[i + 1];
        s->stack_a[s->stack_a_len - 1] = temp;
        ft_printf("ra\n");
    }
	else
		return ;
}

/*
	ft_rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.
*/
void    ft_rb(t_stack *s)
{
    int i;
    int temp;

	if (s->stack_b_len > 1)
	{
        temp = s->stack_b[0];
        i = -1;
        while (++i < (s->stack_b_len - 1))
		    s->stack_b[i] = s->stack_b[i + 1];
        s->stack_b[s->stack_b_len - 1] = temp;
        ft_printf("rb\n");
    }
	else
		return ;
}

/*
	ft_rr : ft_ra and ft_rb at the same time.
*/
void    ft_rr(t_stack *s)
{
    int i;
    int temp;

    ft_printf("rr\n");
	if (s->stack_a_len > 1)
	{
        temp = s->stack_a[0];
        i = -1;
        while (++i < (s->stack_a_len - 1))
		    s->stack_a[i] = s->stack_a[i + 1];
        s->stack_a[s->stack_a_len - 1] = temp;
    }
    if (s->stack_b_len > 1)
	{
        temp = s->stack_b[0];
        i = -1;
        while (++i < (s->stack_b_len - 1))
		    s->stack_b[i] = s->stack_b[i + 1];
        s->stack_b[s->stack_b_len - 1] = temp;
    }
	else
		return ;
}
