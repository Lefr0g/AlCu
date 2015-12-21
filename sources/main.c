/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:13:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/21 14:14:16 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	del_env(t_env *e)
{
	ft_memdel((void **)(&e->table_ref));
	ft_memdel((void **)(&e->table));
	ft_memdel((void **)(&e->winlines));
}

int		alcu_print_error(char *str)
{
	if (str)
	{
		ft_putstr_fd("ERROR : ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		ft_putstr_fd("ERROR\n", 2);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc < 2)
	{
		if (!alcu_readmap(&e, NULL))
			alcu_run_game(&e);
	}
	else if (argc == 2)
	{
		if (!alcu_readmap(&e, argv[1]))
			alcu_run_game(&e);
	}
	else
	{
		alcu_print_error(NULL);
		return (0);
	}
	del_env(&e);
	return (0);
}
