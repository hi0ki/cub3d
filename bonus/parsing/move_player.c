/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:50:58 by kadam             #+#    #+#             */
/*   Updated: 2024/10/15 20:06:14 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void* param)
{
    t_map *map = (t_map *)param;
    // (void)button;
    // (void)action;
    (void)mods;
    // (void)map;
    if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
    {
        if(map->index == 0 || map->index == 2)
            map->index = 1;
    }
    if (mods  )
    exit(1);
}

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_map *map = (t_map *)param;
    double new_px = map->player.px;
    double new_py = map->player.py;
    if (keydata.key == MLX_KEY_W && keydata.action)
    {
        new_px += cos(map->player.angle) * MOVE_SPEED;
        new_py += sin(map->player.angle) * MOVE_SPEED;
    }
    else if (keydata.key == MLX_KEY_S && keydata.action)
    {
        new_px -= cos(map->player.angle) * MOVE_SPEED;
        new_py -= sin(map->player.angle) * MOVE_SPEED;
    }
    else if (keydata.key == MLX_KEY_A && keydata.action)
    {
        new_px += sin(map->player.angle) * MOVE_SPEED;
        new_py -= cos(map->player.angle) * MOVE_SPEED;
    }
    else if (keydata.key == MLX_KEY_D && keydata.action)
    {
        new_px -= sin(map->player.angle) * MOVE_SPEED;
        new_py += cos(map->player.angle) * MOVE_SPEED;
    }
    if (keydata.key == MLX_KEY_LEFT && keydata.action)
        map->player.angle -= ROTATION_SPEED;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action)
        map->player.angle += ROTATION_SPEED;
    else if (keydata.key == MLX_KEY_ESCAPE && keydata.action)
        exit(1);
    map->player.angle = fmod(map->player.angle, 2 * M_PI);
    if (map->player.angle < 0)
        map->player.angle += 2 * M_PI;
    if (check_pos(map, new_py, new_px, 4) == 0)
    {
        map->player.px = new_px;
        map->player.py = new_py;
    }
}
