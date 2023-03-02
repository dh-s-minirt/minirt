/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:47:42 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/24 14:23:24 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	_swap_(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double	fresnel(const t_vec i, const t_vec n, const double ior)
{
	double	cosi;
	double	etai;
	double	etat;
	double	sint;
	double	cost;

	etat = ior;
	etai = 1.0;
	cosi = vec_dot(i, n);
	if (cosi > 0)
		_swap_(&etai, &etat);
	sint = etai / etat * sqrt(fmax_d(0, 1 - pow(cosi, 2)));
	if (sint >= 1)
		return (1.0);
	cosi = fabs(cosi);
	cost = sqrt(fmax_d(0, 1 - pow(sint, 2)));
	return ((pow(((etat * cosi) - (etai * cost)) / ((etat * cosi) + \
	(etai * cost)), 2) \
	+ \
	pow(((etai * cost) - (etat * cosi)) / ((etai * cost) + \
	(etat * cosi)), 2)) \
	/ 2);
}

t_vec	refract(const t_vec i, t_vec n, const double ior)
{
	double	cosi;
	double	etai;
	double	etat;
	double	eta;
	double	k;

	etat = ior;
	etai = 1.0;
	cosi = vec_dot(i, n);
	if (cosi < 0)
		cosi = -cosi;
	else
	{
		_swap_(&etai, &etat);
		n = vec_mul(n, -1);
	}
	eta = etai / etat;
	k = 1 - pow(eta, 2) * (1 - pow(cosi, 2));
	if (k < 0)
		return (vec(0, 0, 0));
	else
		return (vec_add(vec_mul(i, eta), \
		vec_mul(n, eta * cosi - sqrt(k))));
}

double	_outside_(double dot)
{
	if (dot < 0)
		return (1.0);
	else
		return (-1.0);
}

t_color	_shade_refract(t_hit_rec hit_rec, t_info_data *data, \
t_ray ray, t_fres_data fres_dat)
{
	t_color			refl_color;
	t_color			refr_color;
	t_ray			refr_ray;
	t_ray			refl_ray;
	const double	krefl = clamp(fresnel(ray.dir, hit_rec.hit_normal, \
	fres_dat.ior), 0, 1);

	if (krefl < 1.0)
	{
		refr_ray.dir = vec_unit(refract(ray.dir, hit_rec.hit_normal, \
		fres_dat.ior));
		refr_ray.origin = vec_add(hit_rec.contact_point, vec_mul(hit_rec.\
		hit_normal, -BIAS * _outside_(vec_dot(hit_rec.hit_normal, ray.dir))));
		refr_color = ray_casting(refr_ray, data, fres_dat.depth + 1);
	}
	else
		refr_color = vec(0, 0, 0);
	refl_ray.dir = vec_unit(v_reflect(ray.dir, hit_rec.hit_normal));
	refl_ray.origin = vec_add(hit_rec.contact_point, vec_mul(hit_rec.\
	hit_normal, BIAS * _outside_(vec_dot(hit_rec.hit_normal, ray.dir))));
	refl_color = ray_casting(refl_ray, data, fres_dat.depth + 1);
	return (vec_add(vec_mul(refl_color, krefl), \
	vec_mul(refr_color, (1 - krefl))));
}
