/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:29 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/03 22:58:48 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_stack *s)
{
    int temp;

    temp = s->stack_a[0];
    s->stack_a[0] = s->stack_a[1];
    s->stack_a[1] = temp;
}

void ft_sb(t_stack *s)
{
    int temp;

    temp = s->stack_b[0];
    s->stack_b[0] = s->stack_b[1];
    s->stack_b[1] = temp;
}

void ft_ss(t_stack *s)
{
    ft_sa(s);
    ft_sb(s);
}

void ft_pa(t_stack *s)
{
    int temp;

    temp = s->stack_b[0];
    s->stack_b[0] = s->stack_b[1];
    s->stack_b[1] = temp;
}