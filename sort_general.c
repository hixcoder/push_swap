/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:06 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/23 15:33:04 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_index_in_a(t_stack *s, int nbr)
{
    int i;

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
	int mid_a;
	
	mid_a = s->stack_a_len / 2;
	while (s->stack_a[0] != nbr)
	{
		if (i > mid_a)
			ft_rra(s);
		else
			ft_ra(s);
	}
}

void	ft_move_to_top_of_b(t_stack *s, int i, int nbr)
{
	int mid_b;
	
	mid_b = s->stack_b_len / 2;
	while (s->stack_b[0] != nbr)
	{
		if (i > mid_b)
			ft_rrb(s);
		else
			ft_rb(s);
	}
}

void	ft_move_both(t_stack *s, int len, char *move_type, t_passed *i)
{
	int j;

	j = -1;
	while (++j < len)
	{
		if (ft_memcmp(move_type, "rr_both", sizeof(char) * 7) == 0)
		{
			ft_rr(s);
			i->your_place--;
			i->go_to--;
		}
		else
		{
			ft_rrr(s);
			i->your_place++;
			i->go_to++;
		}
		if (i->your_place == s->stack_a_len)
			i->your_place = 0;
		if (i->go_to == s->stack_b_len)
			i->go_to = 0;
	}
}

void	ft_push_it_to_a(t_stack *s, t_passed *i)
{
	int	shared_moves;

	if (i->a_moves > i->b_moves)
		shared_moves = i->b_moves;
	else
		shared_moves = i->a_moves;
	// ft_printf("i->b_moves = %d\ni->a_moves = %d\nshared_moves = %d\n\n",i->b_moves, i->a_moves, shared_moves);
	if (i->a_move_type == i->b_move_type && shared_moves > 0)
		ft_move_both(s, shared_moves, i->b_move_type, i);
	if (i->a_moves > 0)
		ft_move_to_top_of_a(s, i->your_place, s->stack_a[i->your_place]);
	if (i->b_moves > 0)
		ft_move_to_top_of_b(s, i->go_to, s->stack_b[i->go_to]);
	ft_pa(s);
}

void	ft_remove_min_from_b(t_stack *s)
{
	int	i;
	int	min_index_in_a;

	i = -1;
	while (++i < s->stack_b_len)
	{
		// ft_printf("s->stack_b[i] = %d vs s->stack_sorted[0] = %d\n",s->stack_b[i],s->stack_sorted[0]);
		if (s->stack_b[i] == s->stack_sorted[0])
		{
			// ft_printf("s->stack_b[i] = %d vs s->stack_sorted[0] = %d\n",s->stack_b[i],s->stack_sorted[0]);
			min_index_in_a = ft_get_index_in_a(s, ft_get_min(s->stack_a, s->stack_a_len));
			// ft_printf("ft_get_min(s->stack_a, s->stack_a_len) = %d\n\n", ft_get_min(s->stack_a, s->stack_a_len));
			// ft_printf("min_index_in_a = %d\n\n", min_index_in_a);
			
			ft_move_to_top_of_a(s, min_index_in_a, s->stack_a[min_index_in_a]);
			ft_move_to_top_of_b(s, i, s->stack_sorted[0]);
			ft_pa(s);
			break ;
		}			
	}
}
/*
* i.go_to: is the index of the number that we will push to stack a.
* i.your_place: is the index of the number that we must move it to top of a before 
*               recieving the number with index i.go_to.
*/
void	ft_from_b_to_a(t_stack *s)
{
	t_passed i;
	int	min_index_in_a;
	
	while (s->stack_b_len != 0)
	{
		ft_find_smallest_moves(s, &i);
		ft_push_it_to_a(s, &i);
		// ft_printf("\nthe best number that need to go_to is : s->stack_b[%d] = %d\n", i.go_to , s->stack_b[i.go_to]);
		// ft_printf("\nthe best number that is your_place is : s->stack_a[%d] = %d\n", i.your_place , s->stack_a[i.your_place]);
	}
	min_index_in_a = ft_get_index_in_a(s, s->stack_sorted[0]);
	ft_move_to_top_of_a(s, min_index_in_a, s->stack_sorted[0]);
}

void    ft_sort_general(t_stack *s)
{
	t_chosen    chosen;

	chosen = ft_find_chosen_list(s);
	ft_push_the_unchosen_to_b(s, chosen);
	// ft_printf("\n\n==> After push_the_unchosen_to_b:\n");
	// tester(s, 3);
	free(chosen.list);
	ft_from_b_to_a(s);
	// tester(s, 2);
}