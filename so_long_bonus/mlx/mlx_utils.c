/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:39:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 20:45:29 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	info(t_instance *instance)
{
	ft_printf("moves = %d\n", instance->moves);
	ft_printf("items = %d\n", instance->count);
	ft_printf("kills = %d\n", instance->kills);
	ft_printf("\n");
}

int	end_instance(t_instance *instance)
{
	exit(0);
}

void	put_img(t_instance *instance, void *img, int y, int x)
{
	mlx_put_image_to_window(instance->mlx,
		instance->win, img, x * SIZE, y * SIZE);
}

void	*xpm_img(t_instance *instance, char *name)
{
	void	*img;
	int		a;

	img = mlx_xpm_file_to_image(instance->mlx, name, &(a), &(a));
	if (!img)
	{
		ft_printf("img '%s' does not exist", name);
		exit(1);
	}
	return (img);
}

void	display(t_instance *instance, int i, int j)
{
	if (instance->map[i][j] == '0')
		put_img(instance, instance->img.floor, i, j);
	if (instance->map[i][j] == '1')
		put_img(instance, instance->img.wall, i, j);
	if (instance->map[i][j] == 'E')
		put_img(instance, instance->img.exit, i, j);
	if (instance->map[i][j] == 'P')
	{
		if (i == instance->exit[0] && j == instance->exit[1])
			put_img(instance, instance->img.exit, i, j);
		else
			put_img(instance, instance->img.floor, i, j);
		put_img(instance, instance->img.player, i, j);
	}
	if (instance->map[i][j] == 'C')
	{
		put_img(instance, instance->img.floor, i, j);
		put_img(instance, instance->img.item, i, j);
	}
}
