/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtestut <vtestut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:02:27 by vtestut           #+#    #+#             */
/*   Updated: 2023/03/17 14:38:05 by vtestut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// todo : make bonus
// todo : make minilibx
// todo : erreur mort bonus map3

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		ft_error("mlx_init failed");
		exit(EXIT_FAILURE);
	}
	ft_init_vars(&vars);
	if (!ft_check_param(ac, av, &vars))
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		exit(EXIT_FAILURE);
	}
	if (!ft_pathfinding(&vars))
		ft_close_and_free(&vars);
	ft_set_sprites(&vars);
	ft_display_game(&vars);
	ft_close_and_free(&vars);
	return (EXIT_SUCCESS);
}

void	ft_init_vars(t_vars *vars)
{
	vars->win = NULL;
	vars->hero1 = NULL;
	vars->hero2 = NULL;
	vars->wall = NULL;
	vars->floor = NULL;
	vars->coffee = NULL;
	vars->exit = NULL;
	vars->exit2 = NULL;
	vars->x_hero = 0;
	vars->y_hero = 0;
	vars->moves = 0;
	vars->width = 64;
	vars->height = 64;
	ft_init_vars_aux(vars);
}

void	ft_init_vars_aux(t_vars *vars)
{
	vars->map_vars.map = NULL;
	vars->map_vars.cloned_map = NULL;
	vars->map_vars.exit_c = 0;
	vars->map_vars.nb_of_cols = 0;
	vars->map_vars.nb_of_rows = 0;
	vars->map_vars.player = 0;
	vars->map_vars.exit = 0;
	vars->map_vars.collectible = 0;
	vars->map_vars.collectible_c = 0;
	vars->bug_v.bug1 = NULL;
	vars->bug_v.bug2 = NULL;
	vars->bug_v.x_bug = 0;
	vars->bug_v.y_bug = 0;
	vars->bug_v.nb_of_bugs = 0;
}

void	ft_set_sprites(t_vars *vars)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	vars->hero1 = mlx_xpm_file_to_image(vars->mlx, "xpm/idle1.xpm", &w, &h);
	vars->hero2 = mlx_xpm_file_to_image(vars->mlx, "xpm/idle2.xpm", &w, &h);
	vars->wall = mlx_xpm_file_to_image(vars->mlx, "xpm/wall.xpm", &w, &h);
	vars->floor = mlx_xpm_file_to_image(vars->mlx, "xpm/floor.xpm", &w, &h);
	vars->coffee = mlx_xpm_file_to_image(vars->mlx, "xpm/coffee.xpm", &w, &h);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "xpm/exit.xpm", &w, &h);
	vars->exit2 = mlx_xpm_file_to_image(vars->mlx, "xpm/exit2.xpm", &w, &h);
	vars->bug_v.bug1 = mlx_xpm_file_to_image(vars->mlx, "xpm/bug1.xpm", &w, &h);
	vars->bug_v.bug2 = mlx_xpm_file_to_image(vars->mlx, "xpm/bug2.xpm", &w, &h);
	if (!vars->hero1 || !vars->hero2 || !vars->wall || !vars->floor
		|| !vars->coffee || !vars->exit || !vars->exit2 || !vars->bug_v.bug1
		|| !vars->bug_v.bug2)
		ft_xpm_protection(vars);
}

void	ft_xpm_protection(t_vars *vars)
{
	ft_error("XPM file not found");
	if (vars->hero1)
		mlx_destroy_image(vars->mlx, vars->hero1);
	if (vars->hero2)
		mlx_destroy_image(vars->mlx, vars->hero2);
	if (vars->wall)
		mlx_destroy_image(vars->mlx, vars->wall);
	if (vars->floor)
		mlx_destroy_image(vars->mlx, vars->floor);
	if (vars->coffee)
		mlx_destroy_image(vars->mlx, vars->coffee);
	if (vars->exit)
		mlx_destroy_image(vars->mlx, vars->exit);
	if (vars->exit2)
		mlx_destroy_image(vars->mlx, vars->exit2);
	if (vars->bug_v.bug1)
		mlx_destroy_image(vars->mlx, vars->bug_v.bug1);
	if (vars->bug_v.bug2)
		mlx_destroy_image(vars->mlx, vars->bug_v.bug2);
	ft_quit(vars);
	return ;
}
