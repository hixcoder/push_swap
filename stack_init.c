/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:13:41 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/13 09:25:41 by hboumahd         ###   ########.fr       */
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

int	ft_atoi(const char *str)
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
	nbr = nbr * sign;
    if (nbr < -2147483648 || nbr > 2147483647)
        ft_error();
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

void	ft_check_dup(t_stack *s)
{
	int i;
	int j;
	
	i = -1;
	while (++i < s->stack_a_len)
	{
		j = i;
		while (++j < s->stack_a_len)
		{
			if (s->stack_a[i] == s->stack_a[j])
				ft_error();
		}
	}
}

void	ft_is_sorted(t_stack *s)
{
	int cmp;

	cmp = ft_memcmp(s->stack_a, s->stack_sorted, s->stack_a_len * sizeof(int));
	if (cmp == 0)
		exit(0);
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
		s->stack_a[i] = ft_atoi(s->av[i + 1]);
	ft_check_dup(s);
	ft_sortalgo(s);
	ft_is_sorted(s);
}