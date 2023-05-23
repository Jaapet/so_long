/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:57:38 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/22 19:49:41 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_kill_anim(t_instance *n)
{
	int	i;
	int	j;

	i = 0;
	while (n->map[i])
	{
		j = 0;
		while (n->map[i][j])
		{
			if (n->map[i][j] == 'K')
			{
				put_img(n, n->img.kill[n->anim], i, j);
				if (n->anim == 9)
					n->map[i][j] = 'D';
			}
			j++;
		}
		i++;
	}
}
