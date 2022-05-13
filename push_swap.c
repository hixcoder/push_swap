/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:14 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/13 19:01:18 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	s;
	
	if (ac > 1)
	{
		s.av = av;
		s.stack_a_len = ac - 1;
		s.stack_b_len = 0;
		ft_init_stack(&s);
		if (s.stack_a_len == 3)
			ft_sort_three(&s);
		else if (s.stack_a_len == 5)
			ft_sort_five(&s);
		else
			ft_sort_general(&s);
		
		// tester(&s, 2);
	}
	else
		return (0);
}