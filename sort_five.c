/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:49:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/14 12:39:32 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_five(t_stack *s)
{
	while (s->stack_a_len > 3)
	{
		if (ft_ind(s, s->stack_a[0]) == 0
			|| ft_ind(s, s->stack_a[0]) == 1)
			ft_pb(s, 1);
		else
			ft_ra(s, 1);
	}
	if (s->stack_b[0] < s->stack_b[1])
		ft_sb(s, 1);
	ft_sort_three(s);
	ft_pa(s, 1);
	ft_pa(s, 1);
}
