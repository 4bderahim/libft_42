/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:27:58 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/26 20:28:05 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		i;

	i = 0;
	start = 0;
	if (!s1 || s1[0] == '\0')
		return (ft_strdup(""));
	if (!set || set[0] == '\0')
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
