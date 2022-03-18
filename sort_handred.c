/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_handred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:40:41 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/16 21:52:08 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_chunk(t_stack *s, int chunck_num)
{
	int	*chunck;

	chunck = malloc(sizeof(int) * 20);
	if (chunck == NULL)
	{
		free(chunck);
		exit(1);
	}
	if (chunck_num == 1)
		ft_memcpy(chunck, &s->stack_sorted[0], 20 * sizeof(int));
	else if (chunck_num == 2)
		ft_memcpy(chunck, &s->stack_sorted[20], 20 * sizeof(int));
	else if (chunck_num == 3)
		ft_memcpy(chunck, &s->stack_sorted[40], 20 * sizeof(int));
	else if (chunck_num == 4)
		ft_memcpy(chunck, &s->stack_sorted[60], 20 * sizeof(int));
	else if (chunck_num == 5)
		ft_memcpy(chunck, &s->stack_sorted[80], 20 * sizeof(int));
	else
		return (NULL);
	return (chunck);
}

int	ft_is_in_chunk(int *chunk, int nbr)
{
	int	i;

	i = -1;
	while(i++ < 20)
	{
		if (chunk[i] == nbr)
			return (1);
	}
	return (0);
}

t_scanned_nbr ft_scan_from_top(t_stack *s, int chunck_num)
{
	int i;
	int chunck[20];
	t_scanned_nbr scanned_nbr;

	ft_memcpy(chunck, ft_get_chunk(s, chunck_num), 20 * sizeof(int));
	scanned_nbr.nbr = 0;
	scanned_nbr.moves_needed = 0;
	scanned_nbr.moves_type = "ra";
	i = -1;
	while (++i < 50)
	{
		if (ft_is_in_chunk(chunck, s->stack_a[i]) == 1)
		{
			scanned_nbr.nbr = s->stack_a[i];
			scanned_nbr.moves_needed = i;
			break ;
		}
	}
	return (scanned_nbr);
}

t_scanned_nbr ft_scan_from_bottom(t_stack *s, int chunck_num)
{
	int i;
	int chunck[20];
	t_scanned_nbr scanned_nbr;

	ft_memcpy(chunck, ft_get_chunk(s, chunck_num), 20 * sizeof(int));
	scanned_nbr.nbr = 0;
	scanned_nbr.moves_needed = 0;
	scanned_nbr.moves_type = "rra";
	i = 100;
	while (--i >= 50)
	{
		if (ft_is_in_chunk(chunck, s->stack_a[i]) == 1)
		{
			scanned_nbr.nbr = s->stack_a[i];
			scanned_nbr.moves_needed = 100 - i;
			break ;
		}
	}
	return (scanned_nbr);
}

void	ft_move_to_top_of_stack(t_stack *s, t_scanned_nbr *chosen_nbr)
{
	if (ft_memcmp(chosen_nbr->moves_type, "rra", 3) == 0)
	{
		while (chosen_nbr->moves_needed > 0)
		{
			ft_rra(s);
			chosen_nbr->moves_needed--;
		}
	}
	else if (ft_memcmp(chosen_nbr->moves_type, "ra", 2) == 0)
	{
		while (chosen_nbr->moves_needed > 0)
		{
			ft_ra(s);
			chosen_nbr->moves_needed--;
		}
	}
	
}

void	ft_sort_handred(t_stack *s)
{
	// int	j;
	t_scanned_nbr scanned_from_top;
	t_scanned_nbr scanned_from_bottom;
	t_scanned_nbr chosen_nbr;
	
	scanned_from_top = ft_scan_from_top(s, 1);
	scanned_from_bottom = ft_scan_from_bottom(s, 1);
	if (scanned_from_top.moves_needed > scanned_from_bottom.moves_needed)
		chosen_nbr = scanned_from_bottom;
	else
		chosen_nbr = scanned_from_top;
	ft_move_to_top_of_stack(s, &chosen_nbr);
	// ft_printf("scanned_from_top.nbr = %d  scanned_from_top.moves_needed = %d\n",scanned_from_top.nbr, scanned_from_top.moves_needed);
	// ft_printf("scanned_from_bottom.nbr = %d  scanned_from_bottom.moves_needed = %d\n",scanned_from_bottom.nbr, scanned_from_bottom.moves_needed);
	// ft_printf("chosen_nbr.nbr = %d  chosen_nbr.moves_needed = %d\n",chosen_nbr.nbr, chosen_nbr.moves_needed);
	// j = 0;
	// while (s->stack_a_len != 0)
	// {
	// 	if (s->stack_a[0] == s->stack_sorted[j])
	// 	{
	// 		ft_pb(s);
	// 		j++;
	// 	}
	// 	ft_rra(s);
	// }
	// while (s->stack_b_len != 0)
	// 	ft_pa(s);
}
