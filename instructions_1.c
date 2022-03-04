/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:29 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/04 11:13:56 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ft_sa (swap a): Swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements.
*/
void ft_sa(t_stack *s)
{
	int temp;
	
	if (s->stack_a_len > 1)
	{
		temp = s->stack_a[0];
		s->stack_a[0] = s->stack_a[1];
		s->stack_a[1] = temp;   
	}
	else
		return ;
}

/*
	ft_sb (swap b): Swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements.
*/
void ft_sb(t_stack *s)
{
	int temp;
	if (s->stack_b_len > 1)
	{
		temp = s->stack_b[0];
		s->stack_b[0] = s->stack_b[1];
		s->stack_b[1] = temp;  
	}
	else
		return ;
}

/*
	ft_ss : ft_sa and ft_sb at the same time.
*/
void ft_ss(t_stack *s)
{
	ft_sa(s);
	ft_sb(s);
}

/*
	ft_pb (push to b): Take the first element at the top of a and put it at the top of b.
	Do nothing if a is empty.
*/
void ft_pb(t_stack *s)
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
		{
			free(s->stack_a);
			free(s->stack_b);
			exit(0);
		}
		s->stack_b[0] = stack_a_temp[0];
		ft_memcpy(&s->stack_b[1], stack_b_temp, sizeof(int) * (s->stack_b_len - 1));
		ft_memcpy(s->stack_a, &stack_a_temp[1], sizeof(int) * s->stack_a_len);
	}
	else
		return ;
}

/*
	ft_pa (push to a): Take the first element at the top of b and put it at the top of a.
	Do nothing if b is empty.
*/
void ft_pa(t_stack *s)
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
		{
			free(s->stack_a);
			free(s->stack_b);
			exit(0);
		}
		s->stack_a[0] = stack_b_temp[0];
		ft_memcpy(&s->stack_a[1], stack_a_temp, sizeof(int) * (s->stack_a_len - 1));
		ft_memcpy(s->stack_b, &stack_b_temp[1], sizeof(int) * s->stack_b_len);
	}
	else
		return ;
}
