/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:13:00 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:44:38 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	handle_error(t_stack *a, char **args, int need_free)
{
	free_stack(a);
	if (need_free)
		free_split(args);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	parse_arguments(t_stack *a, char **args)
{
	int	i;
	int	value;

	i = 0;
	while (args[i])
	{
		if (!ft_atoi_check(args[i], &value))
			return (0);
		if (!append_node(a, value))
			return (0);
		i++;
	}
	return (1);
}

static void	check_only_space(int argc, char **argv )
{
	if (argc == 2 && is_only_space(argv[1]))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*a;
	char	**args;
	int		need_free;

	check_only_space(argc, argv);
	a = create_empty_stack();
	if (!a)
		return (NULL);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		need_free = 1;
	}
	else
	{
		args = argv +1;
		need_free = 0;
	}
	if (!parse_arguments(a, args) || check_duplicate(a))
		handle_error(a, args, need_free);
	if (need_free)
		free_split(args);
	return (a);
}