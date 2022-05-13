/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:29 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/13 12:50:31 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *s)
{
	free(s->stack_a);
	free(s->stack_b);
	exit(1);
}

/*
	ft_pb (push to b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/
void ft_pb(t_stack *s, int w)
{
	int	stack_b_temp[s->stack_b_len];
	int	stack_a_temp[s->stack_a_len];
	
	if (s->stack_a != NULL)
	{
		ft_memcpy(stack_b_temp, s->stack_b, sizeof(int) * s->stack_b_len);
		ft_memcpy(stack_a_temp, s->stack_a, sizeof(int) * s->stack_a_len);
		free(s->stack_a);
		free(s->stack_b);
		s->stack_b_len++;
		s->stack_a_len--;
		s->stack_a = (int *) malloc(sizeof(int) * s->stack_a_len);
		s->stack_b = (int *) malloc(sizeof(int) * s->stack_b_len);
		if (s->stack_a == NULL || s->stack_b == NULL)
			ft_free(s);
		s->stack_b[0] = stack_a_temp[0];
		ft_memcpy(&s->stack_b[1], stack_b_temp, sizeof(int) * (s->stack_b_len - 1));
		ft_memcpy(s->stack_a, &stack_a_temp[1], sizeof(int) * s->stack_a_len);
		if (w == 1)
			ft_printf("pb\n");
	}
	else
		return ;
}

/*
	ft_pa (push to a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
*/
void ft_pa(t_stack *s, int w)
{
	int	stack_b_temp[s->stack_b_len];
	int	stack_a_temp[s->stack_a_len];
	
	if (s->stack_b != NULL)
	{
		ft_memcpy(stack_b_temp, s->stack_b, sizeof(int) * s->stack_b_len);
		ft_memcpy(stack_a_temp, s->stack_a, sizeof(int) * s->stack_a_len);
		free(s->stack_a);
		free(s->stack_b);
		s->stack_b_len--;
		s->stack_a_len++;
		s->stack_a = (int *) malloc(sizeof(int) * s->stack_a_len);
		s->stack_b = (int *) malloc(sizeof(int) * s->stack_b_len);
		if (s->stack_a == NULL || s->stack_b == NULL)
			ft_free(s);
		s->stack_a[0] = stack_b_temp[0];
		ft_memcpy(&s->stack_a[1], stack_a_temp, sizeof(int) * (s->stack_a_len - 1));
		ft_memcpy(s->stack_b, &stack_b_temp[1], sizeof(int) * s->stack_b_len);
		if (w == 1)
			ft_printf("pa\n");
	}
	else
		return ;
}
