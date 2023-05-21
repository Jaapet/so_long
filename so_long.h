/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:05:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/05/21 12:57:16 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>

# define SIZE 64

/*------INSTANCE_STRUCTURE------*/
typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*item;
	void	*exit;
}	t_img;

typedef struct s_game
{
	char	**map;
	int		height;
	int		width;
	int		*pos;
	int		*exit;
	int		items;
	int		count;
	int		moves;

	int		frame;
	void	*mlx;
	void	*win;
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

/*------PRINTF------*/
int			ft_printf(const char *format, ...);

/*------ERROR------*/
void		throw_error(void);

/*------UTILS------*/
int			ft_strlen(char *str);
char		*ft_strdup(const char *src);
char		**ft_free(char **list, int len);
void		aff_map(char **map, int height);

/*------MLX------*/
void		launch_mlx(t_instance *game);

/*------MLX_UTILS------*/
int			end_instance(void);
void		put_img(t_instance *instance, void *img, int y, int x);
void		*xpm_img(t_instance *instance, char *name);
void		display(t_instance *instance, int i, int j);

/*------EVENT_LISTENER------*/
int			key_press(int key, t_instance *instance);

/*------MOVES------*/
void		up(t_instance *instance);
void		down(t_instance *instance);
void		left(t_instance *instance);
void		right(t_instance *instance);

#endif