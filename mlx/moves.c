/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:03:30 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/20 18:21:08 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_instance *instance)
{
	if (instance->map[instance->pos[0] - 1][instance->pos[1]] != '1')
	{
		instance->map[instance->pos[0] - 1][instance->pos[1]] = 'P';
		instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[0]--;
	}
}

void	down(t_instance *instance)
{
	if (instance->map[instance->pos[0] + 1][instance->pos[1]] != '1')
	{
		instance->map[instance->pos[0] + 1][instance->pos[1]] = 'P';
		instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[0]++;
	}
}

void	left(t_instance *instance)
{
	if (instance->map[instance->pos[0]][instance->pos[1] - 1] != '1')
	{
		instance->map[instance->pos[0]][instance->pos[1] - 1] = 'P';
		instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[1]--;
	}
}

void	right(t_instance *instance)
{
	if (instance->map[instance->pos[0]][instance->pos[1] + 1] != '1')
	{
		instance->map[instance->pos[0]][instance->pos[1] + 1] = 'P';
		instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[1]++;
	}
}
