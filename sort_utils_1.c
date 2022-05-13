/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:53:05 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/13 12:55:41 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_in_chosen(t_chosn chosen, int nbr)
{
	int i;

	i = -1;
	while(++i < chosen.len)
	{
		if (nbr == chosen.list[i])
			return (1);
	}
	return (0);
}

void	ft_push_the_unchosen_to_b(t_stack *s, t_chosn chosen)
{
	int	i;
	
	i = 0;
	while (s->stack_a_len != chosen.len)
	{
		if (ft_is_in_chosen(chosen, s->stack_a[i]) == 0)
			ft_pb(s, 1);
		else
			ft_ra(s, 1);
	}
}
