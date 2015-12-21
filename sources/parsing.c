/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:22:14 by amulin            #+#    #+#             */
/*   Updated: 2015/12/21 15:12:22 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

#include <stdio.h>
#include <strings.h>

int			alcu_check_line(char *line, int minval, int maxval)
{
	int	i;
	int	input;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != '\n')
			return (-1);
		i++;
	}
	input = ft_atoi(line);
	if (input < minval || input > maxval)
	{
		return (-1);
	}
	else
		return (input);
}

static int	alcu_load_table(t_env *e, t_list *list)
{
	int		i;
	t_list	*lstptr;

	i = 0;
	lstptr = list;
	while (lstptr)
	{
		lstptr = lstptr->next;
		i++;
	}
	e->size = i;
	if (!(e->table = (int*)malloc(sizeof(int) * e->size)))
		return (1);
	lstptr = list;
	i--;
	while (lstptr)
	{
		e->table[i] = *(int*)lstptr->content;
		lstptr = lstptr->next;
		i--;
	}
	return (0);
}

static void	alcu_del_elem(void *content, size_t size)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char*)content;
	while (i < size)
	{
		c[i] = '\0';
		i++;
	}
}

static int	alcu_parse_file(t_env *e, int fd, char *line)
{
	int		value;
	t_list	*list;

	list = NULL;
	while (get_next_line(fd, &line) == 1)
		if ((value = alcu_check_line(line, 1, 10000)) == -1)
		{
			alcu_print_error(NULL);
			ft_lstdel(&list, &alcu_del_elem);
			ft_memdel((void**)&line);
			return (1);
		}
		else
			ft_lstadd(&list, ft_lstnew(&value, 4));
	if (alcu_load_table(e, list))
	{
		ft_memdel((void**)&line);
		return (1);
	}
	if (!(e->table_ref = (int*)malloc(sizeof(int) * e->size)))
	{
		ft_memdel((void**)&line);
		return (1);
	}
	ft_strdel(&line);
	return (ft_memcpy(e->table_ref, e->table, e->size * sizeof(int)) && 0);
}

int			alcu_readmap(t_env *e, char *filename)
{
	int		fd;
	char	*line;

	if (!(line = ft_strnew(GNL_LINE_SIZE)))
		return (1);
	if (filename)
	{
		if ((fd = open(filename, O_RDONLY)) == -1)
		{
			alcu_print_error(NULL);
			return (1);
		}
		ft_putstr("Reading from ");
		ft_putendl(filename);
		if (alcu_parse_file(e, fd, line))
		{
			return (close(fd) || 1);
		}
		return (close(fd) && 0);
	}
	else
	{
		ft_putendl("Reading from stdin");
		return (alcu_parse_file(e, 0, line));
	}
}
