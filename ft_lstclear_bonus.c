/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-krid <ael-krid@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:23:07 by ael-krid          #+#    #+#             */
/*   Updated: 2023/12/26 20:23:09 by ael-krid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list;

	if (!lst)
	{
		return ;
	}
	list = *lst;
	while (list != NULL)
	{
		del(list->content);
		tmp = list->next;
		free(list);
		list = tmp;
	}
	*lst = NULL;
}
