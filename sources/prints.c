/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:35:45 by tle-meur          #+#    #+#             */
/*   Updated: 2015/12/20 16:56:10 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	print_map(t_emv *e)
{
	(void)e;
}

void	print_last_action(int player, int action)
{
	if (player == FT_USER)
		ft_putstr("You took ");
	else
		ft_purstr("The IAi tooks ");
	ft_putnbr(action);
	if (action == 1)
		ft_putendl(" match.");
	else
		ft_putendl(" matches.");
}

void	print_yout_turn(t_env *e, int playeri, int max)
{
	int	max;

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
