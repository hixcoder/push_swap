/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:54:53 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/22 12:58:49 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int moves_in_a(int nbr, t_stack *s, t_passed *k)
{
	int i;
	int mid_index;
	int	moves;

	mid_index = s->stack_a_len / 2;
	// k->your_place = 0;
	if (s->stack_a[s->stack_a_len - 1] < nbr && s->stack_a[0] > nbr)
		return (0);
	i = -1;
	while (++i < s->stack_a_len)
	{
		if (s->stack_a[i] < nbr && s->stack_a[i + 1] > nbr)
		{
			i++;
			break ;
		}
	}
	if (i > mid_index)
	{
		k->a_move_type = "rra";
		moves = s->stack_a_len - i;
	}
	else
	{
		k->a_move_type = "ra";
		moves = i;
	}
	k->your_place = i;
	return (moves);
}

int moves_in_b(int i, t_stack *s, t_passed *k)
{
	int mid_index;
	int	moves;

	mid_index = s->stack_b_len / 2;
	if (i > mid_index)
	{
		k->b_move_type = "rra";
		moves = s->stack_b_len - i;
	}
	else
	{
		k->b_move_type = "ra";
		moves = i;
	}
	return (moves);
}

// int moves_in_a(int nbr, t_stack *s, t_passed *k)
// {
// 	int i;
// 	int mid_index;
// 	int	moves;

// 	mid_index = s->stack_a_len / 2;
// 	k->your_place = 0;
// 	if (s->stack_a[s->stack_a_len - 1] < nbr && s->stack_a[0] > nbr)
// 		return (0);
// 	i = -1;
// 	while (++i < s->stack_a_len)
// 	{
// 		if (s->stack_a[i] < nbr && s->stack_a[i + 1] > nbr)
// 		{
// 			i++;
// 			break ;
// 		}
// 	}
// 	if (i > mid_index)
// 		moves = s->stack_a_len - i;
// 	else
// 		moves = i;
// 	k->your_place = i;
// 	return (moves);
// }

// int moves_in_b(int i, t_stack *s)
// {
// 	int mid_index;
// 	int	moves;

// 	mid_index = s->stack_b_len / 2;
// 	if (i > mid_index)
// 		moves = s->stack_b_len - i;
// 	else
// 		moves = i;
// 	return (moves);
// }

/* I used this line: tmp_moves = moves_in_a(s->stack_b[k->go_to], s, k);
* only for know the right value of k->your_place .
*/
void	ft_find_smallest_moves(t_stack *s, t_passed *k)
{
	int i;
	int	moves;
	int	tmp_moves;

	i = -1;
	moves = 2147483647;
	while (++i < s->stack_b_len)
	{
		tmp_moves = moves_in_a(s->stack_b[i], s, k) + moves_in_b(i, s, k);
		// k->a_moves = moves_in_a(s->stack_b[i], s, k);
		// 	k->b_moves = moves_in_b(i, s, k);
		// ft_printf("moves_in_b(%d, s, k) = %d\n",i, moves_in_b(i, s, k));
		// ft_printf("moves_in_a(s->stack_b[%d], s) = %d\n", i, moves_in_a(s->stack_b[i], s, k));
		// ft_printf("i->b_moves = %d\ni->a_moves = %d\n",k->b_moves, k->a_moves);
		// ft_printf("tmp_moves = moves_in_a(s->stack_b[%d], s) + moves_in_b(%d, s, k) = %d + %d = %d\n\n",i, i, moves_in_a(s->stack_b[i], s, k), moves_in_b(i, s, k), moves_in_b(i, s, k) + moves_in_a(s->stack_b[i], s, k));
		if (moves > tmp_moves)
		{
			k->a_moves = moves_in_a(s->stack_b[i], s, k);
			k->b_moves = moves_in_b(i, s, k);
			moves = tmp_moves;
			k->go_to = i;
		}
	}
	tmp_moves = moves_in_a(s->stack_b[k->go_to], s, k);
}