/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:06 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:32:06 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

t_data	*init_game(char *path)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data) * 1);
	if (!data)
		exit(0);
	data->map = ft_give_map(path);
	if (!data->map)
	{
		free(data);
		exit(0);
	}
	ft_possibl(data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 64 * (data->map->xmap - 2) \
	, 64 * (data->map->ymap - 2), "so_long");
	ft_put_background(data);
	ft_put_object(data);
	ft_set_player(data);
	data->mv = '0';
	return (data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_quit(data, 1, 0);
	else if (data->mv2 != '0')
		return (0);
	else if (keycode == 124 || keycode == 2)
		data->mv = 'r';
	else if (keycode == 123 || keycode == 0)
		data->mv = 'l';
	else if (keycode == 126 || keycode == 13)
		data->mv = 'u';
	else if (keycode == 125 || keycode == 1)
		data->mv = 'd';
	return (0);
}

static void	ft_choose_mv(t_data *data, char ptr, int i)
{
	static int	icnt;

	if (!icnt)
		icnt = 0;
	if (ptr == 'r')
		icnt = ft_move_r(data, i, icnt);
	else if (ptr == 'l')
		icnt = ft_move_l(data, i, icnt);
	else if (ptr == 'u')
		icnt = ft_move_u(data, i, icnt);
	else if (ptr == 'd')
		icnt = ft_move_d(data, i, icnt);
	if (i >= 64)
		ft_printf("Mouvements : %i\n", icnt);
}

int	ft_loop_mv(t_data *data)
{
	static int	i;

	if (!data->mv2)
		i = 0;
	if (!data->mv2)
		data->mv2 = '0';
	if (data->mv2 != data->mv && i == 0)
	{
		data->mv2 = data->mv;
		i = 4;
	}
	if (i != 0 && i <= 64)
	{
		ft_choose_mv(data, data->mv2, i);
		i += 4;
	}
	if (i > 64)
	{
		data->mv2 = '0';
		data->mv = '0';
		i = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("Error\nLes arguments sont invalides\n");
		return (0);
	}
	data = init_game(argv[1]);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx_win, 17, 0, ft_press_cross, data);
	mlx_loop_hook(data->mlx, ft_loop_mv, data);
	mlx_loop(data->mlx);
}
