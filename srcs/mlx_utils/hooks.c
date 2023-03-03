/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:57:43 by hyunkyle          #+#    #+#             */
/*   Updated: 2023/03/03 15:04:40 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_rt.h"
#include "./mlx_util.h"
#include "../render/render.h"
#include "../Matrix/matrix.h"

static t_zip	*_make_zip(t_settings set, \
t_info_data *data, \
t_my_mlx	*mlx, \
int row)
{
	t_zip	*zip;

	zip = ft_malloc(sizeof(t_zip));
	zip->set = set;
	zip->data = data;
	zip->mlx = mlx;
	zip->start_row = row;
	return (zip);
}

static	void	multi_thread(t_settings set, t_info_data *data, \
t_my_mlx *my_mlx)
{
	pthread_t	tid[THREAD_N];
	int			i;
	t_zip		*zip[THREAD_N];

	i = -1;
	while (++i < THREAD_N)
	{
		zip[i] = _make_zip(set, data, my_mlx, \
		i * set.screen_height / THREAD_N);
		pthread_create(&tid[i], NULL, render, (void *)zip[i]);
	}
	i = -1;
	while (++i < THREAD_N)
		pthread_join(tid[i], NULL);
	i = -1;
	while (++i < THREAD_N)
		free(zip[i]);
}

// img ㅅㅐ로 만만들들어어야됨
void	start_draw(t_zip *zip)
{
	multi_thread(zip->set, (zip->data), zip->mlx);
	mlx_put_image_to_window(zip->mlx->mlx, \
	zip->mlx->mlx_win, zip->mlx->img.img, 100, 100);
}

void	update_center_x(t_zip *zip, long double e)
{
	if (zip->mdat->obj_type == PLANE)
		((t_plane *)(zip->mdat->object))->center.x += e;
	else if (zip->mdat->obj_type == SPHERE)
		((t_sphere *)(zip->mdat->object))->center.x += e;
	else if (zip->mdat->obj_type == CONE)
	{
		((t_cone *)(zip->mdat->object))->center.x += e;
		((t_cone *)(zip->mdat->object))->bot->center.x += e;
	}
	else if (zip->mdat->obj_type == DISK)
	{
		((t_disk *)(zip->mdat->object))->center.x += e;
		if (((t_disk *)(zip->mdat->object))->parent_type == CONE)
			((t_cone *)(((t_disk *)(zip->mdat->object))->parent))->\
			center.x += e;
		else
			((t_cylinder *)(((t_disk *)(zip->mdat->object))->parent))->\
			center.x += e;
	}
	else if (zip->mdat->obj_type == CYLINDER)
	{
		((t_cylinder *)(zip->mdat->object))->center.x += e;
		((t_cylinder *)(zip->mdat->object))->bot->center.x += e;
		((t_cylinder *)(zip->mdat->object))->top->center.x += e;
	}
	else
		return ;
}

void	update_center_y(t_zip *zip, long double e)
{
	if (zip->mdat->obj_type == PLANE)
		((t_plane *)(zip->mdat->object))->center.y += e;
	else if (zip->mdat->obj_type == SPHERE)
		((t_sphere *)(zip->mdat->object))->center.y += e;
	else if (zip->mdat->obj_type == CONE)
	{
		((t_cone *)(zip->mdat->object))->center.y += e;
		((t_cone *)(zip->mdat->object))->bot->center.y += e;
	}
	else if (zip->mdat->obj_type == DISK)
	{
		((t_disk *)(zip->mdat->object))->center.y += e;
		if (((t_disk *)(zip->mdat->object))->parent_type == CONE)
			((t_cone *)(((t_disk *)(zip->mdat->object))->parent))->\
			center.y += e;
		else
			((t_cylinder *)(((t_disk *)(zip->mdat->object))->parent))->\
			center.y += e;
	}
	else if (zip->mdat->obj_type == CYLINDER)
	{
		((t_cylinder *)(zip->mdat->object))->center.y += e;
		((t_cylinder *)(zip->mdat->object))->bot->center.y += e;
		((t_cylinder *)(zip->mdat->object))->top->center.y += e;
	}
	else
		return ;
}

void	update_center_z(t_zip *zip, long double e)
{
	if (zip->mdat->obj_type == PLANE)
		((t_plane *)(zip->mdat->object))->center.z += e;
	else if (zip->mdat->obj_type == SPHERE)
		((t_sphere *)(zip->mdat->object))->center.z += e;
	else if (zip->mdat->obj_type == CONE)
	{
		((t_cone *)(zip->mdat->object))->center.z += e;
		((t_cone *)(zip->mdat->object))->bot->center.z += e;
	}
	else if (zip->mdat->obj_type == DISK)
	{
		((t_disk *)(zip->mdat->object))->center.z += e;
		if (((t_disk *)(zip->mdat->object))->parent_type == CONE)
			((t_cone *)(((t_disk *)(zip->mdat->object))->parent))->\
			center.z += e;
		else
			((t_cylinder *)(((t_disk *)(zip->mdat->object))->parent))->\
			center.z += e;
	}
	else if (zip->mdat->obj_type == CYLINDER)
	{
		((t_cylinder *)(zip->mdat->object))->center.z += e;
		((t_cylinder *)(zip->mdat->object))->bot->center.z += e;
		((t_cylinder *)(zip->mdat->object))->top->center.z += e;
	}
	else
		return ;
}

void	update_center(t_zip *zip, char mode, long double e)
{
	if (mode == 'x')
		update_center_x(zip, e);
	if (mode == 'y')
		update_center_y(zip, e);
	if (mode == 'z')
		update_center_z(zip, e);
}

void	object_move(t_zip *zip, int keycode)
{
	long double	e;

	e = zip->set.scale / SCREEN_HEIGHT * 1000;
	if (zip->mdat->choice_obj == FALSE)
	{
		printf("choose obj\n");
		return ;
	}
	if (keycode == KEY_A)
		update_center(zip, 'x', e);
	else if (keycode == KEY_Q)
		update_center(zip, 'x', -e);
	else if (keycode == KEY_W)
		update_center(zip, 'y', e);
	else if (keycode == KEY_S)
		update_center(zip, 'y', -e);
	else if (keycode == KEY_E)
		update_center(zip, 'z', e);
	else if (keycode == KEY_D)
		update_center(zip, 'z', -e);
	// else if (keycode == KEY_ROT_XM)
	// 	zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
	// 	_rotate_mat_(-20, 'x'));
	// else if (keycode == KEY_ROT_XP)
	// 	zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
	// 	_rotate_mat_(20, 'x'));
	// else if (keycode == KEY_ROT_YM)
	// 	zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
	// 	_rotate_mat_(-20, 'y'));
	// else if (keycode == KEY_ROT_YP)
	// 	zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
	// 	_rotate_mat_(20, 'y'));
	// else if (keycode == KEY_ROT_ZM)
	// 	zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
	// 	_rotate_mat_(-20, 'z'));
	// else if (keycode == KEY_ROT_ZP){
	// 	zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
	// 	_rotate_mat_(20, 'z'));
	// }
	start_draw(zip);	
}

void	camera_move(t_zip *zip, int keycode)
{
	long double	e;

	e = zip->set.scale / SCREEN_HEIGHT * 1000;
	if (keycode == KEY_A)
		zip->set.camera.center.x += e;
	else if (keycode == KEY_Q)
		zip->set.camera.center.x -= e;
	else if (keycode == KEY_W)
		zip->set.camera.center.y += e;
	else if (keycode == KEY_S)
		zip->set.camera.center.y -= e;
	else if (keycode == KEY_E)
		zip->set.camera.center.z += e;
	else if (keycode == KEY_D)
		zip->set.camera.center.z -= e;
	else if (keycode == KEY_MINUS)
		zip->set.scale = tan(degrees_to_radians(clamp\
		((zip->set.fov += 10), 1, 179) * 0.5));
	else if (keycode == KEY_PLUS)
		zip->set.scale = tan(degrees_to_radians(clamp\
		((zip->set.fov -= 10), 1, 179) * 0.5));
	else if (keycode == KEY_ROT_XM)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(-20, 'x'));
	else if (keycode == KEY_ROT_XP)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(20, 'x'));
	else if (keycode == KEY_ROT_YM)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(-20, 'y'));
	else if (keycode == KEY_ROT_YP)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(20, 'y'));
	else if (keycode == KEY_ROT_ZM)
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(-20, 'z'));
	else if (keycode == KEY_ROT_ZP){
		zip->set.camera_to_world = _mul_mat_(zip->set.camera_to_world, \
		_rotate_mat_(20, 'z'));
	}
	else 
		return ;
	start_draw(zip);
	mlx_string_put(zip->mlx->mlx, (zip->mlx->mlx_win), 10, 20, 0xffffff, "InterFace : \n.\n");
	mlx_string_put(zip->mlx->mlx, (zip->mlx->mlx_win), 10, 30, 0xffffff, "q(x_up),a(x_down)\n");
	mlx_string_put(zip->mlx->mlx, (zip->mlx->mlx_win), 10, 40, 0xffffff, "e(z_up),d(z_down)\n)\n");
	mlx_string_put(zip->mlx->mlx, (zip->mlx->mlx_win), 10, 50, 0xffffff, "if you want to change, key press 'c'.\n\n");	
}

void	move(t_zip *zip, int keycode)
{
	if (zip->mdat->mode == CMODE)
		camera_move(zip, keycode);
	else
		object_move(zip, keycode);

}

int	key_hook(int keycode, t_zip *zip)
{
	if (keycode == KEY_C)
	{
		if (zip->mdat->mode == CMODE)
		{
			printf("OMODE\n");
			zip->mdat->mode = OMODE;
		}
		else 
		{
			printf("CMODE\n");
			zip->mdat->mode = CMODE;
		}
	}
	if (keycode == ESC)
	{
		mlx_destroy_window(zip->mlx, zip->mlx->mlx_win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_A || keycode == KEY_S \
		|| keycode == KEY_D || keycode == KEY_Q || \
		keycode == KEY_W || keycode == KEY_E || \
		keycode == KEY_PLUS || keycode == KEY_MINUS)
		move(zip, keycode);
	else if (keycode == KEY_ROT_XM || keycode == KEY_ROT_XP || \
		keycode == KEY_ROT_YM || keycode == KEY_ROT_YP || \
		keycode == KEY_ROT_ZM || keycode == KEY_ROT_ZP)
		move(zip, keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_zip *zip)
{
	t_ray		obj_ray;
	double		world_x;
	double		world_y;
	t_hit_rec	hit_rec;

	if (button == 1 && zip->mdat->mode == OMODE && \
	zip->mdat->choice_obj == FALSE)
	{
		hit_rec = _init_rec_();
		world_x = (2 * (x - 100+ 0.5) / (double)(zip->set.screen_width) - 1) * \
		zip->set.scale;
		world_y = (1 - 2 * (y - 100+ 0.5) / (double)(zip->set.screen_height)) \
		* zip->set.aspect_ratio * zip->set.scale;
		printf("%d %d %lf %lf\n", x, y, world_x, world_y);
		obj_ray.dir = vec_unit(_mul_vec_mat(zip->set.camera_to_world, \
			vec_2_arr_vec3(vec(world_x, world_y, -1))));
		obj_ray.origin = vec_copy(zip->set.camera.center);
		printf("%lf %lf %lf\n", obj_ray.origin.x, obj_ray.origin.y, obj_ray.origin.z);
		if (trace_hit(zip->data->objects, &hit_rec, obj_ray))
		{
			zip->mdat->object = hit_rec.object;
			zip->mdat->choice_obj = TRUE;
			zip->mdat->obj_type = hit_rec.obj_type;
			printf("You choice one obj: type : %d\n", zip->mdat->obj_type);
		}
	}	
	return (0);
}

void	my_hook(t_zip *zip)
{
	t_m_dat	*dat;

	dat = ft_malloc(sizeof(t_m_dat));
	dat->mode = CMODE;
	zip->mdat = dat;
	mlx_key_hook(zip->mlx->mlx_win, key_hook, zip);
	mlx_mouse_hook(zip->mlx->mlx_win, mouse_hook, zip);	
}

// img ㅅㅐ로 만만들들어어야됨
// void	start_draw(t_vars *vars)
// {
// 	t_data	img;

// 	init_img(&img, vars);
// 	put_pixel(&img, vars);
// 	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
// }


// int	mouse_hook(int button, int x, int y, t_vars *vars)
// {
// 	if (button == 4)
// 		zoom_in(x, y, vars);
// 	else if (button == 5)
// 		zoom_out(x, y, vars);
// 	else if (button == 1 || button == 2)
// 		change_color(vars);
// 	return (0);
// }

// void	zoom_in(int x, int y, t_vars *vars)
// {
// 	long double	e;

// 	vars->size *= 0.9;
// 	e = vars->size / WIN_HEIGHT;
// 	vars->point_x += (x - WIN_WIDTH / 2) * e * 0.1;
// 	vars->point_y += (WIN_HEIGHT / 2 - y) * e * 0.1;
// 	start_draw(vars);
// }

// void	zoom_out(int x, int y, t_vars *vars)
// {
// 	long double	e;

// 	vars->size *= 1.1;
// 	e = vars->size / WIN_HEIGHT;
// 	vars->point_x -= (x - WIN_WIDTH / 2) * e * 0.1;
// 	vars->point_y -= (WIN_HEIGHT / 2 - y) * e * 0.1;
// 	start_draw(vars);
// }