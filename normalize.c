/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:17:07 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:45:52 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	current = stack->top;
	while (current)
	{
		rank = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				rank ++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}