/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:07:30 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/13 19:00:54 by hboumahd         ###   ########.fr       */
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
	else if (i == 3)
	{
		for (int i = 0; i < s->stack_a_len; i++)
			ft_printf("stack_a[%d] = %d\n", i, s->stack_a[i]);
		ft_printf("\n");
		for (int i = 0; i < s->stack_b_len; i++)
			ft_printf("stack_b[%d] = %d\n", i, s->stack_b[i]);
	}
}

void ft_make_instr(char *line, t_stack *s)
{
	int i;

	i = ft_memcmp(line, "sa\n", 3);
	//ft_printf("this : %d\n", i);
	if (ft_memcmp(line, "sa\n", 3) == 0)
		ft_sa(s, 0);
	else if (ft_memcmp(line, "sb\n", 3) == 0)
		ft_sb(s, 0);
	else if (ft_memcmp(line, "ss\n", 3) == 0)
		ft_ss(s, 0);
	else if (ft_memcmp(line, "pb\n", 3) == 0)
		ft_pb(s, 0);
	else if (ft_memcmp(line, "pa\n", 3) == 0)
		ft_pa(s, 0);
	else if (ft_memcmp(line, "ra\n", 3) == 0)
		ft_ra(s, 0);
	else if (ft_memcmp(line, "rb\n", 3) == 0)
		ft_rb(s, 0);
	else if (ft_memcmp(line, "rr\n", 3) == 0)
		ft_rr(s, 0);
	else if (ft_memcmp(line, "rra\n", 4) == 0)
		ft_rra(s, 0);
	else if (ft_memcmp(line, "rrb\n", 4) == 0)
		ft_rrb(s, 0);
	else if (ft_memcmp(line, "rrr\n", 4) == 0)
		ft_rrr(s, 0);
	else
	{
		printf("error\n");
		exit(1);
	}
}

void ft_read_instr(t_stack *s)
{
	int i;
	char	*line;

	i = 0;
	line = get_next_line(0);
	// ft_make_instr(line, s);
	// free(line);
	while (line)
	{
		ft_make_instr(line, s);
		line = get_next_line(0);
		if(!line)
			break ;
		free(line);
	}
	return ;
}

int main(int ac, char **av)
{
	t_stack	s;
	
	if (ac > 1)
	{
		s.av = av;
		s.stack_a_len = ac - 1;
		s.stack_b_len = 0;
		ft_init_stack(&s);
		ft_read_instr(&s);
		// tester(&s, 2);
		ft_checker(&s);
	}
	else
		return (0);
}