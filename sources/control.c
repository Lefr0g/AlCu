/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:26:59 by amulin            #+#    #+#             */
/*   Updated: 2015/12/21 13:31:34 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	*prepare_lines_to_win(t_env *e)
{
	int	i;

	i = -1;
	if (!(e->winlines = (int *)malloc(e->size * sizeof(int))))
		return (NULL);
	e->winlines[++i] = 1;
	while (++i < e->size)
	{
		if ((!e->winlines[i - 1] && e->table_ref[i - 1] % 4 == 1)
			|| (e->winlines[i - 1] && e->table_ref[i - 1] % 4 != 1))
			e->winlines[i] = 1;
		else
			e->winlines[i] = 0;
	}
	return (e->winlines);
}

static int	compute_best(t_env *e, int max)
{
	int	rest;

	rest = e->table[e->id_line] % 4;
	if (e->winlines[e->id_line] && rest != 1)
		return ((!rest) ? FT_MIN(3, max) : FT_MIN(rest - 1, max));
	else if (!e->winlines[e->id_line] && rest)
		return (rest);
	else
		return (FT_MIN(1, max));
}

static int	alcu_turn(t_env *e, int player)
{
	int		max;
	char	*line;
	int		action;

	max = FT_MIN(3, e->table[e->id_line]);
	print_your_turn(player, max);
	if (!(line = NULL) && player == FT_IA)
	{
		action = compute_best(e, max);
		ft_putnbr(action);
		ft_putchar('\n');
	}
	else if ((action = -1))
		while (action == -1)
		{
			if ((action = get_next_line(0, &line)) == -1)
			{
				ft_memdel((void **)(&line));
				return (-1);
			}
			if ((action = alcu_check_line(line, 1, max)) == -1)
				print_retry(max);
		}
	ft_memdel((void **)&line);
	return (action);
}

int			alcu_run_game(t_env *e)
{
	int	action;
	int	player;
	int	nb_turns;
	int	first_turn;

	first_turn = 1;
	nb_turns = 1;
	player = FT_IA;
	e->id_line = e->size - 1;
	if (!prepare_lines_to_win(e))
		return (-1);
	while (e->table[0] && nb_turns++)
	{
		(!first_turn) ? print_last_action(player, action) : (first_turn = 0);
		print_map(e);
		player = (player + 1) % 2;
		if ((action = alcu_turn(e, player)) == -1)
			return (-1);
		e->table[e->id_line] -= action;
		if (!e->table[e->id_line])
			e->id_line--;
	}
	print_last_action(player, action);
	print_map(e);
	return (print_result(player, nb_turns));
}
