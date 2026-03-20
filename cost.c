/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 18:58:37 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:46:18 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_of_max(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		pos;
	int		max_pos;

	current = stack->top;
	max = current->index;
	pos = 0;
	max_pos = 0;
	while (current)
	{
		if (current->index > max)
		{
			max = current->index;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

int	find_target_in_b(t_stack *b, int index_a)
{
	t_node	*current;
	int		target_index;
	int		target_pos;
	int		pos;

	if (!b || !b->top)
		return (0);
	target_index = -2147483648;
	target_pos = 0;
	current = b->top;
	pos = 0;
	while (current)
	{
		if (current->index < index_a && current->index > target_index)
		{
			target_index = current->index;
			target_pos = pos;
		}
		pos++;
		current = current->next;
	}
	if (target_index == -2147483648)
		return (find_position_of_max(b));
	return (target_pos);
}

int	calculate_cost_a(t_stack *a, t_node *node)
{
	if (node->above_mid)
		return (node->position);
	else
		return (a->size - node->position);
}

int	calculate_cost_b(t_stack *b, int target_pos)
{
	int	mid;

	mid = b->size / 2;
	if (target_pos <= mid)
		return (target_pos);
	else
		return (b->size - target_pos);
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		cost_a;
	int		cost_b;
	int		target_pos;

	current = a->top;
	while (current)
	{
		cost_a = calculate_cost_a(a, current);
		target_pos = find_target_in_b(b, current->index);
		cost_b = calculate_cost_b(b, target_pos);
		if ((current->above_mid && target_pos <= b->size / 2)
			|| (!current->above_mid && target_pos > b->size / 2))
		{
			if (cost_a > cost_b)
				current->cost = cost_a;
			else
				current->cost = cost_b;
		}
		else
			current->cost = cost_a + cost_b;
		current = current->next;
	}
}