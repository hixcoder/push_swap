/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:14 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/02 11:08:27 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int tab[] = {1,58,88,445};
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

int main(int ac, char **av)
{
	int *stack;
	
	if (ac > 1)
	{
		stack = ft_init_stack(av);
		if (stack == NULL)
			return (0);
		for (int i = 1; av[i]; i++)
		{
			ft_printf("%d\n", stack[i]);
		}
	}
	else
		ft_printf("please enter the stack you wanna sort!\n");
}