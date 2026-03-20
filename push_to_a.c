/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:35:55 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:47:38 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_of_min(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack->top;
	min = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min)
		{
			min = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	init_find_target(int *target_index, int *target_pos)
{
	*target_index = 2147483647;
	*target_pos = 0;
}

int	find_target_in_a(t_stack *a, int index_b)
{
	t_node	*current;
	int		target_index;
	int		target_pos;
	int		pos;

	if (!a || !a->top)
		return (0);
	init_find_target(&target_index, &target_pos);
	current = a->top;
	pos = 0;
	while (current)
	{
		if (current->index > index_b && current->index < target_index)
		{
			target_index = current->index;
			target_pos = pos;
		}
		pos++;
		current = current->next;
	}
	if (target_index == 2147483647)
		return (find_position_of_min(a));
	return (target_pos);
}

void	rotate_a_to_position(t_stack *a, int target_pos)
{
	int	steps;

	if (target_pos == 0)
		return ;
	if (target_pos <= a->size / 2)
	{
		while (target_pos-- > 0)
			ra(a);
	}
	else
	{
		steps = a->size - target_pos;
		while (steps-- > 0)
			rra(a);
	}
}

void	push_to_a(t_stack *a, t_stack *b)
{
	int	target_pos;

	while (b->size > 0)
	{
		target_pos = find_target_in_a(a, b->top->index);
		rotate_a_to_position(a, target_pos);
		pa(a, b);
	}
}