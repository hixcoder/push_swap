/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:06 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/20 13:49:47 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int moves_in_a(int nbr, t_stack *s, t_passed *k)
{
	int i;
	int mid_index;
	int	moves;

	mid_index = s->stack_a_len / 2;
	k->your_place = 0;
	if (s->stack_a[s->stack_a_len - 1] < nbr && s->stack_a[0] > nbr)
		return (0);
	i = 0;
	while (++i < s->stack_a_len)
	{
		if (s->stack_a[i] < nbr && s->stack_a[i + 1] > nbr)
		{
			i++;
			break ;
		}
	}
	if (i > mid_index)
		moves = s->stack_a_len - i;
	else
		moves = i;
	k->your_place = i;
	return (moves);
}

int moves_in_b(int i, t_stack *s)
{
	int mid_index;
	int	moves;

	mid_index = s->stack_b_len / 2;
	if (i > mid_index)
		moves = s->stack_b_len - i;
	else
		moves = i;
	return (moves);
}

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
		tmp_moves = moves_in_a(s->stack_b[i], s, k) + moves_in_b(i, s);
		// ft_printf("tmp_moves = moves_in_a(s->stack_b[%d], s) + moves_in_b(%d, s) = %d + %d = %d\n", i, i, moves_in_a(s->stack_b[i], s, k), moves_in_b(i, s), moves_in_b(i, s) + moves_in_a(s->stack_b[i], s, k));
		if (moves > tmp_moves)
		{
			moves = tmp_moves;
			k->go_to = i;
		}
	}
	tmp_moves = moves_in_a(s->stack_b[k->go_to], s, k);
}

// void	ft_push_it_to_a(t_stack *s)
// {
// 	int 
// }

/*
* i.go_to: is the index of the number that we will push to stack a.
* i.your_place: is the index of the number that we must move it to top of a before 
*               recieving the number with index i.go_to.
*/
void	ft_from_b_to_a(t_stack *s)
{
	t_passed i;
	
	ft_find_smallest_moves(s, &i);
	ft_printf("\nthe best number that need to go_to is : s->stack_b[%d] = %d\n", i.go_to , s->stack_b[i.go_to]);
	ft_printf("\nthe best number that is your_place is : s->stack_a[%d] = %d\n", i.your_place , s->stack_a[i.your_place]);
	// ft_push_it_to_a(s->stack_b[i.go_to]);
	// while (s->stack_b_len != 0)
	// {
	// 	i = ft_find_smallest_moves(s);
	// 	ft_push_it_to_a(s->stack_b[i]);
	// }	
}

void    ft_sort_general(t_stack *s)
{
	// int i;
	t_chosen    chosen;

	chosen = ft_find_chosen_list(s);
	ft_push_the_unchosen_to_b(s, chosen);
	free(chosen.list);
	ft_from_b_to_a(s);
	
	// ft_printf("\n\n");
	// i = -1;
	// while(++i < chosen.len){
	// 	ft_printf("chosen.list[%d] = %d\n", i, chosen.list[i]);
	// }
}