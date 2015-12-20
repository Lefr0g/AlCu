/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:22:14 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 15:03:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int readmap_stdin(void)
{
	ft_putendl("Reading from stdin");
	return (0);
}

int	readmap_file(char *filename)
{
	if (filename)
	{
		ft_putstr("Reading from ");
		ft_putendl(filename);
		return (0);
	}
	else
		print_error("NULL file name");
	return (1);
}
