/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:10:17 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 15:28:34 by ndesprez         ###   ########.fr       */
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
		throw_error("map has to be .ber\n");
	instance = build_instance(argv[1]);
	if (instance)
		launch_mlx(instance);
	return (0);
}

// void	aff_map(char **map, int height)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			printf("%c", map[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	printf("\n");
// }
