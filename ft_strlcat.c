/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:29:19 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/26 20:27:11 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	dstlen_increased;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dstlen_increased = dstlen;
	if (!dst || dstsize == 0)
		return (srclen);
	if (dstsize < dstlen)
		return (dstsize + srclen);
	i = 0;
	while (src[i] && dstlen_increased < dstsize - 1)
	{
		dst[dstlen_increased] = src[i];
		i++;
		dstlen_increased++;
	}
	dst[dstlen_increased] = '\0';
	return (dstlen + srclen);
}
