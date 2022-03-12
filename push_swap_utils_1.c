/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:13:53 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/12 04:42:17 by hboumahd         ###   ########.fr       */
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

}