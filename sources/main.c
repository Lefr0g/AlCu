/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:13:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 18:11:05 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	main(int argc, char **argv)
{
	t_env	e;

	(void)e;
	if (argc < 2)
	{
		alcu_readmap_stdin();
	}
	else if (argc == 2)
	{
		alcu_readmap_file(argv[1]);
	}
	else
	{
		alcu_print_error(NULL);
		alcu_exit_game();
	}
	alcu_run_game(&e);
	return (0);
}
