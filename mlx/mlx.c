/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:37:13 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 13:25:32 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	run(t_instance *instance)
{
	int	i;
	int	j;

	instance->frame++;
	if (instance->frame >= 100)
		instance->frame = 0;
	i = 0;
	while (instance->map[i])
	{
		j = 0;
		while (instance->map[i][j])
		{
			display(instance, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

static void	init_img(t_instance *instance)
{
	instance->img.floor = xpm_img(instance, "./xpm/chars/floor.xpm");
	instance->img.player = xpm_img(instance, "./xpm/chars/player_t.xpm");
	instance->img.wall = xpm_img(instance, "./xpm/chars/wall.xpm");
	instance->img.item = xpm_img(instance, "./xpm/chars/item.xpm");
	instance->img.exit = xpm_img(instance, "./xpm/chars/exit.xpm");
}

void	launch_mlx(t_instance *instance)
{
	instance->mlx = mlx_init();
	instance->win = mlx_new_window(instance->mlx, instance->width * SIZE,
			instance->height * SIZE, "!so_long");
	init_img(instance);
	mlx_loop_hook(instance->mlx, run, instance);
	mlx_hook(instance->win, 2, 0, key_press, instance);
	mlx_hook(instance->win, 17, 0, end_instance, NULL);
	mlx_loop(instance->mlx);
}
