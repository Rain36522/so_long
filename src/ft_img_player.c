/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:31:49 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:31:49 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static char	*ft_path_player(int x, int y)
{
	if (x < 0)
		return ("./img/fuseL.xpm");
	else if (x > 0)
		return ("./img/fuseR.xpm");
	else if (y > 0)
		return ("./img/fuseD.xpm");
	else
		return ("./img/fuseU.xpm");
}

void	ft_move__offset(t_data *data, int of_x, int of_y)
{
	int		xwidth;
	int		yheight;
	int		xpos;
	int		ypos;
	void	*img;

	xwidth = 64;
	yheight = 64;
	ft_path_player(0, 0);
	xpos = ((data->map->xplayer - 1) * xwidth) + of_x;
	ypos = ((data->map->yplayer - 1) * yheight) + of_y;
	img = mlx_xpm_file_to_image(data->mlx, ft_path_player(of_x, of_y), \
													&xwidth, &yheight);
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, xpos, ypos);
	mlx_destroy_image(data->mlx, img);
}
