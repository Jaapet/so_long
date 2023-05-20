/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:10:17 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/20 14:48:08 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '.' && file[i])
		i++;
	if (file[i] == '.' && file[i + 1] == 'b' && file[i + 2] == 'e'
		&& file[i + 3] == 'r' && !file[i + 4])
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_instance	*instance;

	if (argc != 2 || !is_ber(argv[1]))
		throw_error();
	instance = build_instance(argv[1]);
	
	launch_mlx(instance);
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
