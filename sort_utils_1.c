/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:53:05 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/25 03:02:00 by hboumahd         ###   ########.fr       */
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
	// int	inst[s->stack_a_len];

	i = -1;
	j.len = 0;
	while (++i < s->stack_a_len)
	{
		if (j.len < ft_check_element_list(s, i))
		{
			j.nbr_index = i;
			j.len = ft_check_element_list(s, i);
		}
		else if (j.len == ft_check_element_list(s, i))
		{
			if (ft_get_index_in_sorted(s, s->stack_a[i]) < ft_get_index_in_sorted(s, s->stack_a[j.nbr_index]))
			{
				j.nbr_index = i;
				j.len = ft_check_element_list(s, i);
			}
		}
	}
	// ft_printf("j.nbr_index = %d\n",j.len);
	// ft_printf("j.len = %d\n",j.len);
	// for (int i = 0; i < s->stack_a_len; i++)
	// {
	// 	ft_printf("inst[%d] = %d\n",i, inst[i]);	
	// }
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

void	ft_push_the_unchosen_to_b(t_stack *s, t_chosen chosen)
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
