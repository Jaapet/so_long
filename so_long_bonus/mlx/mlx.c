/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:37:13 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/23 17:35:08 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_bar(t_instance *n)
{
	int	x;
	int	y;
	int	i;

	y = 20;
	i = 0;
	while (y < 43)
	{
		x = 370 + i;
		while (x >= 0)
		{
			mlx_pixel_put(n->mlx, n->win, x, y, 0xFFFFFF);
			x--;
		}
		if (y < 31)
			i++;
		else
			i--;
		y++;
	}
}

static void	print_score(t_instance *n)
{
	mlx_string_put(n->mlx, n->win, 20, 20,
		0xFFFFFF, ft_strjoin("Moves : ", ft_itoa(n->moves)));
	mlx_string_put(n->mlx, n->win, 140, 20,
		0xFFFFFF, ft_strjoin("Kills : ", ft_itoa(n->kills)));
	mlx_string_put(n->mlx, n->win, 260, 20,
		0xFFFFFF, ft_strjoin("Items : ", ft_itoa(n->count)));
}

static int	run(t_instance *instance)
{
	int	i;
	int	j;

	instance->frame++;
	if (instance->frame >= 100)
		instance->frame = 0;
	if (instance->frame % 4 == 0)
		instance->anim++;
	if (instance->anim >= 10)
		instance->anim = 0;
	display_kill_anim(instance);
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
	print_score(instance);
	return (0);
}

static void	init_img(t_instance *instance)
{
	instance->img.floor = xpm_img(instance, "./xpm/sand.xpm");
	instance->img.player = xpm_img(instance, "./xpm/player.xpm");
	instance->img.wall = xpm_img(instance, "./xpm/wall.xpm");
	instance->img.exit = xpm_img(instance, "./xpm/exit.xpm");
	instance->img.ennemy = xpm_img(instance, "./xpm/mine/mine_on.xpm");
	instance->img.dead = xpm_img(instance, "./xpm/mine/mine_off.xpm");
	init_item(instance);
	init_kill(instance);
}

void	launch_mlx(t_instance *n)
{
	n->mlx = mlx_init();
	n->win = mlx_new_window(n->mlx, n->width * SIZE,
			n->height * SIZE, "!so_long");
	init_img(n);
	mlx_loop_hook(n->mlx, run, n);
	mlx_hook(n->win, 2, 0, key_press, n);
	mlx_hook(n->win, 17, 0, end_instance, n);
	mlx_loop(n->mlx);
}
