/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:37:13 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/20 15:48:42 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_instance(void)
{
	exit(0);
}

void	put_img(t_instance *instance, void *img, int y, int x)
{
	mlx_put_image_to_window(instance->mlx, instance->win, img, x * SIZE, y * SIZE);
}

int	run(t_instance *instance)
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
			if (instance->map[i][j] == '0')
				put_img(instance, instance->img.floor, i, j);
			if (instance->map[i][j] == '1')
				put_img(instance, instance->img.wall, i, j);
			if (instance->map[i][j] == 'E')
				put_img(instance, instance->img.exit, i, j);
			if (instance->map[i][j] == 'P')
				put_img(instance, instance->img.player, i, j);
			if (instance->map[i][j] == 'C')
				put_img(instance, instance->img.item, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	key_press(int key, t_instance *instance)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		printf("monter\n");
	return (0);
}
void	*xpm_img(t_instance *instance, char *name)
{
	void	*img;
	int		a;

	img = mlx_xpm_file_to_image(instance->mlx, name, &(a), &(a));
	if (!img)
		exit(1);
	return (img);
}

void	init_img(t_instance *instance)
{
	instance->img.floor = xpm_img(instance, "./xpm/chars/floor.xpm");
	instance->img.player = xpm_img(instance, "./xpm/chars/player.xpm");
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
