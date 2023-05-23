/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:03:30 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/23 14:54:00 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_instance *n)
{
	if (n->map[n->pos[0] - 1][n->pos[1]] != '1')
	{
		if (n->map[n->pos[0] - 1][n->pos[1]] == 'C')
		{
			n->map[n->pos[0] - 1][n->pos[1]] = '0';
			n->count++;
		}
		n->pos[0]--;
		n->moves++;
		if ((n->map[n->pos[0]][n->pos[1]] == 'E' && n->items == n->count)
			|| n->map[n->pos[0]][n->pos[1]] == 'V')
			throw_msg(n->map[n->pos[0]][n->pos[1]]);
	}
}

void	down(t_instance *n)
{
	if (n->map[n->pos[0] + 1][n->pos[1]] != '1')
	{
		if (n->map[n->pos[0] + 1][n->pos[1]] == 'C')
		{
			n->map[n->pos[0] + 1][n->pos[1]] = '0';
			n->count++;
		}
		n->pos[0]++;
		n->moves++;
		if ((n->map[n->pos[0]][n->pos[1]] == 'E' && n->items == n->count)
			|| n->map[n->pos[0]][n->pos[1]] == 'V')
			throw_msg(n->map[n->pos[0]][n->pos[1]]);
	}
}

void	left(t_instance *n)
{
	if (n->map[n->pos[0]][n->pos[1] - 1] != '1')
	{
		if (n->map[n->pos[0]][n->pos[1] - 1] == 'C')
		{
			n->map[n->pos[0]][n->pos[1] - 1] = '0';
			n->count++;
		}
		n->pos[1]--;
		n->moves++;
		if ((n->map[n->pos[0]][n->pos[1]] == 'E' && n->items == n->count)
			|| n->map[n->pos[0]][n->pos[1]] == 'V')
			throw_msg(n->map[n->pos[0]][n->pos[1]]);
	}
}

void	right(t_instance *n)
{
	if (n->map[n->pos[0]][n->pos[1] + 1] != '1')
	{
		if (n->map[n->pos[0]][n->pos[1] + 1] == 'C')
		{
			n->map[n->pos[0]][n->pos[1] + 1] = '0';
			n->count++;
		}
		n->pos[1]++;
		n->moves++;
		if ((n->map[n->pos[0]][n->pos[1]] == 'E' && n->items == n->count)
			|| n->map[n->pos[0]][n->pos[1]] == 'V')
			throw_msg(n->map[n->pos[0]][n->pos[1]]);
	}
}
