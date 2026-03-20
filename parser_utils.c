/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:45:23 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:51:31 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(long result, int sign, char next_digit)
{
	if (result > 214748364)
		return (0);
	if (result == 214748364)
	{
		if (sign == 1 && (next_digit - '0') > 7)
			return (0);
		if (sign == -1 && (next_digit - '0') > 8)
			return (0);
	}
	return (1);
}

static int	parse_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi_check(char *str, int *value)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = parse_sign(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	result = 0;
	while (ft_isdigit(str[i]))
	{
		if (!check_overflow(result, sign, str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*value = (int)(result * sign);
	return (1);
}

int	check_duplicate(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}