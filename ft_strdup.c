/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:26:42 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/26 20:26:45 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*all;

	i = 0;
	i = ft_strlen(s1);
	all = (char *)malloc(i + 1);
	i = 0;
	if (!all)
		return (NULL);
	while (s1[i])
	{
		all[i] = s1[i];
		i++;
	}
	all[i] = '\0';
	return (all);
}
