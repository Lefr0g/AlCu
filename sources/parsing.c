/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:22:14 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 19:16:28 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

#include <stdio.h>
#include <strings.h>

/*
void	lstprint(t_list	*list)
{
	int	i;

	i = 0;
	printf("Printing list at %p\n", list);
	while (list)
	{
		printf("Elem %d convent = %d\n", i, *(int*)list->content);
		list = list->next;
		i++;
	}
}
*/

int	alcu_readmap(t_env *e, char *filename)
{
	int		fd;
	char	*line;
	
	line = ft_strnew(GNL_LINE_SIZE);
	if (filename)
	{	
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			alcu_print_error(NULL);
			return (1);
		}
		ft_putstr("Reading from ");
		ft_putendl(filename);
		alcu_parse_file(e, fd, line);
		close(fd);
	}
	else
	{
		ft_putendl("Reading from stdin");
		alcu_parse_file(e, 0, line);
	}
	return (0);
}

int	alcu_parse_file(t_env *e, int fd, char *line)
{
	int		value;
	t_list	*list;

	value = 0;
	list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if ((value = alcu_check_line(line, 1, 10000)) == -1)
		{
			alcu_print_error(NULL);
			ft_lstdel(&list, &alcu_del_elem);
			list = NULL;
			ft_memdel((void**)&line);
			return (1);
		}
		else
			ft_lstadd(&list, ft_lstnew(&value, 4));
	}
	alcu_load_table(e, list);
	e->table_ref = (int*)malloc(sizeof(int) * e->size);
	if (!e->table_ref)
		return (1);
	ft_memcpy(e->table_ref, e->table, e->size * sizeof(int));
	return (0);
}

int	alcu_load_table(t_env *e, t_list *list)
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
	e->table = (int*)malloc(sizeof(int) * e->size);
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

int	alcu_check_line(char *line, int minval, int maxval)
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
		return (-1);
	else
		return (input);
}

void	alcu_del_elem(void *content, size_t size)
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
