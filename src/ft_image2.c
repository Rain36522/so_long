/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:31:45 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:31:45 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

void	ft_set_player(t_data *data)
{
	int		j;
	int		i;
	t_map	*my_map;

	my_map = data->map;
	j = 1;
	while (j < my_map->ymap)
	{
		i = 1;
		while (i < my_map->xmap)
		{
			if (my_map->map[j][i] == 'P')
			{
				my_map->xplayer = i;
				my_map->yplayer = j;
				my_map->map[j][i] = '0';
				return ;
			}
			i ++;
		}
	j ++;
	}
}

void	ft_put_image(t_data *data, char *path, int i, int j)
{
	int		xwidth;
	int		yheight;
	int		xpos;
	int		ypos;
	void	*img;

	xwidth = 64;
	yheight = 64;
	xpos = (i - 1) * xwidth;
	ypos = (j - 1) * yheight;
	img = mlx_xpm_file_to_image(data->mlx, path, &xwidth, &yheight);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, xpos, ypos);
	mlx_destroy_image(data->mlx, img);
}
