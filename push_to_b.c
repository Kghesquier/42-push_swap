/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:39:14 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:47:26 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top_a(t_stack *a, t_node *node)
{
	while (a->top != node)
	{
		if (node->above_mid)
			ra(a);
		else
			rra(a);
	}
}

void	move_to_top_b(t_stack *b, int target_pos)
{
	int	steps;

	if (target_pos == 0)
		return ;
	if (target_pos <= b->size / 2)
	{
		while (target_pos-- > 0)
			rb(b);
	}
	else
	{
		steps = b->size - target_pos;
		while (steps-- > 0)
			rrb(b);
	}
}

static int	do_double_rot(t_stack *a, t_stack *b, t_node *node, int tpos)
{
	int	steps;

	if (node->above_mid && tpos <= b->size / 2)
	{
		while (a->top != node && tpos > 0)
		{
			rr(a, b);
			tpos--;
		}
	}
	else if (!node->above_mid && tpos > b->size / 2)
	{
		steps = b->size - tpos;
		while (a->top != node && steps > 0)
		{
			rrr(a, b);
			steps--;
		}
		if (steps > 0)
			tpos = b->size - steps;
		else
			tpos = 0;
	}
	return (tpos);
}

void	execute_rotations(t_stack *a, t_stack *b, t_node *node)
{
	int	target_pos;

	target_pos = find_target_in_b(b, node->index);
	target_pos = do_double_rot(a, b, node, target_pos);
	move_to_top_a(a, node);
	move_to_top_b(b, target_pos);
}

void	push_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (a->size > 3)
	{
		update_positions(a);
		update_positions(b);
		calculate_costs(a, b);
		cheapest = find_cheapest(a);
		execute_rotations(a, b, cheapest);
		pb(a, b);
	}
}

