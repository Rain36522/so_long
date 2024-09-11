/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:16 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:32:16 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"
#include "get_next_line.h"

static int	ft_count_line(char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDWR);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line && line[0] != '\0')
	{
		free(line);
		i ++;
		line = get_next_line(fd);
	}
	close(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	if (i < 3)
		ft_printf("Error\nLa map est trop petite");
	return (i);
}

static t_map	*ft_put_player_pos(t_map *map, int j)
{
	int	i;

	i = 0;
	while (map->map[j][i] && map->map[j][i] != 'P')
		i ++;
	if (i != 'P')
		return (map);
	map->xplayer = i;
	map->yplayer = j;
	return (map);
}

static t_map	*ft_stock_map(t_map *map, char *path, int iline)
{
	int	fd;
	int	j;

	fd = open(path, O_RDWR);
	j = 0;
	while (j < iline)
	{
		map->map[j] = get_next_line(fd);
		if (!map->map[j])
		{
			ft_printf("Error\nRead file");
			return (NULL);
		}
		if (ft_strchr(map->map[j], '\n') != 0)
			map->map[j][ft_strlen(map->map[j]) - 1] = '\0';
		if (ft_strchr(map->map[j], 'P'))
			ft_put_player_pos(map, j);
		j ++;
	}
	map->xmap = ft_strlen(map->map[0]);
	map->ymap = iline;
	close(fd);
	return (map);
}

t_map	*ft_give_map(char *path)
{
	int		iline;
	t_map	*map;

	if (ft_check_map(path) == 0)
		return (NULL);
	iline = ft_count_line(path);
	map = 0;
	if (iline < 3)
		return (NULL);
	map = (t_map *) malloc(sizeof(t_map) * 1);
	if (!map)
	{
		ft_printf("Error\nMalloc map size");
		return (NULL);
	}
	map->map = (char **) malloc(sizeof(char *) * (iline + 1));
	if (!map->map)
	{
		ft_printf("Error\nMalloc map size");
		return (NULL);
	}
	map->map[iline] = NULL;
	return (ft_stock_map(map, path, iline));
}
