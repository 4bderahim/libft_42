/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:26:14 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/26 20:26:15 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	memory_freed(char **allocation, int child)
{
	while (child >= 0)
	{
		free(allocation[child]);
		child--;
	}
	free(allocation);
}

char	**alloc(char const *s, char **allocation, char c, int count)
{
	int	child;
	int	t;

	child = 0;
	while (*s)
	{
		if (*s != c)
		{
			t = 0;
			while (s[t] != c && s[t] != '\0')
				t++;
			allocation[child] = ft_substr(s, 0, t);
			if (!allocation[child])
			{
				memory_freed(allocation, child);
				return (NULL);
			}
			child++;
			s = s + t;
			if (count == child)
				break ;
		}
		s++;
	}
	return (allocation);
}

char	**ft_split(char const *s, char c)
{
	int		words_count;
	char	**split_array;

	words_count = count_words(s, c);
	split_array = malloc(sizeof(char *) * (words_count + 1));
	if (!split_array)
		return (NULL);
	split_array[words_count] = (NULL);
	if (words_count == 0)
		return (split_array);
	split_array = alloc(s, split_array, c, words_count);
	return (split_array);
}
