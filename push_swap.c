/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:14 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/04 13:15:06 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	s;
	
	if (ac > 1)
	{
		s.av = av;
		ft_init_stack(&s);

		// before	
		for (int i = 0; i < s.stack_a_len; i++)
			ft_printf("stack_a[%d] = %d\n", i, s.stack_a[i]);
		ft_printf("\n");
		for (int i = 0; i < s.stack_b_len; i++)
			ft_printf("stack_b[%d] = %d\n", i, s.stack_b[i]);

		ft_printf("\n\n");
		// ft_pb(&s);
		// ft_pb(&s);
		// ft_pb(&s);
		// // ft_pb(&s);
		// // ft_pb(&s);
		// // ft_pb(&s);
		// ft_rr(&s);


		// after ft_pb	
		for (int i = 0; i < s.stack_a_len; i++)
			ft_printf("stack_a[%d] = %d\n", i, s.stack_a[i]);
		ft_printf("\n");
		for (int i = 0; i < s.stack_b_len; i++)
			ft_printf("stack_b[%d] = %d\n", i, s.stack_b[i]);

		// ft_printf("\n\n");
		// ft_rb(&s);

		// // after ft_pb	
		// for (int i = 0; i < s.stack_a_len; i++)
		// 	ft_printf("stack_a[%d] = %d\n", i, s.stack_a[i]);
		// ft_printf("\n");
		// for (int i = 0; i < s.stack_b_len; i++)
		// 	ft_printf("stack_b[%d] = %d\n", i, s.stack_b[i]);
		// while(1)
		// 	;
	}
	else
		return (0);
}