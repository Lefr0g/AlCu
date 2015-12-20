/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:14:23 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 18:23:24 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# define GNL_LINE_SIZE 1000

# include "libft.h"
# include <fcntl.h>

# define FT_IA			0
# define FT_USER		1
# define FT_MIN( x, y )	( ( (x) > (y) ) ? (y) : (x) )

typedef	struct	s_env
{
	int	*table;
	int	*table_ref;
	int	size;
	int	id_line;
}				t_env;

/*
** parsing.c
*/
int				alcu_check_line(char *line, int minval, int maxval);
int				alcu_readmap_stdin(void);
int				alcu_readmap_file(t_env *e, char *filename);
int				alcu_parse_file(t_env *e, char *filename);
int				alcu_load_table(t_env *e, t_list *list);

/*
** control.c
*/
int				alcu_run_game(t_env *e);
void			alcu_exit_game(void);

/*
** error.c
*/
int				alcu_print_error(char *str);

/*
** prints.c
*/
void			print_map(t_env *e);
void			print_last_action(int player, int action);
void			print_your_turn(int player, int max);


#endif
