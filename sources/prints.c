/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:35:45 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/21 17:59:21 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	print_map(t_env *e)
{
	int		i;
	int		max;

	i = -1;
	max = 0;
	max = MAX_MATCHES_PER_LINE;
	i = -1;
	while (++i < e->size)
	{
		if (e->table_ref[i] <= MAX_MATCHES_PER_LINE)
			print_small_line(e, max, i);
		else
			print_long_line(e, i);
	}
}

void	print_last_action(int player, int action)
{
	if (player == FT_USER)
	{
		ft_putstr(ANSI_UNDERLINED);
		ft_putstr("You took ");
	}
	else
	{
		ft_putstr(ANSI_COLOR_CYAN);
		ft_putstr("The IA tooks ");
	}
	ft_putnbr(action);
	if (action == 1)
		ft_putendl(" match.");
	else
		ft_putendl(" matches.");
	ft_putstr(ANSI_RESET);
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
	{
		ft_putstr(ANSI_COLOR_GREEN);
		ft_putstr("CONGRATULATIONS !!! YOU ARE A WINNER !!!\n YOU WON IN ");
	}
	else
	{
		ft_putstr(ANSI_COLOR_RED);
		ft_putstr("YOU'RE A JERK !!! YOU ARE A LOOSER !!!\n YOU LOSE IN ");
	}
	ft_putnbr(nb_turns / 2);
	ft_putendl(" TURNS !!!");
	ft_putendl(ANSI_RESET);
	return (player);
}

void	print_retry(int max)
{
	ft_putstr(ANSI_COLOR_YELLOW);
	ft_putstr("Please choose a value between 1 and ");
	ft_putnbr(max);
	if (max == 1)
		ft_putstr(" match : ");
	else
		ft_putstr(" matches : ");
	ft_putstr(ANSI_RESET);
}
