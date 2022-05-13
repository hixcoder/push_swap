/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:01:20 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/13 12:57:15 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three(t_stack *s)
{
    int t[3];

    if (s == NULL)
        return ;
    ft_memcpy(t, s->stack_a, 3 * sizeof(int));
    if (t[0] < t[1] && t[1] > t[2] && t[2] > t[0])
    {
        ft_sa(s, 1);
        ft_ra(s, 1);
    }
    else if (t[0] > t[1] && t[1] > t[2] && t[2] < t[0])
    {
        ft_sa(s, 1);
        ft_rra(s, 1);
    }
    else if (t[0] > t[1] && t[1] < t[2] && t[2] > t[0])
        ft_sa(s, 1);
    else if (t[0] > t[1] && t[1] < t[2] && t[2] < t[0])
        ft_ra(s, 1);
    else if (t[0] < t[1] && t[1] > t[2] && t[2] < t[0])
        ft_rra(s, 1);
    else
        return ;
}