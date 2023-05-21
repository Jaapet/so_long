/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:03:30 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 20:47:47 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_instance *n)
{
	if (n->map[n->pos[0] - 1][n->pos[1]] != '1')
	{
		if ((n->map[n->pos[0] - 1][n->pos[1]] == 'E' && n->items == n->count)
			|| n->map[n->pos[0] - 1][n->pos[1]] == 'V')
			throw_msg(n->map[n->pos[0] - 1][n->pos[1]]);
		if (n->map[n->pos[0] - 1][n->pos[1]] == 'C')
			n->count++;
		n->map[n->pos[0] - 1][n->pos[1]] = 'P';
		if (n->pos[0] == n->exit[0] && n->pos[1] == n->exit[1])
			n->map[n->pos[0]][n->pos[1]] = 'E';
		else
			n->map[n->pos[0]][n->pos[1]] = '0';
		n->pos[0]--;
		n->moves++;
		info(n);
	}
}

void	down(t_instance *n)
{
	if (n->map[n->pos[0] + 1][n->pos[1]] != '1')
	{
		if ((n->map[n->pos[0] + 1][n->pos[1]] == 'E' && n->items == n->count)
			|| n->map[n->pos[0] + 1][n->pos[1]] == 'V')
			throw_msg(n->map[n->pos[0] + 1][n->pos[1]]);
		if (n->map[n->pos[0] + 1][n->pos[1]] == 'C')
			n->count++;
		n->map[n->pos[0] + 1][n->pos[1]] = 'P';
		if (n->pos[0] == n->exit[0]
			&& n->pos[1] == n->exit[1])
			n->map[n->pos[0]][n->pos[1]] = 'E';
		else
			n->map[n->pos[0]][n->pos[1]] = '0';
		n->pos[0]++;
		n->moves++;
		info(n);
	}
}

void	left(t_instance *n)
{
	if (n->map[n->pos[0]][n->pos[1] - 1] != '1')
	{
		if ((n->map[n->pos[0]][n->pos[1] - 1] == 'E' && n->items == n->count)
			|| n->map[n->pos[0]][n->pos[1] - 1] == 'V')
			throw_msg(n->map[n->pos[0]][n->pos[1] - 1]);
		if (n->map[n->pos[0]][n->pos[1] - 1] == 'C')
			n->count++;
		n->map[n->pos[0]][n->pos[1] - 1] = 'P';
		if (n->pos[0] == n->exit[0]
			&& n->pos[1] == n->exit[1])
			n->map[n->pos[0]][n->pos[1]] = 'E';
		else
			n->map[n->pos[0]][n->pos[1]] = '0';
		n->pos[1]--;
		n->moves++;
		info(n);
	}
}

void	right(t_instance *n)
{
	if (n->map[n->pos[0]][n->pos[1] + 1] != '1')
	{
		if ((n->map[n->pos[0]][n->pos[1] + 1] == 'E' && n->items == n->count)
			|| n->map[n->pos[0]][n->pos[1] + 1] == 'V')
			throw_msg(n->map[n->pos[0]][n->pos[1] + 1]);
		if (n->map[n->pos[0]][n->pos[1] + 1] == 'C')
			n->count++;
		n->map[n->pos[0]][n->pos[1] + 1] = 'P';
		if (n->pos[0] == n->exit[0]
			&& n->pos[1] == n->exit[1])
			n->map[n->pos[0]][n->pos[1]] = 'E';
		else
			n->map[n->pos[0]][n->pos[1]] = '0';
		n->pos[1]++;
		n->moves++;
		info(n);
	}
}
