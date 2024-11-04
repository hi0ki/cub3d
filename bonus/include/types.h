/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:58:48 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/11/04 14:08:58 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"

# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define WHITE 0xFFFFFFFF
# define BLACK 0x000000FF
# define GREY 0x808080FF
# define NEW 0xE0E0E0FF
# define ROTATION_SPEED 0.099
# define MOVE_SPEED 3.0
# define SIZE 20
# define WIDTH 1650
# define HEIGHT 1050

typedef struct s_helper
{
	char			*line;
	int				find[6];
	int				res;
	char			*ptr_line;
	char			*trim_line;
}					t_helper;

typedef struct s_lines
{
	int s_x;
	int e_x;
	int y;
	int x_pos;
	struct s_lines *next;
	struct s_lines *prv;
}t_lines;


typedef struct s_player
{
	int				x;
	int				y;
	double			px;
	double			py;
	double			angle;
	mlx_image_t		*image_player;
}					t_player;

typedef struct s_dis_H
{
	double			x_h;
	double			y_h;
	char			inter_type_h;
	int				x_o;
	int				y_o;
	bool			open_door;
	bool			is_door;
}					t_dis_H;

typedef struct s_dis_V
{
	double			x_v;
	double			y_v;
	char			inter_type_v;
	int				x_o;
	int				y_o;
	bool			open_door;
	bool			is_door;
}					t_dis_V;

typedef struct s_rays
{
	t_dis_H			dis_H;
	t_dis_V			dis_V;
	double 			rayangle;
}t_rays;

typedef struct s_map
{
	char			**str;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				f[3];
	int				c[3];
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*textur[5];
	mlx_texture_t   *gun[8];
	int index;
}					t_data;

#endif