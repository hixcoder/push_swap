/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <hboumahd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:38 by hboumahd          #+#    #+#             */
/*   Updated: 2022/05/15 11:26:52 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

# define MAX 2147483647

typedef struct s_stack
{
	char	**av;
	int		*stack_a;
	int		*stack_b;
	int		stack_a_len;
	int		stack_b_len;

	int		*stack_sorted;
	int		sorted_len;
	int		mid;
	int		min;
	int		max;
}	t_stack;

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
}	t_chosn;

typedef struct s_passed
{
	int		go_to;
	int		your_place;
	char	*a_move_type;
	char	*b_move_type;
	int		b_moves;
	int		a_moves;
}	t_passed;

// here is the algo functions
void	ft_sort_three(t_stack *s);
void	ft_sort_five(t_stack *s);
void	ft_sort_general(t_stack *s);

// those exist in the instructions_x.c files.
void	ft_sa(t_stack *s, int w);
void	ft_sb(t_stack *s, int w);
void	ft_ss(t_stack *s, int w);
void	ft_pb(t_stack *s, int w);
void	ft_pa(t_stack *s, int w);
void	ft_ra(t_stack *s, int w);
void	ft_rb(t_stack *s, int w);
void	ft_rr(t_stack *s, int w);
void	ft_rra(t_stack *s, int w);
void	ft_rrb(t_stack *s, int w);
void	ft_rrr(t_stack *s, int w);

// functions used in the push_swap_utils.c file
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_swap(int *a, int *b);
void	ft_sortalgo(t_stack *s);
int		ft_get_min(int *list, int list_len);

// functions used in the stack_init.c file
void	ft_exit(t_stack *s, int status);
int		ft_atoi(const char *str, t_stack *s);
void	ft_check_dup(t_stack *s);
void	ft_is_sorted(t_stack *s, int w);
void	ft_init_stack(t_stack *s, int w);

// functions used in the sort_utils_0.c file
int		ft_ind(t_stack *s, int nbr);
int		ft_check_element_list(t_stack *s, int i);
void	ft_bring_element_list(t_stack *s, t_chosn *chosen);
t_chosn	ft_find_chosen_list(t_stack *s);

// functions used in the sort_utils_1.c file
int		ft_is_in_chosen(t_chosn chosen, int nbr);
void	ft_push_the_unchosen_to_b(t_stack *s, t_chosn chosen);

// functions used in the sort_utils_2.c file
int		ft_nexnbr_index_a(t_stack *s, int nbr);
int		moves_in_a(int nbr, t_stack *s, t_passed *k);
int		moves_in_b(int i, t_stack *s, t_passed *k);
void	ft_check_shared_moves(t_passed *k, int *tmp_moves);
void	ft_find_smallest_moves(t_stack *s, t_passed *k);

// functions used in the sort_utils_3.c file
int		ft_get_index_in_a(t_stack *s, int nbr);
void	ft_move_to_top_of_a(t_stack *s, int i, int nbr);
void	ft_move_to_top_of_b(t_stack *s, int i, int nbr);
void	ft_move_both(t_stack *s, int len, char *move_type, t_passed *i);
void	ft_push_it_to_a(t_stack *s, t_passed *i);

void	tester(t_stack *s, int i);

void	ft_push_the_unchosen_to_b(t_stack *s, t_chosn chosen);
void	ft_find_smallest_moves(t_stack *s, t_passed *k);

#endif