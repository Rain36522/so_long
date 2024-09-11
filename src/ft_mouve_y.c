/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:31:55 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:31:55 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_change_u(t_data *data, int x, int y, int i)
{
	char	c;

	if (data->map->map[y][x] == 'C')
		data->map->map[y][x] = 'F';
	if (i < 64)
	{
		c = data->map->map[data->map->yplayer][data->map->xplayer];
		ft_put_img_by_char(data, c, data->map->xplayer, data->map->yplayer);
	}
	c = data->map->map[data->map->yplayer - 1][data->map->xplayer];
	ft_put_img_by_char(data, c, data->map->xplayer, data->map->yplayer - 1);
	ft_move__offset(data, 0, i * -1);
	if (i >= 64)
		data->map->yplayer --;
}

int	ft_move_u(t_data *data, int i, int icnt)
{
	int		x;
	int		y;

	x = data->map->xplayer;
	y = data->map->yplayer;
	if (ft_strchr("0CFE", data->map->map[y - 1][x]))
	{
		if (i >= 64)
			icnt = ft_put_cnt_text(data, icnt);
		ft_change_u(data, x, y, i);
		if (i >= 64 && ft_check_flag(data) == 1 && \
			data->map->map[y - 1][x] == 'E')
			ft_quit(data, 2, icnt);
	}
	else if (data->map->map[y - 1][x] == 'B')
	{
		ft_change_u(data, x, y, i);
		if (i >= 64)
			ft_quit(data, 4, icnt);
	}
	return (icnt);
}

static void	ft_change_d(t_data *data, int x, int y, int i)
{
	char	c;

	if (data->map->map[y][x] == 'C')
		data->map->map[y][x] = 'F';
	if (i < 64)
	{
		c = data->map->map[data->map->yplayer][data->map->xplayer];
		ft_put_img_by_char(data, c, data->map->xplayer, data->map->yplayer);
	}
	c = data->map->map[data->map->yplayer + 1][data->map->xplayer];
	ft_put_img_by_char(data, c, data->map->xplayer, data->map->yplayer + 1);
	ft_move__offset(data, 0, i);
	if (i >= 64)
		data->map->yplayer ++;
}

int	ft_move_d(t_data *data, int i, int icnt)
{
	int		x;
	int		y;

	x = data->map->xplayer;
	y = data->map->yplayer;
	if (ft_strchr("0CFE", data->map->map[y + 1][x]))
	{
		if (i >= 64)
			icnt = ft_put_cnt_text(data, icnt);
		ft_change_d(data, x, y, i);
		if (i >= 64 && ft_check_flag(data) == 1 && \
			data->map->map[y + 1][x] == 'E')
			ft_quit(data, 2, icnt);
	}
	else if (data->map->map[y + 1][x] == 'B')
	{
		ft_change_d(data, x, y, i);
		if (i >= 64)
			ft_quit(data, 4, icnt);
	}
	return (icnt);
}
