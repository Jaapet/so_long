/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:10:17 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/19 14:42:21 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_instance	*instance;

	if (argc != 2 || !is_ber(argv[1]))
		throw_error();
	instance = malloc(sizeof(t_instance));
	if (!instance)
		return (0);
	instance->height = get_height(argv[1]);
	instance->width = get_width(argv[1]);
	instance->map = parse_map(argv[1], instance->height);
	if (!instance->map)
		return (0);
	//check_map(instance);
	int i = 0;
	while (i < instance->height)
	{
		int j = 0;
		while (instance->map[i][j])
		{
			printf("%c", instance->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
