/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:53:05 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/12 16:02:36 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_gIn: give you the index of nbr in the sorted list
int ft_gIn(t_stack *s, int nbr)
{
    int i;

    i = -1;
    while (++i < s->sorted_len)
    {
        if (s->stack_sorted[i] == nbr)
            return (i);   
    }
    return (-1);
}

// i : is the index of the element that we will check it's list
int	ft_check_element_list(t_stack *s, int i)
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

void	ft_bring_element_list(t_stack *s, t_chosn *chosen)
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

t_chosn	ft_find_chosen_list(t_stack *s)
{
	int i;
	t_chosn j;
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
			if (ft_gIn(s, s->stack_a[i]) < ft_gIn(s, s->stack_a[j.nbr_index]))
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