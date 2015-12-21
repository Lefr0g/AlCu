/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 15:56:09 by amulin            #+#    #+#             */
/*   Updated: 2015/12/21 14:50:55 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*buf;
	t_list	*next;

	if (alst != NULL && *alst && (*del) != NULL)
	{
		buf = *alst;
		next = buf->next;
		while (buf->next != NULL)
		{
			ft_lstdelone(&buf, del);
			buf = next;
			next = buf->next;
		}
		ft_lstdelone(&buf, del);
	}
}
