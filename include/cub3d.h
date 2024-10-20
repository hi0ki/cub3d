/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadam <kadam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:12:37 by kadam             #+#    #+#             */
/*   Updated: 2024/10/20 11:58:29 by kadam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../gnl/get_next_line.h"
# include "types.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*				libft				*/
int		ft_lenarray(char **array);
void	free_2d_array(char **array);
void	ft_putstrn_fd(char *s, int fd);
char	**ft_split(char *s, char *c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*_strjoin(char *s1, char *s2);
int		_strlen(char *str);

/*                    parsing                      */
int		process_color(int *map_color, char *str, char *name);
int		process_line(char *c, char **ptr_line, int *find);
int		read_map(char *line, int fd, t_map *map_struct, char *ptr_line);
int		process_path(char **str, int i, char *name, char **path);
int		read_file(int fd, t_helper *helper);
int		check_all(int ac, char **av, t_map *map_struct, int fd);

//texturing:

void	draw_f_c(t_map *map);
int	get_color(t_map *map, t_rays rays, int tex_y,
		int texture_index);
int		tex_index(t_dis_H dis_H, t_dis_V dis_V, double rayangle);

/*                      utils                   */
void	check_map(t_map *s_map);
char	**copy_arr(char **array);
void	put_err(char *str, t_map *s_map);

/*				check_utils						*/
int		valid_char(char **arr, t_map *s_map);
int		found_zero_index(char **arr, t_map *s_map);
int		valid_path(char **map, int y, int x);
void	key_hook(mlx_key_data_t keydata, void *param);

/*					raycasting					*/
void	start_raycasting(t_map *map);
int		check_ray(t_map *map, double y, double x);
double	cal_dis(double xp, double yp, double x, double y);
int		check_pos(t_map *map, double py, double px, double num_pix);
void draw_3d(t_map *map, double line_height, int i, t_rays rays);
void	start_drawing(void *ptr);
#endif