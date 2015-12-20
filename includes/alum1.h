/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:14:23 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 15:01:00 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "libft.h"


/*
** parsing.c
*/
int		readmap_stdin(void);
int		readmap_file(char *filename);

/*
** control.c
*/
int		run_game(void);
void	exit_game(void);

/*
** error.c
*/
int		print_error(char *str);

#endif
