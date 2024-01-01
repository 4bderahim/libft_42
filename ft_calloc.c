/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:39:25 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/30 01:48:36 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*all;
	size_t	tmp;

	if (count == 0 || size == 0)
	{
		all = (void *)malloc(count * size);
		return (ft_memset(all, 0, 1));
	}
	tmp = count * size;
	if ((tmp / size) != count)
		return (NULL);
	all = (void *)malloc(count * size);
	if (!all)
		return (NULL);
	return (ft_memset(all, 0, count * size));
}
