/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:31:37 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:31:37 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_put_flag(t_data *data, char *path, int i, int j)
{
	int		xwidth;
	int		yheight;
	int		xpos;
	int		ypos;
	void	*img;

	xwidth = 64;
	yheight = 64;
	xpos = (i - 1) * xwidth + 32;
	ypos = (j - 1) * yheight;
	img = mlx_xpm_file_to_image(data->mlx, path, &xwidth, &yheight);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, xpos, ypos);
	mlx_destroy_image(data->mlx, img);
}

static void	ft_put_img_by_char2(t_data *data, char c, int i, int j)
{
	if (c == 'B')
	{
		ft_put_image(data, "./img/back_g.xpm", i, j);
		ft_put_image(data, "./img/blackhole.xpm", i, j);
	}
}

void	ft_put_img_by_char(t_data *data, char c, int i, int j)
{
	if (c == 'P')
		ft_put_image(data, "./img/terre.xpm", i, j);
	else if (c == '0')
		ft_put_image(data, "./img/back_g.xpm", i, j);
	else if (c == '1')
		ft_put_image(data, "./img/Asteroid.xpm", i, j);
	else if (c == 'E')
	{
		ft_put_image(data, "./img/back_g.xpm", i, j);
		ft_put_image(data, "./img/terre.xpm", i, j);
	}
	else if (c == 'C')
	{
		ft_put_image(data, "./img/back_g.xpm", i, j);
		ft_put_image(data, "./img/moon.xpm", i, j);
	}
	else if (c == 'F')
	{
		ft_put_image(data, "./img/back_g.xpm", i, j);
		ft_put_image(data, "./img/moon.xpm", i, j);
		ft_put_flag(data, "./img/flag.xpm", i, j);
	}
	else
		ft_put_img_by_char2(data, c, i, j);
}

void	ft_put_object(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (j + 1 < data->map->ymap)
	{
		i = 1;
		while (i + 1 < data->map->xmap)
		{
			if (data->map->map[j][i] == 'C')
				ft_put_image(data, "./img/moon.xpm", i, j);
			else if (data->map->map[j][i] == 'P')
				ft_put_image(data, "./img/fuseU.xpm", i, j);
			else if (data->map->map[j][i] == '1')
				ft_put_image(data, "./img/Asteroid.xpm", i, j);
			else if (data->map->map[j][i] == 'E')
				ft_put_image(data, "./img/terre.xpm", i, j);
			else if (data->map->map[j][i] == 'B')
				ft_put_image(data, "./img/blackhole.xpm", i, j);
			i ++;
		}
		j ++;
	}	
}

void	ft_put_background(t_data *data)
{
	int		i;
	int		j;

	j = 1;
	while (j + 1 < data->map->ymap)
	{
		i = 1;
		while (i + 1 < data->map->xmap)
		{
			ft_put_image(data, "./img/back_g.xpm", i, j);
			i ++;
		}
		j ++;
	}
}
