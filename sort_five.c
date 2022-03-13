/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:49:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/13 13:06:44 by hboumahd         ###   ########.fr       */
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
    int index0a;
    int index0b;
    
    if (s == NULL)
        return ;
    ft_pb(s);
    ft_pb(s);
    ft_sort_three(s);
    
    index0b = ft_get_index(s, s->stack_b[0]);
    while(ft_memcmp(s->stack_a, s->stack_sorted, s->stack_a_len * sizeof(int)) != 0)
    {
        // sleep(1);
        index0a = ft_get_index(s, s->stack_a[0]);
        // ft_printf("s->stack_a[0] = %d   index0a = %d  \n", s->stack_a[0], index0a);
        // ft_printf("s->stack_b[0] = %d   index0b = %d  \n", s->stack_b[0], index0b);
        // ft_printf("index0a - index0b == %d  \n", index0a - index0b);
        if (index0a - index0b == 1)
            ft_pa(s);
        else
            ft_ra(s);
    }
    
}d