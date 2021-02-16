/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:16:31 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/07 12:27:10 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	write_pixel(int num, unsigned char *arr)
{
	arr[0] = (unsigned char)(num & 255);
	arr[1] = (unsigned char)((num >> 8) & 255);
	arr[2] = (unsigned char)((num >> 16) & 255);
	arr[3] = (unsigned char)((num >> 24) & 255);
}

void	write_image(t_all *all, unsigned char *bytes, int bmpsize)
{
	int	i;
	int	x;
	int	y;
	int	color;

	i = 54;
	y = all->data->hight;
	while (y-- > 0)
	{
		x = 0;
		while (x < all->data->width && i < bmpsize)
		{
			color = my_get_img_color(&all->save, x, y);
			write_pixel(color, bytes + i);
			i += 4;
			x++;
		}
	}
}

void	create_header(t_all *all, unsigned char *bytes, int bmpsize)
{
	int	pix;

	bytes[0] = 'B';
	bytes[1] = 'M';
	write_pixel(bmpsize, bytes + 2);
	bytes[10] = (unsigned char)54;
	bytes[14] = (unsigned char)40;
	write_pixel(all->data->width, bytes + 18);
	write_pixel(all->data->hight, bytes + 22);
	bytes[26] = (unsigned char)1;
	bytes[28] = (unsigned char)32;
	bytes[34] = (unsigned char)32;
	pix = (int)((double)70 * 39.37);
	write_pixel(pix, bytes + 38);
	write_pixel(pix, bytes + 42);
}

int		create_screenshot(t_all *all)
{
	int				fd;
	int				size;
	unsigned char	*bytes;

	if ((fd = open(SCREENSHOT, O_CREAT | O_WRONLY | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) <= 0)
		return (ft_errors(SCRFL));
	size = all->data->width * all->data->hight * 4 + 54;
	if (!(bytes = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (ft_errors(ALLER));
	create_header(all, bytes, size);
	write_image(all, bytes, size);
	if (write(fd, bytes, size) < size)
		return (ft_errors(WRIER));
	free(bytes);
	close(fd);
	ft_putendl_fd(SVGOD, 1);
	return (0);
}
