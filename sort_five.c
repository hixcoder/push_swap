/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:49:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/14 17:57:01 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_index(t_stack *s, int nbr)
{
    int i;

    i = -1;
    while (++i < s->sorted_len)
    {
        if (s->stack_sorted[i] == nbr)
            return (i);   
    }
    return (-1);
}

void ft_sort_five(t_stack *s)
{
   
    while(s->stack_a_len > 3)
    {
        if(ft_get_index(s, s->stack_a[0]) == 0 || ft_get_index(s, s->stack_a[0]) == 1)
            ft_pb(s);
        else
            ft_ra(s);
    }
    if (s->stack_b[0] < s->stack_b[1])
        ft_sb(s);
    ft_sort_three(s);
    ft_pa(s);
    ft_pa(s);
}
