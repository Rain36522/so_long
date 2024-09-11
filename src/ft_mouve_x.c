/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouve_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:31:53 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:31:53 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

static void	ft_change_l(t_data *data, int x, int y, int i)
{
	char	c;

	if (data->map->map[y][x] == 'C')
		data->map->map[y][x] = 'F';
	if (i < 64)
	{
		c = data->map->map[data->map->yplayer][data->map->xplayer];
		ft_put_img_by_char(data, c, data->map->xplayer, data->map->yplayer);
	}
	c = data->map->map[data->map->yplayer][data->map->xplayer - 1];
	ft_put_img_by_char(data, c, data->map->xplayer - 1, data->map->yplayer);
	ft_move__offset(data, i * -1, 0);
	if (i >= 64)
		data->map->xplayer --;
}

int	ft_move_l(t_data *data, int i, int icnt)
{
	int		x;
	int		y;

	x = data->map->xplayer;
	y = data->map->yplayer;
	if (ft_strchr("0CFE", data->map->map[y][x - 1]))
	{
		if (i >= 64)
			icnt = ft_put_cnt_text(data, icnt);
		ft_change_l(data, x, y, i);
		if (i >= 64 && ft_check_flag(data) == 1 && \
			data->map->map[y][x - 1] == 'E')
			ft_quit(data, 2, icnt);
	}
	else if (data->map->map[y][x - 1] == 'B')
	{
		ft_change_l(data, x, y, i);
		if (i >= 64)
			ft_quit(data, 4, icnt);
	}
	return (icnt);
}

static void	ft_change_r(t_data *data, int x, int y, int i)
{
	char	c;

	if (data->map->map[y][x] == 'C')
		data->map->map[y][x] = 'F';
	if (i < 64)
	{
		c = data->map->map[data->map->yplayer][data->map->xplayer];
		ft_put_img_by_char(data, c, data->map->xplayer, data->map->yplayer);
	}
	c = data->map->map[data->map->yplayer][data->map->xplayer + 1];
	ft_put_img_by_char(data, c, data->map->xplayer + 1, data->map->yplayer);
	ft_move__offset(data, i, 0);
	if (i >= 64)
		data->map->xplayer ++;
}

int	ft_move_r(t_data *data, int i, int icnt)
{
	int		x;
	int		y;

	x = data->map->xplayer;
	y = data->map->yplayer;
	if (ft_strchr("0CFE", data->map->map[y][x + 1]))
	{
		if (i >= 64)
			icnt = ft_put_cnt_text(data, icnt);
		ft_change_r(data, x, y, i);
		if (i >= 64 && ft_check_flag(data) == 1 && \
			data->map->map[y][x + 1] == 'E')
			ft_quit(data, 2, icnt);
	}
	else if (data->map->map[y][x + 1] == 'B')
	{
		ft_change_r(data, x, y, i);
		if (i >= 64)
			ft_quit(data, 4, icnt);
	}
	return (icnt);
}
