/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:39:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/23 14:53:19 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	info(t_instance *instance)
// {
// 	ft_printf("moves = %d\n", instance->moves);
// 	ft_printf("items = %d\n", instance->count);
// 	ft_printf("kills = %d\n", instance->kills);
// 	ft_printf("\n");
// }

int	end_instance(t_instance *instance)
{
	exit(0);
}

void	put_img(t_instance *instance, void *img, int y, int x)
{
	if (img)
		mlx_put_image_to_window(instance->mlx,
			instance->win, img, x * SIZE, y * SIZE);
	else
		ft_printf("not image lmao\n");
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

void	display(t_instance *n, int i, int j)
{
	if (n->map[i][j] == '0')
		put_img(n, n->img.floor, i, j);
	if (n->map[i][j] == '1')
		put_img(n, n->img.wall, i, j);
	if (n->map[i][j] == 'E')
		put_img(n, n->img.exit, i, j);
	if (n->map[i][j] == 'C')
	{
		put_img(n, n->img.floor, i, j);
		put_img(n, n->img.item[n->anim], i, j);
	}
	if (n->map[i][j] == 'V')
		put_img(n, n->img.ennemy, i, j);
	if (n->map[i][j] == 'D')
		put_img(n, n->img.dead, i, j);
	if (i == n->pos[0] && j == n->pos[1])
		put_img(n, n->img.player, i, j);
}
