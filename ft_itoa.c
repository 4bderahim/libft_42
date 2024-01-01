/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:24:50 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/26 20:24:52 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_size(int n)
{
	int		i;
	long	num;

	num = n;
	i = 0;
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*allocation(long num, char *block, int size)
{
	int	x;

	while (num != 0)
	{
		x = (num % 10);
		block[size] = x + '0';
		size--;
		num = num / 10;
	}
	return (block);
}

char	*ft_itoa(int n)
{
	long	num;
	int		size;
	char	*alloc;

	size = alloc_size(n);
	if (size == 0)
		size++;
	num = n;
	alloc = (char *)malloc(size + 1);
	if (!alloc)
		return (NULL);
	alloc[size] = '\0';
	if (num == 0)
	{
		alloc[0] = '0';
		return (alloc);
	}
	if (num < 0)
	{
		alloc[0] = '-';
		num *= -1;
	}
	return (allocation(num, alloc, size - 1));
}
