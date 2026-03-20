/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:44:33 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:50:14 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->cost = 0;
	node->above_mid = 0;
	node->position = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

int	append_node(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->size++;
		return (1);
	}
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
	stack->size++;
	return (1);
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	is_sorted(t_stack	*stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}