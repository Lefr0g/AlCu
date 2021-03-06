/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:14:23 by amulin            #+#    #+#             */
/*   Updated: 2015/12/21 17:52:27 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# define GNL_LINE_SIZE 1000
# define MAX_MATCHES_PER_LINE 80

# include "libft.h"
# include <fcntl.h>

# define ANSI_COLOR_RED "\033[31m"
# define ANSI_COLOR_GREEN "\033[32m"
# define ANSI_COLOR_YELLOW "\033[33m"
# define ANSI_COLOR_BLUE "\033[34m"
# define ANSI_COLOR_MAGENTA "\033[35m"
# define ANSI_COLOR_CYAN "\033[36m"
# define ANSI_UNDERLINED "\033[4m"
# define ANSI_RESET "\033[0m"

# define FT_IA			0
# define FT_USER		1
# define FT_MIN( x, y )	( ( (x) > (y) ) ? (y) : (x) )
# define FT_MAX( x, y )	( ( (x) < (y) ) ? (y) : (x) )

typedef	struct	s_env
{
	int	*table;
	int	*table_ref;
	int	*winlines;
	int	size;
	int	id_line;
}				t_env;

/*
** parsing.c
*/
int				alcu_check_line(char *line, int minval, int maxval);
int				alcu_readmap(t_env *e, char *filename);

/*
** control.c
*/
int				alcu_run_game(t_env *e);

/*
** main.c
*/
int				alcu_print_error(char *str);

/*
** prints.c
*/
void			print_map(t_env *e);
void			print_retry(int max);
int				print_result(int player, int nb_turns);
void			print_last_action(int player, int action);
void			print_your_turn(int player, int max);

/*
** prints_extras.c
*/
void			print_long_line(t_env *e, int i);
void			print_small_line(t_env *e, int max, int i);

#endif
