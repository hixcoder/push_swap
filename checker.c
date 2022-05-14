/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:07:30 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/14 12:01:57 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(t_stack *s)
{
	int	cmp;

	cmp = ft_memcmp(s->stack_sorted, s->stack_a, s->sorted_len * sizeof(int));
	if (cmp == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ft_make_instr(char *line, t_stack *s)
{
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
		ft_exit(s, 1);
}

void	ft_read_instr(t_stack *s)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(0);
	while (line)
	{
		ft_make_instr(line, s);
		line = get_next_line(0);
		if (!line)
			break ;
		free(line);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_stack	s;

	if (ac > 1)
	{
		s.av = av;
		s.stack_a_len = ac - 1;
		s.stack_b_len = 0;
		ft_init_stack(&s, 1);
		ft_read_instr(&s);
		ft_checker(&s);
	}
	else
		return (0);
}
