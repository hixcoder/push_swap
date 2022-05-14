/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:06 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/14 12:48:36 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* k.go_to: is the index of the number that we will push to stack a.
* k.your_place: is the index of the number that we must move it 
*				to top of a before recieving the number with index k.go_to.
*/
void	ft_from_b_to_a(t_stack *s)
{
	t_passed	k;
	int			min_index_in_a;

	while (s->stack_b_len != 0)
	{
		ft_find_smallest_moves(s, &k);
		ft_push_it_to_a(s, &k);
	}
	min_index_in_a = ft_get_index_in_a(s, s->stack_sorted[0]);
	ft_move_to_top_of_a(s, min_index_in_a, s->stack_sorted[0]);
}

void	ft_sort_general(t_stack *s)
{
	t_chosn	chosen;

	chosen = ft_find_chosen_list(s);
	ft_push_the_unchosen_to_b(s, chosen);
	free(chosen.list);
	ft_from_b_to_a(s);
}
