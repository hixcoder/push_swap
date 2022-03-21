/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:13:53 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/21 15:48:56 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	str1;
	unsigned char	str2;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (i < n)
	{
		str1 = ps1[i];
		str2 = ps2[i];
		if (str1 != str2)
			return (str1 - str2);
		i++;
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// implement the selection sort algorithm
void ft_sortalgo(t_stack *s)
{
	int i;
	int	j;
	
	s->sorted_len = s->stack_a_len;
	s->stack_sorted = (int *) malloc(sizeof(int) * s->stack_a_len);
	if (s->stack_sorted == NULL)
	{
		free(s->stack_a);
		exit(1);
	}
	ft_memcpy(s->stack_sorted, s->stack_a, sizeof(int) * s->stack_a_len);
	i = -1;
	while(++i < s->stack_a_len)
	{
		j = i + 1;
		while (j < s->stack_a_len)
		{
			if (s->stack_sorted[i] > s->stack_sorted[j])
				ft_swap(&s->stack_sorted[i], &s->stack_sorted[j]);
			j++;
		}	
	}
	s->mid = s->stack_sorted[s->sorted_len / 2];
	s->max = s->stack_sorted[s->sorted_len - 1];
	s->min = s->stack_sorted[0];
}

// this func return the min in a list of int.
int ft_get_min(int *list, int list_len)
{
	int i;
	int j;
	
	j = list[0];
	i = 0;
	while (++i < list_len)
	{
		if (list[i] < j)
			j = list[i];
	}
	return (j);
}