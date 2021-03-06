/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:54:53 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/15 12:14:53 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_index_in_a(t_stack *s, int nbr)
{
	int	i;

	i = -1;
	while (++i < s->stack_a_len)
	{
		if (s->stack_a[i] == nbr)
			return (i);
	}
	return (-1);
}

void	ft_move_to_top_of_a(t_stack *s, int i, int nbr)
{
	int	mid_a;

	mid_a = s->stack_a_len / 2;
	while (s->stack_a[0] != nbr)
	{
		if (i > mid_a)
			ft_rra(s, 1);
		else
			ft_ra(s, 1);
	}
}

void	ft_move_to_top_of_b(t_stack *s, int i, int nbr)
{
	int	mid_b;

	mid_b = s->stack_b_len / 2;
	while (s->stack_b[0] != nbr)
	{
		if (i > mid_b)
			ft_rrb(s, 1);
		else
			ft_rb(s, 1);
	}
}

void	ft_move_both(t_stack *s, int shared_moves, char *move_type, t_passed *k)
{
	int	j;

	j = -1;
	while (++j < shared_moves)
	{
		if (ft_memcmp(move_type, "rr_both", sizeof(char) * 7) == 0)
		{
			ft_rr(s, 1);
			k->your_place--;
			k->go_to--;
		}
		else
		{
			ft_rrr(s, 1);
			k->your_place++;
			k->go_to++;
		}
		if (k->your_place == s->stack_a_len)
			k->your_place = 0;
		if (k->go_to == s->stack_b_len)
			k->go_to = 0;
	}
}

void	ft_push_it_to_a(t_stack *s, t_passed *k)
{
	int	shared_moves;

	shared_moves = 0;
	if (k->a_move_type == k->b_move_type && k->a_moves > k->b_moves)
		shared_moves = k->b_moves;
	else if (k->a_move_type == k->b_move_type && k->a_moves <= k->b_moves)
		shared_moves = k->a_moves;
	if (shared_moves > 0)
	{
		ft_move_both(s, shared_moves, k->b_move_type, k);
		shared_moves = 0;
	}
	ft_move_to_top_of_a(s, k->your_place, s->stack_a[k->your_place]);
	ft_move_to_top_of_b(s, k->go_to, s->stack_b[k->go_to]);
	ft_pa(s, 1);
}
