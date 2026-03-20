/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:11:54 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:43:39 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	int				above_mid;
	int				position;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/*push_swap_main.c*/
int		main(int argc, char **argv);

/*stack_utils.c*/
void	free_stack(t_stack *stack);
t_node	*create_node(int value);
int		append_node(t_stack *stack, int value);
t_stack	*create_empty_stack(void);
int		is_sorted(t_stack	*stack);

/*libft_utils.c*/
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);

/*split.c*/
char	**ft_split(char *str, char c);

/*parser_utils.c*/
int		ft_atoi_check(char *str, int *value);
int		check_duplicate(t_stack *stack);
int		is_only_space(char *str);

/*parser.c*/
t_stack	*init_stack(int argc, char **argv);

/*swap.c*/
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/*push.c*/
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/*rotate.c*/
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

/*reverse_rotate.c*/
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/*normalize.c*/
void	normalize_stack(t_stack *stack);

/*sort_utils.c*/
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
void	update_positions(t_stack *stack);
t_node	*find_node_by_index(t_stack *stack, int index);
t_node	*find_cheapest(t_stack *stack);

/*sort.c*/
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	final_rotation(t_stack *a);
void	sort_stack(t_stack *a, t_stack *b);

/*cost.c*/
int		find_position_of_max(t_stack *stack);
int		find_target_in_b(t_stack *b, int index_a);
int		calculate_cost_a(t_stack *a, t_node *node);
int		calculate_cost_b(t_stack *b, int target_pos);
void	calculate_costs(t_stack *a, t_stack *b);

/*push_to_b.c*/
void	move_to_top_a(t_stack *a, t_node *node);
void	move_to_top_b(t_stack *b, int target_pos);
void	execute_rotations(t_stack *a, t_stack *b, t_node *node);
void	push_to_b(t_stack *a, t_stack *b);

/*push_to_a.c*/
int		find_position_of_min(t_stack *stack);
int		find_target_in_a(t_stack *a, int index_b);
void	rotate_a_to_position(t_stack *a, int target_pos);
void	push_to_a(t_stack *a, t_stack *b);

#endif