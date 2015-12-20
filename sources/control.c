/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:26:59 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 19:09:15 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	compute_best(t_env *e, int max)
{
	int	rest;
	int	want_line;

	want_line = 0;
	rest = e->table[e->id_line] % 4;
	if (!want_line && rest != 1)
		return ((!rest) ? FT_MIN(3, max) : FT_MIN(rest - 1, max));
	else if (want_line && rest)
		return (rest);
	else
		return (FT_MIN(1, max));
}

static int	alcu_turn(t_env *e, int player)
{
	int		max;
	char	*line;
	int		action;

	line = NULL;
	max = FT_MIN(3, e->table[e->id_line]);
	print_your_turn(player, max);
	if (player == FT_IA)
	{
		action = compute_best(e, max);
		ft_putnbr(action);
		ft_putchar('\n');
	}
	else if (!(action = 0))
		while (action <= 0 || action > max)
		{
			if ((action = get_next_line(0, &line)) == -1)
			{
				ft_memdel((void **)(&line));
				return (-1);
			}
			action = alcu_check_line(line, 1, max);
		}
	ft_memdel((void **)&line);
	return (action);
}

int			alcu_run_game(t_env *e)
{
	int	action;
	int	player;
	int	first_turn;

	first_turn = 1;
	player = FT_USER;
	while (e->table[e->size - 1])
	{
		print_map(e);
		if (!first_turn)
			print_last_action(player, action);
		else
			first_turn = 0;
		action = alcu_turn(e, player);
		if (action == -1)
			return (-1);
		e->table[e->id_line] -= action;
		if (!e->table[e->id_line])
			e->id_line--;
		player = (player + 1) % 2;
	}
	return (player);
}

void		alcu_exit_game(void)
{
	exit(-1);
}
