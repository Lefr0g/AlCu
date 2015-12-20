/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:24:39 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 15:15:02 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int	alcu_print_error(char *str)
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
