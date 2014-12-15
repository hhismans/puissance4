/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:50:56 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/15 00:08:08 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BLUE 0x0000FF
#define RED 0xFF0000
#define YELLOW 0xFFFF00
#define WX 595
#define WY 510
#define XMIN -2
#define XMAX 1
#define YMIN -1
#define YMAX 1
#define it_max 1000

#define LEFT_CLIC 1
#define RIGHT_CLIC 3
#define MOL_CLIC 2
#define MOL_UP 4
#define MOL_DOWN 5
#define TOKEN_VOID 0
#define TOKEN_RED 1
#define TOKEN_YELLOW 2

void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color);

typedef struct	s_text
{
	void *img;
	int w;
	int h;
}				t_text;


typedef struct s_env
{
	void	*mlx;
	void	*img;
	t_text	tx_red;
	t_text	tx_yellow;
	t_text	tx_void;
	void	*win;
	int		color_turn;
	int		tab[7][6];
}				t_env;
