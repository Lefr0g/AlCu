/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:14:23 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 17:07:49 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# define GNL_LINE_SIZE 1000

# include "libft.h"
# include <fcntl.h>

typedef	struct	s_env
{
	int	*table;
	int	size;
	int	id_line;
}				t_env;

/*
** parsing.c
*/
int		alcu_readmap_stdin(void);
int		alcu_readmap_file(char *filename);
int		alcu_parse_file(char *filename);
int		alcu_check_line(char *line, int minval, int maxval);

/*
** control.c
*/
int		alcu_run_game(void);
void	alcu_exit_game(void);

/*
** error.c
*/
int		alcu_print_error(char *str);

#endif
