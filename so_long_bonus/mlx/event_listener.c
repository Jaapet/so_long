/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:48:38 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 20:37:43 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int key, t_instance *instance)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		up(instance);
	if (key == 1)
		down(instance);
	if (key == 0)
		left(instance);
	if (key == 2)
		right(instance);
	if (key == 49)
		attack(instance);
	return (0);
}
