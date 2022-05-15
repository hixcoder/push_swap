/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:53:05 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/15 11:11:14 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_ind: give you the index of nbr in the sorted list
int	ft_ind(t_stack *s, int nbr)
{
	int	i;

	i = -1;
	while (++i < s->sorted_len)
	{
		if (s->stack_sorted[i] == nbr)
			return (i);
	}
	return (-1);
}

// i : is the index of the element that we will check it's list
// this function return the lenght of the checked list.
int	ft_check_element_list(t_stack *s, int i)
{
	int	len;
	int	j;
	int	l;

	len = 1;
	j = i;
	l = i;
	while (++i < s->stack_a_len)
	{
		if (s->stack_a[i] > s->stack_a[j])
		{
			j = i;
			len++;
		}
	}
	i = -1;
	while (++i < l)
	{
		if (s->stack_a[i] > s->stack_a[j])
		{
			j = i;
			len++;
		}
	}
	return (len);
}

void	ft_init_things(t_stack *s, int *j, int *k, t_chosn *chosen)
{
	*j = chosen->nbr_index;
	*k = chosen->nbr_index;
	chosen->list = (int *) malloc(sizeof(int) * chosen->len);
	if (chosen->list == NULL)
	{
		free(chosen->list);
		chosen->list = NULL;
		ft_exit(s, 1);
	}
}

void	ft_bring_element_list(t_stack *s, t_chosn *chosen)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	ft_init_things(s, &j, &k, chosen);
	chosen->list[i] = s->stack_a[chosen->nbr_index];
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

// here we find the long sorted list that will stay on stack a
t_chosn	ft_find_chosen_list(t_stack *s)
{
	int		i;
	int		checked_list_len;
	t_chosn	j;

	i = -1;
	j.len = 0;
	while (++i < s->stack_a_len)
	{
		checked_list_len = ft_check_element_list(s, i);
		if (j.len < checked_list_len)
		{
			j.nbr_index = i;
			j.len = checked_list_len;
		}
		else if (j.len == checked_list_len)
		{
			if (ft_ind(s, s->stack_a[i]) < ft_ind(s, s->stack_a[j.nbr_index]))
			{
				j.nbr_index = i;
				j.len = checked_list_len;
			}
		}
	}
	ft_bring_element_list(s, &j);
	return (j);
}
