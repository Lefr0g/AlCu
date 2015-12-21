/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 19:36:14 by amulin            #+#    #+#             */
/*   Updated: 2015/12/03 14:12:15 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_puthex_byte(unsigned char val)
{
	int				i;
	unsigned char	tmp;

	tmp = val;
	i = 1;
	while ((tmp = tmp / 16))
		i = i * 16;
	tmp = val;
	if (val < 15)
		ft_putchar('0');
	while (i)
	{
		if (tmp / i <= 9)
			ft_putchar(tmp / i + '0');
		else
			ft_putchar(tmp / i - 10 + 'a');
		tmp = tmp % i;
		i = i / 16;
	}
}

static void	print_symbols(const void *addr, size_t size)
{
	size_t	i;

	i = size;
	while (i < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (!(i % 2))
			ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (((unsigned char*)addr)[i] > 31 && ((unsigned char*)addr)[i] < 127)
			ft_putchar(((unsigned char*)addr)[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void		ft_print_memory(const void *addr, size_t size)
{
	size_t			i;
	size_t			linelen;
	unsigned char	*ptr;

	ptr = (unsigned char*)addr;
	i = 0;
	linelen = 0;
	while (i <= size)
	{
		if ((!(i % 16) || i == size) && i)
		{
			ft_putchar(' ');
			print_symbols(&ptr[i - linelen], linelen);
			ft_putchar('\n');
			linelen = 0;
		}
		else if (i && !(i % 2))
			ft_putchar(' ');
		if (i < size)
			ft_puthex_byte(((unsigned char*)addr)[i]);
		i++;
		linelen++;
	}
}
