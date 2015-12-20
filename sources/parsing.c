/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:22:14 by amulin            #+#    #+#             */
/*   Updated: 2015/12/20 18:00:23 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

#include <stdio.h>
#include <strings.h>

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

int	alcu_readmap_stdin(void)
{
	ft_putendl("Reading from stdin");
	return (0);
}

int	alcu_readmap_file(char *filename)
{
	if (filename)
	{
		ft_putstr("Reading from ");
		ft_putendl(filename);
		alcu_parse_file(filename);
		return (0);
	}
	else
		alcu_print_error("NULL file name");
	return (1);
}

int	alcu_parse_file(char *filename)
{
	int		fd;
	char	*line;
	int		value;
	t_list	*list;

	value = 0;
	list = NULL;
	line = ft_strnew(GNL_LINE_SIZE);
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		alcu_print_error(NULL);
		return (1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if ((value = alcu_check_line(line, 1, 10000)) == -1)
		{
			alcu_print_error(NULL);
			// Free all memory
			exit(1);
		}
		else
		{
			ft_lstadd(&list, ft_lstnew(&value, 4));
//			printf("Element added, list is at %p\n", list);
//			printf("Value copied to list, content is %d\n", *(int*)(list->content));
		}
	}
	lstprint(list);

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

