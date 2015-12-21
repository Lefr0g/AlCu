/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 13:36:01 by amulin            #+#    #+#             */
/*   Updated: 2015/12/03 13:56:06 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int n, char *mode)
{
	if (n > 15)
	{
		ft_puthex(n / 16, mode);
		ft_puthex(n % 16, mode);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else if (!ft_strcmp(mode, "min"))
			ft_putchar((n - 10) + 'a');
		else if (!ft_strcmp(mode, "maj"))
			ft_putchar((n - 10) + 'A');
	}
}
