/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:13:06 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:45:00 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	final_rotation(t_stack *a)
{
	int	min_pos;
	int	steps;

	min_pos = find_position_of_min(a);
	if (min_pos == 0)
		return ;
	if (min_pos <= a->size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		steps = a->size - min_pos;
		while (steps-- > 0)
			rra(a);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	(void) b;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else
	{
		normalize_stack(a);
		push_to_b(a, b);
		sort_three(a);
		push_to_a(a, b);
		final_rotation(a);
	}
}