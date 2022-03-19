/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:06 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/19 12:21:41 by hboumahd         ###   ########.fr       */
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
	ft_printf("chosen.nbr_index = %d\n", chosen->nbr_index);
	ft_printf("chosen.len = %d\n\n", chosen->len);
	chosen->list = (int *) malloc(sizeof(int) * chosen->len);
	if (chosen->list == NULL)
	{
		free(chosen->list);
		exit(1);
	}
	chosen->list[i] =  s->stack_a[chosen->nbr_index];
	ft_printf("s->stack_a[%d] = %d", chosen->nbr_index, s->stack_a[chosen->nbr_index]);
	ft_printf("   chosen->list[%d] = %d\n", i, chosen->list[i]);
	while (++chosen->nbr_index < s->stack_a_len)
	{
		ft_printf("s->stack_a[%d] = %d", chosen->nbr_index, s->stack_a[chosen->nbr_index]);
		if (s->stack_a[chosen->nbr_index] > s->stack_a[j])
		{
			j = chosen->nbr_index;
			chosen->list[++i] = s->stack_a[chosen->nbr_index];
			ft_printf("   chosen->list[%d] = %d\n", i, chosen->list[i]);
		}else
			ft_printf("\n");
	}
	ft_printf("\n\n");
	l = -1;
	while (l++ < k)
	{
		ft_printf("s->stack_a[%d] = %d", l, s->stack_a[l]);
		if (s->stack_a[l] > s->stack_a[j])
		{
			j = l;
			chosen->list[++i] = s->stack_a[l];
			ft_printf("   chosen->list[%d] = %d\n", i, chosen->list[i]);
		}else
			ft_printf("\n");
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

void    ft_sort_general(t_stack *s)
{
	int i;
	t_chosen    chosen;

	chosen = ft_find_chosen_list(s);
	
	ft_printf("\n\n");
	i = -1;
	while(++i < chosen.len){
		ft_printf("chosen.list[%d] = %d\n", i, chosen.list[i]);
	}
}