/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:05:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/20 11:38:30 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define SIZE 64

/*------INSTANCE_STRUCTURE------*/
typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*collec;
	void	*exit;
}	t_img;

typedef struct s_game
{
	int		frame;
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		*pos;
	t_img	img;
}	t_instance;

/*------PARSING------*/
int			get_height(char *file);
int			get_width(char *file);
char		**parse_map(char *file, int size);
t_instance	*build_instance(char *file);

/*------CHECKING------*/
void		check_path(t_instance *instance);
void		check_map(t_instance *instance);

/*------GNL------*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);

void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_strchri(const char *s, int c);
char		*ft_strjoin_bufs(char *s1, char const *s2);

/*------ERROR------*/
void		throw_error(void);

/*------UTILS------*/
int			ft_strlen(char *str);
char		*ft_strdup(const char *src);
char		**ft_free(char **list, int len);

#endif