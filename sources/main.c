/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:13:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 18:59:34 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	tmp_print_map(int *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_env	e;

	(void)e;
	if (argc < 2)
	{
		alcu_readmap(&e, NULL);
	}
	else if (argc == 2)
	{
		alcu_readmap(&e, argv[1]);
	}
	else
	{
		alcu_print_error(NULL);
		alcu_exit_game();
	}
	tmp_print_map(e.table, e.size);
	alcu_run_game(&e);
	return (0);
}
