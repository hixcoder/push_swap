/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:38 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/16 21:02:51 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	char    **av;
	int     *stack_a;
	int     *stack_b;
	int     stack_a_len;
	int     stack_b_len;

	int		*stack_sorted;
	int		sorted_len;
	int		index_mid;
	int		index_min;
	int		index_max;
}   t_stack;

typedef struct s_scanned_nbr
{
	int		nbr;
	int		moves_needed;
	char	*moves_type;
}	t_scanned_nbr;

int     ft_stack_len(char **av);
void	ft_init_stack(t_stack	*stack);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_sortalgo(t_stack *s);

void ft_sort_three(t_stack *s);
void ft_sort_five(t_stack *s);
void	ft_sort_handred(t_stack *s);

void	ft_sa(t_stack *s);
void	ft_sb(t_stack *s);
void	ft_ss(t_stack *s);
void	ft_pb(t_stack *s);
void	ft_pa(t_stack *s);
void    ft_ra(t_stack *s);
void    ft_rb(t_stack *s);
void    ft_rr(t_stack *s);
void    ft_rra(t_stack *s);
void    ft_rrb(t_stack *s);
void    ft_rrr(t_stack *s);


#endif