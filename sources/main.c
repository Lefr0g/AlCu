/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:13:24 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 14:56:25 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		readmap_stdin();
	}
	else if (argc == 2)
	{
		readmap_file(argv[1]);
	}
	else
	{
		print_error(NULL);
		exit_game();
	}
	run_game();
	return (0);
}
