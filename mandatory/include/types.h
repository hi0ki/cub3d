/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:58:48 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/10/18 17:03:38 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TYPES_H
#  define TYPES_H

#include "cub3d.h"

#define RED 0xFF0000FF
#define GREEN 0x00FF00FF
#define WHITE 0xFFFFFFFF
#define BLACK 0x000000FF
#define GREY 0x808080FF
#define NEW 0xE0E0E0FF
#define ROTATION_SPEED 0.1
#define MOVE_SPEED 10.0
#define Size 30
#define WIDTH 1650
#define HEIGHT	1050

typedef struct s_ray
{
	double angle;
	double x;
	double y;
} t_ray;

typedef struct s_player
{
	int x;
	int y;
	double px; // Player's x position
	double py; // Player's y position
	double angle;
	mlx_image_t *image_player;
} t_player;

typedef struct s_dis_H
{
	double x_H;
	double y_H; 
	char inter_type_H;
} t_dis_H;

typedef struct s_dis_V
{
	double x_V;
	double y_V; 
	char inter_type_V;
} t_dis_V;

typedef struct s_map
{
	// read the all map
	char **str;
	// read the map
	char **map_array;
	// read the path
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	// read the color
	int F[3];
	int C[3];
	// for player
	t_player player;
	mlx_t *mlx;
	mlx_image_t *image;
	t_ray ray;
	mlx_texture_t *textur[4];
} t_map;

# endif