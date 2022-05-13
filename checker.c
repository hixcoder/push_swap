/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:07:30 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/13 15:37:47 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_checker(t_stack *s)
{
	if (ft_memcmp(s->stack_sorted, s->stack_a, s->sorted_len * sizeof(int)) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	
}

int main(int ac, char **av)
{
	t_stack	s;
	
	if (ac > 1)
	{
		s.av = av;
		s.stack_a_len = ac - 1;
		s.stack_b_len = 0;
		ft_init_stack(&s, 1);
		if (s.stack_a_len == 1)
			return (0);
		if (s.stack_a_len == 3)
			ft_sort_three(&s);
		else if (s.stack_a_len == 5)
			ft_sort_five(&s);
		else
			ft_sort_general(&s);
		
		ft_checker(&s);
	}
	else
		return (0);
}