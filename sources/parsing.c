/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:22:14 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 15:17:35 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	alcu_readmap_stdin(void)
{
	ft_putendl("Reading from stdin");
	return (0);
}

int	alcu_readmap_file(char *filename)
{
	if (filename)
	{
		ft_putstr("Reading from ");
		ft_putendl(filename);
		alcu_parse_file(filename);
		return (0);
	}
	else
		alcu_print_error("NULL file name");
	return (1);
}

int	alcu_parse_file(char *filename)
{
	(void)filename;
	return (0);
}
