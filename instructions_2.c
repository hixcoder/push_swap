/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:34 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/04 11:40:17 by hboumahd         ###   ########.fr       */
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
    }
	else
		return ;
}

/*
	ft_rr : ft_ra and ft_rb at the same time.
*/
void    ft_rr(t_stack *s)
{
    ft_ra(s);
    ft_rb(s);
}
