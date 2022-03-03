/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:38 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/03 21:52:41 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
    char    **av;
    int     *stack;
    int     stack_len;    
}   t_stack;

int	ft_stack_len(char **av);
void	ft_init_stack(t_stack	*stack);

#endif