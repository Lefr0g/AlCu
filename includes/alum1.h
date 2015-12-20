/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:14:23 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 15:14:25 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "libft.h"

/*
** parsing.c
*/
int		alcu_readmap_stdin(void);
int		alcu_readmap_file(char *filename);
int		alcu_parse_file(char *filename);

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
