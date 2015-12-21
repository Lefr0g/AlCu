/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_extras.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:50:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/21 17:51:26 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	print_long_line(t_env *e, int i)
{
	ft_putstr("\t\t\tLine ");
	ft_putnbr(i);
	ft_putstr(" : ");
	ft_putnbr(e->table[i]);
	ft_putstr(" / ");
	ft_putnbr(e->table_ref[i]);
	if (e->table[i] > 1)
		ft_putstr(" matches");
	else
		ft_putstr(" match");
	ft_putendl(" remaining");
}

void	print_small_line(t_env *e, int max, int i)
{	
	int		size;
	char	*line;

	line = NULL;
	if (!(line = ft_strnew(max + 1)))
		return (ft_putstr("Problem during the map printing."));
	size = (max - e->table_ref[i]) / 2;
	ft_memset(line, ' ', size);
	ft_memset(line + size, '|', e->table[i]);
	size += e->table[i];
	ft_memset(line + size, '.', e->table_ref[i] - e->table[i]);
	size += (e->table_ref[i] - e->table[i]);
	line[size++] = '\n';
	write(1, line, size);
	ft_memdel((void **)&line);
}
