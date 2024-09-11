/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pudry <pudry@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:02 by pudry             #+#    #+#             */
/*   Updated: 2024/09/11 11:32:02 by pudry            ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	ft_quit(t_data *data, int j, int icnt)
{
	int	i;

	i = 0;
	if (j != 3)
		mlx_destroy_window(data->mlx, data->mlx_win);
	while (data->map->map[i])
	{
		free(data->map->map[i]);
		i ++;
	}
	free(data->map->map);
	free(data->map);
	free(data);
	if (j == 1)
		ft_printf("Vous avez abandonne\n");
	else if (j == 2)
		ft_printf("Vous avez gagne en %i mouvements\n", icnt);
	else if (j == 3)
		ft_printf("Error\nMalloc");
	else if (j == 4)
		ft_printf("Vous avez ete absorbe par le trou noir.\n");
	exit(0);
	return (0);
}

int	ft_check_flag(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	while (j < data->map->ymap)
	{
		i = 1;
		while (i < data->map->xmap)
		{
			if (data->map->map[j][i] == 'C')
				return (0);
			i ++;
		}
	j ++;
	}
	return (1);
}

int	ft_put_cnt_text(t_data *data, int i)
{
	char	*str;
	char	*ptr;

	i ++;
	ptr = ft_itoa(i);
	str = ft_strjoin("Mouvements : ", ptr);
	free(ptr);
	ft_put_img_by_char(data, data->map->map[1][1], 1, 1);
	ft_put_img_by_char(data, data->map->map[1][2], 2, 1);
	mlx_string_put(data->mlx, data->mlx_win, 5, 30, 0x00FFFFFF, str);
	free(str);
	return (i);
}

int	ft_press_cross(t_data *data)
{
	ft_quit(data, 1, 0);
	return (0);
} 

int	ft_check_elem(char *line)
{
	int	i;
	int	icnt;

	i = 0;
	icnt = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			icnt += 2;
		else if (line[i] == 'E')
			icnt += 3;
		i ++;
	}
	return (icnt);
}
