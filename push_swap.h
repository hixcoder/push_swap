/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:38 by hboumahd          #+#    #+#             */
/*   Updated: 2022/03/22 13:15:02 by hboumahd         ###   ########.fr       */
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
	int		mid;
	int		min;
	int		max;
}   t_stack;

typedef struct s_scanned_nbr
{
	int		nbr;
	int		moves_needed;
	char	*moves_type;
}	t_scanned_nbr;

typedef struct s_chosen
{
	int	len;
	int	*list;
	int	nbr_index;
}	t_chosen;

typedef struct s_passed
{
	int		go_to;
	int		your_place;
	char	*a_move_type;
	char	*b_move_type;
	int		b_moves;
	int		a_moves;
}	t_passed;

int     ft_stack_len(char **av);
void	ft_init_stack(t_stack	*stack);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_sortalgo(t_stack *s);
int ft_get_min(int *list, int list_len);


void tester(t_stack *s, int i);



void		ft_sort_general(t_stack *s);
t_chosen	ft_find_chosen_list(t_stack *s);
void		ft_push_the_unchosen_to_b(t_stack *s, t_chosen chosen);
void		ft_find_smallest_moves(t_stack *s, t_passed *k);

void	ft_sort_three(t_stack *s);
void	ft_sort_five(t_stack *s);
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