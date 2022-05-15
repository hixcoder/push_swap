/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:29 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/15 10:59:22 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_temp(int *a_temp, int *b_temp)
{
	free(a_temp);
	free(b_temp);
	a_temp = NULL;
	b_temp = NULL;
}

void	ft_make_back_up(t_stack *s, int *a_temp, int *b_temp)
{
	ft_memcpy(b_temp, s->stack_b, sizeof(int) * s->stack_b_len);
	ft_memcpy(a_temp, s->stack_a, sizeof(int) * s->stack_a_len);
	free(s->stack_a);
	free(s->stack_b);
}

/*
	ft_pb (push to b): Take the first element at the top of a 
					   and put it at the top of b.
	Do nothing if a is empty.
*/
void	ft_pb(t_stack *s, int w)
{
	int	*a_temp;
	int	*b_temp;

	a_temp = (int *) malloc(sizeof(int) * s->stack_a_len);
	b_temp = (int *) malloc(sizeof(int) * s->stack_b_len);
	if (b_temp == NULL || a_temp == NULL)
		ft_free_temp(a_temp, b_temp);
	if (s->stack_a != NULL)
	{
		ft_make_back_up(s, a_temp, b_temp);
		s->stack_b_len++;
		s->stack_a_len--;
		s->stack_a = (int *) malloc(sizeof(int) * s->stack_a_len);
		s->stack_b = (int *) malloc(sizeof(int) * s->stack_b_len);
		if (s->stack_a == NULL || s->stack_b == NULL)
			ft_exit(s, 1);
		s->stack_b[0] = a_temp[0];
		ft_memcpy(&s->stack_b[1], b_temp, sizeof(int) * (s->stack_b_len - 1));
		ft_memcpy(s->stack_a, &a_temp[1], sizeof(int) * s->stack_a_len);
		if (w == 1)
			ft_printf("pb\n");
		ft_free_temp(a_temp, b_temp);
	}
	else
		return ;
}

/*
	ft_pa (push to a): Take the first element at the top of b 
						and put it at the top of a.
	Do nothing if b is empty.
*/
void	ft_pa(t_stack *s, int w)
{
	int	*a_temp;
	int	*b_temp;

	a_temp = (int *) malloc(sizeof(int) * s->stack_a_len);
	b_temp = (int *) malloc(sizeof(int) * s->stack_b_len);
	if (b_temp == NULL || a_temp == NULL)
		ft_free_temp(a_temp, b_temp);
	if (s->stack_b != NULL)
	{
		ft_make_back_up(s, a_temp, b_temp);
		s->stack_b_len--;
		s->stack_a_len++;
		s->stack_a = (int *) malloc(sizeof(int) * s->stack_a_len);
		s->stack_b = (int *) malloc(sizeof(int) * s->stack_b_len);
		if (s->stack_a == NULL || s->stack_b == NULL)
			ft_exit(s, 1);
		s->stack_a[0] = b_temp[0];
		ft_memcpy(&s->stack_a[1], a_temp, sizeof(int) * (s->stack_a_len - 1));
		ft_memcpy(s->stack_b, &b_temp[1], sizeof(int) * s->stack_b_len);
		if (w == 1)
			ft_printf("pa\n");
		ft_free_temp(a_temp, b_temp);
	}
	else
		return ;
}
