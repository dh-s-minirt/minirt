/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daegulee <daegulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:11:00 by daegulee          #+#    #+#             */
/*   Updated: 2023/02/07 08:12:48 by daegulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    // for (int j = image_height-1; j >= 0; --j) {
    //     std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    //     for (int i = 0; i < image_width; ++i) {
    //         color pixel_color(0, 0, 0);
    //         for (int s = 0; s < samples_per_pixel; ++s) {
    //             auto u = (i + random_double()) / (image_width-1);
    //             auto v = (j + random_double()) / (image_height-1);
    //             ray r = cam.get_ray(u, v);
    //             pixel_color += ray_color(r, world, max_depth);
					// vec3f dir;
					// settings.cameraToWrld.multidrMatrix(vec3(x,y,-1), dir);
					// dir.normalize()
					// *(pix++) castRay();
    //         }
    //         write_color(std::cout, pixel_color, samples_per_pixel);
    //     }
    // }