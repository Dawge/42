/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostroh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:15:54 by rostroh           #+#    #+#             */
/*   Updated: 2017/08/13 03:46:21 by rostroh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			gestion(char *str)
{
	if (ft_strlen(str) == 0)
		return (-1);
	while (*str)
	{
		if (ft_isdigit(*str) == 0 && *str != ' ' && *str != '\n' && *str != '-')
			return (-1);
		str++;
	}
	return (0);
}

int			put_error(int fd)
{
	if (!fd)
	{
		ft_putstr_fd("Open Error\n", 2);
		return (-1);
	}
	if (fd == -1)
	{
		ft_putstr_fd("No such file in this directory\n", 2);
		return (-1);
	}
	return (1);
}

char		*get_fd(char *argv, int *nb)
{
	int		fd;
	char	*str;
	char	*line;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	fd = open(argv, O_RDONLY);
	if (put_error(fd) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		*nb += 1;
		line = ft_strjoin(line, "\n");
		str = ft_strjoin(str, line);
	}
	return (str);
}

int			main(int argc, char **argv)
{
	t_point	**p;
	t_point	**save;
	char	*str;
	int		nb_line;

	if (argc == 2)
	{
		str = get_fd(argv[1], &nb_line);
		if (!str)
			return (0);
		if (gestion(str) == -1)
		{
			ft_putstr_fd("Invalid file\n", 2);
			return (0);
		}
		p = creat_point(str, nb_line);
		save = creat_point(str, nb_line);
		draw_call(p, save, nb_line, argv[1]);
	}
	else
		ft_putendl("Usage : ./fdf [file_name]");
	return (0);
}
