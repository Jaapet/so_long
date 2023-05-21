/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:03:30 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 13:50:15 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up(t_instance *instance)
{
	if (instance->map[instance->pos[0] - 1][instance->pos[1]] != '1')
	{
		if (instance->map[instance->pos[0] - 1][instance->pos[1]] == 'E'
			&& instance->items == instance->count)
			exit(0);
		if (instance->map[instance->pos[0] - 1][instance->pos[1]] == 'C')
			instance->count++;
		instance->map[instance->pos[0] - 1][instance->pos[1]] = 'P';
		if (instance->pos[0] == instance->exit[0]
			&& instance->pos[1] == instance->exit[1])
			instance->map[instance->pos[0]][instance->pos[1]] = 'E';
		else
			instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[0]--;
		instance->moves++;
		ft_printf("moves = %d\n", instance->moves);
	}
}

void	down(t_instance *instance)
{
	if (instance->map[instance->pos[0] + 1][instance->pos[1]] != '1')
	{
		if (instance->map[instance->pos[0] + 1][instance->pos[1]] == 'E'
			&& instance->items == instance->count)
			exit(0);
		if (instance->map[instance->pos[0] + 1][instance->pos[1]] == 'C')
			instance->count++;
		instance->map[instance->pos[0] + 1][instance->pos[1]] = 'P';
		if (instance->pos[0] == instance->exit[0]
			&& instance->pos[1] == instance->exit[1])
			instance->map[instance->pos[0]][instance->pos[1]] = 'E';
		else
			instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[0]++;
		instance->moves++;
		ft_printf("moves = %d\n", instance->moves);
	}
}

void	left(t_instance *instance)
{
	if (instance->map[instance->pos[0]][instance->pos[1] - 1] != '1')
	{
		if (instance->map[instance->pos[0]][instance->pos[1] - 1] == 'E'
			&& instance->items == instance->count)
			exit(0);
		if (instance->map[instance->pos[0]][instance->pos[1] - 1] == 'C')
			instance->count++;
		instance->map[instance->pos[0]][instance->pos[1] - 1] = 'P';
		if (instance->pos[0] == instance->exit[0]
			&& instance->pos[1] == instance->exit[1])
			instance->map[instance->pos[0]][instance->pos[1]] = 'E';
		else
			instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[1]--;
		instance->moves++;
		ft_printf("moves = %d\n", instance->moves);
	}
}

void	right(t_instance *instance)
{
	if (instance->map[instance->pos[0]][instance->pos[1] + 1] != '1')
	{
		if (instance->map[instance->pos[0]][instance->pos[1] + 1] == 'E'
			&& instance->items == instance->count)
			exit(0);
		if (instance->map[instance->pos[0]][instance->pos[1] + 1] == 'C')
			instance->count++;
		instance->map[instance->pos[0]][instance->pos[1] + 1] = 'P';
		if (instance->pos[0] == instance->exit[0]
			&& instance->pos[1] == instance->exit[1])
			instance->map[instance->pos[0]][instance->pos[1]] = 'E';
		else
			instance->map[instance->pos[0]][instance->pos[1]] = '0';
		instance->pos[1]++;
		instance->moves++;
		ft_printf("moves = %d\n", instance->moves);
	}
}
