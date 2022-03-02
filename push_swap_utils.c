/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 10:45:50 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/02 12:51:42 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_error()
{
    ft_printf("Error\n");
    exit(0);
}

void ft_check_nbr(long *nbr, int sign)
{
	*nbr = (*nbr) * sign;
    if (*nbr < -2147483648 || *nbr > 2147483647)
        ft_error();
	else
		return ;
}
int	ft_atoi(const char *str)
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
    ft_check_nbr(&nbr, sign);
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

int	*ft_init_stack(char **av)
{
	int *stack;
	int	i;

	stack = (int *) malloc(sizeof(int) * ft_stack_len(av));
	if (stack == NULL)
		return (0);
	i = 0;
	while (av[++i])
		stack[i] = ft_atoi(av[i]);
	return (stack);
}