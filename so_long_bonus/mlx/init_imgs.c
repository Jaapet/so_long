/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:57:05 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/22 19:31:16 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_item(t_instance *instance)
{
	instance->img.item[0] = xpm_img(instance, "./xpm/bullet/bullet_1.xpm");
	instance->img.item[1] = xpm_img(instance, "./xpm/bullet/bullet_2.xpm");
	instance->img.item[2] = xpm_img(instance, "./xpm/bullet/bullet_3.xpm");
	instance->img.item[3] = xpm_img(instance, "./xpm/bullet/bullet_4.xpm");
	instance->img.item[4] = xpm_img(instance, "./xpm/bullet/bullet_5.xpm");
	instance->img.item[5] = xpm_img(instance, "./xpm/bullet/bullet_5.xpm");
	instance->img.item[6] = xpm_img(instance, "./xpm/bullet/bullet_4.xpm");
	instance->img.item[7] = xpm_img(instance, "./xpm/bullet/bullet_3.xpm");
	instance->img.item[8] = xpm_img(instance, "./xpm/bullet/bullet_2.xpm");
	instance->img.item[9] = xpm_img(instance, "./xpm/bullet/bullet_1.xpm");
}

void	init_kill(t_instance *instance)
{
	instance->img.kill[0] = xpm_img(instance, "./xpm/mine/mine_1.xpm");
	instance->img.kill[1] = xpm_img(instance, "./xpm/mine/mine_1.xpm");
	instance->img.kill[2] = xpm_img(instance, "./xpm/mine/mine_2.xpm");
	instance->img.kill[3] = xpm_img(instance, "./xpm/mine/mine_2.xpm");
	instance->img.kill[4] = xpm_img(instance, "./xpm/mine/mine_3.xpm");
	instance->img.kill[5] = xpm_img(instance, "./xpm/mine/mine_3.xpm");
	instance->img.kill[6] = xpm_img(instance, "./xpm/mine/mine_4.xpm");
	instance->img.kill[7] = xpm_img(instance, "./xpm/mine/mine_4.xpm");
	instance->img.kill[8] = xpm_img(instance, "./xpm/mine/mine_5.xpm");
	instance->img.kill[9] = xpm_img(instance, "./xpm/mine/mine_5.xpm");
}
