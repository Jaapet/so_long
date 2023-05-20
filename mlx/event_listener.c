/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:48:38 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/20 16:59:47 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int key, t_instance *instance)
{
	if (key == 53)
		exit(0);
	if (key == 13)
		printf("monter\n");
	return (0);
}
