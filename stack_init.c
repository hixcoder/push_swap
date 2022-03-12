/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:13:41 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/12 04:42:36 by hboumahd         ###   ########.fr       */
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
    exit(1);
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
		ft_printf("nbr= %d    =vs=    s->stack_a[%d]= %d\n",*nbr, i, s->stack_a[i]);
		if (*nbr == s->stack_a[i])
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
	if (str[i] == '-')
	{
		sign = -1;
		i++;
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
	
	s->stack_a_len = ft_stack_len(s->av) - 1;
	s->stack_b_len = 0;
	s->stack_a = (int *) malloc(sizeof(int) * s->stack_a_len);
	if (s->stack_a == NULL)
	{
		free(s->stack_a);
		exit(1);
	}
	i = -1;
	while (++i < s->stack_a_len)
		s->stack_a[i] = ft_atoi(s->av[i + 1], s, i);
	ft_sortalgo(s);
}