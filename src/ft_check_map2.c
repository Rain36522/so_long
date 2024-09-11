/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:31:34 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:31:34 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_check_line(char *old_line, char *line, int isize, int fd)
{
	if (old_line[0] != '1' || old_line[isize - 1] != '1')
		return (ft_free_line(old_line, line, 2, fd));
	else if (ft_check_char(old_line) == 0)
		return (ft_free_line(old_line, line, 3, fd));
	else if ((int)ft_strlen(old_line) != isize + 1)
		return (ft_free_line(old_line, line, 1, fd));
	return (1);
}

static int	ft_change_p(char **map, int i, int j)
{
	if (map[j][i - 1] != '1' && map[j][i - 1] != 'B' && map[j][i - 1] != 'P')
	{
		map[j][i - 1] = 'P';
		return (1);
	}
	if (map[j][i + 1] != '1' && map[j][i + 1] != 'B' && map[j][i + 1] != 'P')
	{
		map[j][i + 1] = 'P';
		return (1);
	}
	if (map[j + 1][i] != '1' && map[j + 1][i] != 'B' && map[j + 1][i] != 'P')
	{
		map[j + 1][i] = 'P';
		return (1);
	}
	if (map[j - 1][i] != '1' && map[j - 1][i] != 'B' && map[j - 1][i] != 'P')
	{
		map[j - 1][i] = 'P';
		return (1);
	}
	return (0);
}

static void	ft_put_p(char **map, int x_max, int y_max)
{
	int	i;
	int	j;
	int	k;
	int	l;

	j = 1;
	k = 0;
	l = 0;
	while (j < y_max && l ++ < 300)
	{
		i = 1;
		while (i < x_max)
		{
			if (map[j][i] == 'P')
				k += ft_change_p(map, i, j);
			i ++;
		}
		j ++;
		if (j == y_max && k != 0)
		{
			j = 1;
			k = 0;
		}
	}
}

static char	**ft_map_dup(t_data *data)
{
	char	**map2;
	int		i;

	i = 0;
	map2 = (char **) malloc(sizeof(char *) * (data->map->ymap + 1));
	if (!map2)
		return (NULL);
	map2[data->map->ymap] = NULL;
	while (i < data->map->ymap)
	{
		map2[i] = ft_strdup(data->map->map[i]);
		if (!map2[i])
		{
			i = 0;
			while (map2[i])
				free(map2[i ++]);
			free(map2);
			return (NULL);
		}
		i ++;
	}
	return (map2);
}

int	ft_possibl(t_data *data)
{
	char	**map2;
	int		i;
	int		j;

	map2 = ft_map_dup(data);
	if (!map2)
		ft_quit(data, 3, 0);
	ft_put_p(map2, data->map->xmap, data->map->ymap);
	j = 1;
	while (map2[j + 1] != NULL)
	{
		i = 1;
		while (map2[j][i + 1] != '\0')
		{
			if (map2[j][i] == 'C' || map2[j][i] == 'E')
			{
				ft_free_impossible(data, map2);
			}
			i ++;
		}
		j ++;
	}
	return (ft_free_map(map2));
}
