/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:14 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/02 11:41:00 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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