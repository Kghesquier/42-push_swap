/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kghesqui <kghesqui@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 19:18:23 by kghesqui          #+#    #+#             */
/*   Updated: 2026/03/07 20:51:18 by kghesqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static char	*extract_word(char *str, int *index)
{
	int		start;
	int		len;
	char	*word;
	int		i;

	while (str[*index] && str[*index] == ' ')
		(*index)++;
	start = *index;
	len = 0;
	while (str[*index] && str[*index] != ' ')
	{
		(*index)++;
		len++;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_result(char **result, int count)
{
	while (count > 0)
		free(result[--count]);
	free(result);
}

char	**ft_split(char *str, char c)
{
	char	**result;
	int		words;
	int		i;
	int		index;

	(void)c;
	words = count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (i < words)
	{
		result[i] = extract_word(str, &index);
		if (!result[i])
			return (free_result(result, i), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}