/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheras-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 07:49:10 by jheras-f          #+#    #+#             */
/*   Updated: 2020/01/31 07:49:13 by jheras-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H
# include <stdint.h>

typedef struct		s_file_header
{
	uint16_t		bf_type;
	uint32_t		bf_size;
	uint16_t		bf_reserved1;
	uint16_t		bf_reserved2;
	uint32_t		bf_offbits;
}					t_file_header;

typedef struct		s_info_header
{
	uint32_t		bi_size;
	int32_t			bi_height;
	int32_t			bi_width;
	uint16_t		bi_planes;
	uint16_t		bi_bit_count;
	uint32_t		bi_compression;
	uint32_t		bi_img_size;
	int32_t			bi_x_ppm;
	int32_t			bi_y_ppm;
	uint32_t		bi_clr_used;
	uint32_t		bi_clr_important;
}					t_info_header;

typedef struct		s_color_table
{
	uint8_t			*rgb_blue;
	uint8_t			rgb_green;
	uint8_t			rgb_red;
	uint8_t			rgb_reserved;
}					t_color_table;

typedef struct		s_image
{
	t_file_header	fh;
	t_info_header	fi;
	t_color_table	ct;
}					t_image;

#endif
