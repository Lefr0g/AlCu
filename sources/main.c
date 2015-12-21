/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:13:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/21 15:47:33 by amulin           ###   ########.fr       */
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
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc < 2)
	{
		if (!alcu_readmap(&e, NULL) && e.size)
			alcu_run_game(&e);
		else
			return (1);
	}
	else if (argc == 2)
	{
		if (!alcu_readmap(&e, argv[1]))
			alcu_run_game(&e);
		else
			return (1);
	}
	else
	{
		return (alcu_print_error(NULL));
	}
	del_env(&e);
	return (0);
}
