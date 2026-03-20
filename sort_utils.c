/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:50:21 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:51:43 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}

void	update_positions(t_stack *stack)
{
	t_node	*current;
	int		pos;
	int		mid;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	pos = 0;
	mid = stack->size / 2;
	while (current)
	{
		current->position = pos;
		if (pos <= mid)
			current->above_mid = 1;
		else
			current->above_mid = 0;
		pos++;
		current = current->next;
	}
}

t_node	*find_node_by_index(t_stack *stack, int index)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->index == index)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_node	*find_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;

	current = stack->top;
	cheapest = current;
	min_cost = current->cost;
	while (current)
	{
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}