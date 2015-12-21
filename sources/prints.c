/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:35:45 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/21 13:32:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	print_map(t_env *e)
{
	int		i;
	int		max;
	int		size;
	char	*line;

	i = -1;
	max = 0;
	line = NULL;
	while (++i < e->size)
		max = FT_MAX(max, e->table_ref[i]);
	if (!(line = ft_strnew(max + 1)))
		return (ft_putstr("Problem during the map printing."));
	i = -1;
	while (++i < e->size)
	{
		size = (max - e->table_ref[i]) / 2;
		ft_memset(line, ' ', size);
		ft_memset(line + size, '|', e->table[i]);
		size += e->table[i];
		ft_memset(line + size, '.', e->table_ref[i] - e->table[i]);
		size += (e->table_ref[i] - e->table[i]);
		line[size++] = '\n';
		write(1, line, size);
	}
	ft_memdel((void **)&line);
}

void	print_last_action(int player, int action)
{
	if (player == FT_USER)
		ft_putstr("You took ");
	else
		ft_putstr("The IA tooks ");
	ft_putnbr(action);
	if (action == 1)
		ft_putendl(" match.");
	else
		ft_putendl(" matches.");
}

void	print_your_turn(int player, int max)
{
	if (player == FT_USER)
		ft_putstr("It's your turn (between 1 and ");
	else
		ft_putstr("It's the IA's turn (between 1 and ");
	ft_putnbr(max);
	if (max == 1)
		ft_putstr(" match) : ");
	else
		ft_putstr(" matches) : ");
}

int		print_result(int player, int nb_turns)
{
	if (player == FT_IA)
		ft_putstr("CONGRATULATIONS !!! YOU ARE A WINNER !!!\n YOU WON IN ");
	else
		ft_putstr("YOU'RE A JERK !!! YOU ARE A LOOSER !!!\n YOU LOSE IN ");
	ft_putnbr(nb_turns / 2);
	ft_putendl(" TURNS !!!");
	return (player);
}

void	print_retry(int max)
{
	ft_putstr("Please choose a value between 1 and ");
	ft_putnbr(max);
	if (max == 1)
		ft_putstr(" match : ");
	else
		ft_putstr(" matches : ");
}
