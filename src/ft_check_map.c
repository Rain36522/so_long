/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:28 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:32:28 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "get_next_line.h"

static int	ft_check_first_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		ft_printf("Error\nLa map est vide.\n");
		return (0);
	}
	while (line[i] != '\n' || '\0')
	{
		if (line[i] != '1')
			break ;
		i ++;
	}
	if (line[i] == '\n' || line[i] == '\0')
		return (i);
	ft_printf("Error\nLa map n'est pas entourree d'obstacles.\n");
	return (0);
}

int	ft_check_char(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'C')
			i ++;
		else if (line[i] == 'E' || line[i] == 'P' || line[i] == 'B')
			i ++;
		else
			return (0);
	}
	return (1);
}

int	ft_free_line(char *line, char *line2, int i, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line2)
		free(line2);
	if (i == 0)
		return (1);
	else if (i == 1)
		ft_printf("Error\nLa map n'est pas de forme rectangulaire\n");
	else if (i == 2)
		ft_printf("Error\nLa map n'est pas entourree d'obstacles.\n");
	else if (i == 3)
		ft_printf("Error\nUn caractere inconnu est dans la map.\n");
	else if (i == 4)
		ft_printf("Error\nLes element sont incorrecte (player exit)\n");
	else if (i == 5)
		ft_printf("Error\nLa map se terminer de fasson inconnue.\n");
	if (i > 0)
		exit (0);
	return (1);
}

static int	ft_check_map2(int fd, int isize, char *line, int ielem)
{
	char	*old_line;

	old_line = get_next_line(fd);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_check_line(old_line, line, isize, fd) == 0)
			return (0);
		ielem += ft_check_elem(old_line);
		free(old_line);
		old_line = line;
		line = get_next_line(fd);
	}
	if (ielem != 5)
		return (ft_free_line(old_line, line, 4, fd));
	else if (old_line[0] == '\n' || (line && line[0] != '\0'))
		return (ft_free_line(line, old_line, 5, fd));
	else if (ft_check_first_line(old_line) == 0)
		return (ft_free_line(old_line, line, 6, fd));
	ft_free_line(old_line, line, 0, fd);
	return (1);
}

int	ft_check_map(char *path)
{
	int		fd;
	int		isize;
	char	*line;
	int		i;
	int		ielem;

	fd = open(path, O_RDWR);
	if (fd < 0)
	{
		ft_printf("Error\nMap introuvable\n");
		return (0);
	}
	isize = 0;
	line = get_next_line(fd);
	isize = ft_check_first_line(line);
	free(line);
	if (isize == 0)
		return (0);
	ielem = 0;
	i = ft_check_map2(fd, isize, line, ielem);
	close(fd);
	if (i == 1)
		return (isize);
	return (0);
}
