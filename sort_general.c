/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:06 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/19 12:49:58 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// i : is the index of the element that we will check it's list

int ft_check_element_list(t_stack *s, int i)
{
	int len;
	int	j;
	int k;
	int l;

	len = 1;
	j = i;
	k = i;
	while (++i < s->stack_a_len)
	{
		if (s->stack_a[i] > s->stack_a[j])
		{
			j = i;
			len++;
		}
	}
	l = -1;
	while (++l < k)
	{
		if (s->stack_a[l] > s->stack_a[j])
		{
			j = l;
			len++;
		}
	}
	return (len);
}

void	ft_bring_element_list(t_stack *s, t_chosen *chosen)
{
	int i;
	int	j;
	int k;
	int l;

	i = 0;
	j = chosen->nbr_index;
	k = chosen->nbr_index;
	chosen->list = (int *) malloc(sizeof(int) * chosen->len);
	if (chosen->list == NULL)
	{
		free(chosen->list);
		exit(1);
	}
	chosen->list[i] =  s->stack_a[chosen->nbr_index];
	while (++chosen->nbr_index < s->stack_a_len)
	{
		if (s->stack_a[chosen->nbr_index] > s->stack_a[j])
		{
			j = chosen->nbr_index;
			chosen->list[++i] = s->stack_a[chosen->nbr_index];
		}
	}
	l = -1;
	while (l++ < k)
	{
		if (s->stack_a[l] > s->stack_a[j])
		{
			j = l;
			chosen->list[++i] = s->stack_a[l];
		}
	}
}

t_chosen	ft_find_chosen_list(t_stack *s)
{
	int i;
	t_chosen j;

	i = -1;
	j.len = 0;
	while (++i < s->stack_a_len)
	{
		if (j.len < ft_check_element_list(s, i))
		{
			j.nbr_index = i;
			j.len = ft_check_element_list(s, i);
		}
	}
	ft_bring_element_list(s, &j);
	return (j);
}

int ft_is_in_chosen(t_chosen chosen, int nbr)
{
	int i;

	i = -1;
	while(++i < chosen.len)
	{
		if (nbr == chosen.list[i])
			return (1);
	}
	return (0);
}

void	ft_push_the_unchosen(t_stack *s, t_chosen chosen)
{
	int	i;
	
	i = 0;
	while (s->stack_a_len != chosen.len)
	{
		if (ft_is_in_chosen(chosen, s->stack_a[i]) == 0)
			ft_pb(s);
		else
			ft_ra(s);
	}
}

void    ft_sort_general(t_stack *s)
{
	// int i;
	t_chosen    chosen;

	chosen = ft_find_chosen_list(s);
	ft_push_the_unchosen(s, chosen);
	free(chosen.list);
	
	// ft_printf("\n\n");
	// i = -1;
	// while(++i < chosen.len){
	// 	ft_printf("chosen.list[%d] = %d\n", i, chosen.list[i]);
	// }
}