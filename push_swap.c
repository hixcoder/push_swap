/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:14 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/05 12:17:57 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tester(t_stack *s)
{
	// before	
	ft_printf("\n\n");
	ft_printf("=========== Tester ============\n\n");
	ft_printf("==> Before:\n");
	for (int i = 1; s->av[i]; i++)
		ft_printf("stack_a[%d] = %s\n", i - 1, s->av[i]);
	ft_printf("\n\n");
		
	// after ft_pb
	ft_printf("==> After:\n");
	for (int i = 0; i < s->stack_a_len; i++)
		ft_printf("stack_a[%d] = %d\n", i, s->stack_a[i]);
	ft_printf("\n");
	for (int i = 0; i < s->stack_b_len; i++)
		ft_printf("stack_b[%d] = %d\n", i, s->stack_b[i]);
}

int main(int ac, char **av)
{
	t_stack	s;
	
	if (ac > 1)
	{
		s.av = av;
		ft_init_stack(&s);

		// here you write your algo for sort the stack
		ft_sa(&s);
		ft_pb(&s);
		ft_pb(&s);
		ft_pb(&s);
		ft_ra(&s);
		ft_rb(&s);
		ft_rra(&s);
		ft_rrb(&s);
		ft_sa(&s);
		ft_pa(&s);
		ft_pa(&s);
		ft_pa(&s);
		
		// here you test it
		tester(&s);

	}
	else
		return (0);
}