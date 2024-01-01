/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:27:03 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/26 20:27:36 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_for_it(const char *haystack, const char *needle, size_t i,
		size_t len)
{
	size_t	t;
	size_t	needle_size;

	needle_size = 0;
	t = 0;
	while (needle[needle_size])
		needle_size++;
	if (i + needle_size > len)
		return (0);
	while (needle[t])
	{
		if (i == len)
			return (0);
		if (needle[t] != haystack[i])
			return (0);
		t++;
		i++;
	}
	return (1);
}

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (haystack == needle)
		return (needle);
	if (!needle[0])
	{
		return (haystack);
	}
	if (len == 0)
		return (NULL);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] && needle[0] == haystack[i])
		{
			if (check_for_it(haystack, needle, i, len) == 1)
				return (haystack + i);
		}
		i++;
	}
	return (NULL);
}
