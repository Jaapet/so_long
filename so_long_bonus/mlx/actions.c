/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:27:02 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/23 14:54:06 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	attack(t_instance *n)
{
	int	i;
	int	j;

	n->anim = 0;
	i = n->pos[0] - 1;
	while (i <= n->pos[0] + 1)
	{
		j = n->pos[1] - 1;
		while (j <= n->pos[1] + 1)
		{
			if (n->map[i][j] == 'V')
			{
				n->map[i][j] = 'K';
				n->kills++;
			}
			j++;
		}
		i++;
	}
	n->moves++;
}
