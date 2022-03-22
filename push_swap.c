/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:14 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/22 14:28:23 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tester(t_stack *s, int i)
{
	if (i == 1)
	{
		// before	
		ft_printf("\n\n");
		ft_printf("=========== Tester ============\n\n");
		ft_printf("==> Before:\n");
		for (int i = 1; s->av[i]; i++)
			ft_printf("stack_a[%d] = %s\n", i - 1, s->av[i]);
		ft_printf("\n\n");

		ft_printf("==> selection sort algo:\n");
		for (int i = 0; i < s->stack_a_len; i++)
			ft_printf("stack_sorted[%d] = %d\n", i, s->stack_sorted[i]);
		ft_printf("\n\n");
		ft_printf("==> my algo:\n");
	}
	else if (i == 2)
	{
		// after ft_pb
		ft_printf("\n\n==> After:\n");
		for (int i = 0; i < s->stack_a_len; i++)
			ft_printf("stack_a[%d] = %d\n", i, s->stack_a[i]);
		ft_printf("\n");
		for (int i = 0; i < s->stack_b_len; i++)
			ft_printf("stack_b[%d] = %d\n", i, s->stack_b[i]);
		if (ft_memcmp(s->stack_sorted, s->stack_a, s->sorted_len * sizeof(int)) == 0)
			ft_printf("\n\n=====> Your list is sorted, Congratulation!\n\n");
		else
			ft_printf("\n\n=====> Your list is not sorted, Sorry!\n\n");
	}
}

// Insertion Sort algorithm
void	ft_mysort(t_stack *s)
{
	int	j;

	j = 0;
	while (s->stack_a_len != 0)
	{
		if (s->stack_a[0] == s->stack_sorted[j])
		{
			ft_pb(s);
			j++;
		}
		ft_rra(s);
	}
	while (s->stack_b_len != 0)
		ft_pa(s);
}

int main(int ac, char **av)
{
	t_stack	s;
	
	if (ac > 1)
	{
		s.av = av;
		ft_init_stack(&s);
		if (s.stack_a_len == 1)
			return (0);
		// please debug this : ./push_swap 427 195 232 505 323 59 277 566 141 109
		// the problem may be in ft_move_both func
		tester(&s, 1);

		if (s.stack_a_len == 3)
			ft_sort_three(&s);
		else if (s.stack_a_len == 5)
			ft_sort_five(&s);
		else
			ft_sort_general(&s);
		
		tester(&s, 2);
		// while (1);
	}
	else
		return (0);
}