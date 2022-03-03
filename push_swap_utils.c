/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:45:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/03 22:22:56 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	
	this func exit the program if :
 		->the nbr is not integer (string)
 		->the nbr is not in the range of integers (long)
 		->the nbr is already exist (duplication).
*/
void    ft_error()
{
    ft_printf("Error\n");
    exit(0);
}

/*	
	this func check 2 things:
 	if the nbr is not integer (long)
 	if the nbr is already exist or not
*/
void ft_check_nbr(long *nbr, int sign, t_stack *s, int i)
{
	*nbr = (*nbr) * sign;
    if (*nbr < -2147483648 || *nbr > 2147483647)
        ft_error();
	while (i >= 0)
	{
		if (*nbr == s->stack[i])
			ft_error();
		i--;
	}
}

int	ft_atoi(const char *str, t_stack *s, int index)
{
	int	    i;
	long	nbr;
	int 	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr * 10 + (str[i++] - '0');
		else
			ft_error();
	}
    ft_check_nbr(&nbr, sign, s, index);
	return ((int) nbr);
}

int	ft_stack_len(char **av)
{
	int i;

	i = 1;
	while (av[i])
		i++;
	return (i);
}

void	ft_init_stack(t_stack	*s)
{
	int	i;
	
	if (s == NULL)
		return ;
	s->stack_len = ft_stack_len(s->av) - 1;
	s->stack = (int *) malloc(sizeof(int) * s->stack_len);
	if (s->stack == NULL)
	{
		free(s->stack);
		exit(0);
	}
	i = -1;
	while (++i < s->stack_len)
	{
		s->stack[i] = ft_atoi(s->av[i + 1], s, i); 
	}
}