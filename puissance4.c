/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 14:35:09 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/15 00:05:34 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "puissance4.h"
#include <stdio.h>
#include <mlx.h>


static void	tab_init(int tab[][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 7)
		{
			tab[j][i] = TOKEN_VOID;
			j++;
		}
		i++;
	}
}

static void	update_tab(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 7)
		{
			if ((e->tab)[j][i] == TOKEN_RED)
				mlx_put_image_to_window(e->mlx, e->win, e->tx_red.img, e->tx_red.w * j, e->tx_red.h * i);
			else if ((e->tab)[j][i] == TOKEN_VOID)
				mlx_put_image_to_window(e->mlx, e->win, e->tx_void.img, e->tx_void.w * j, e->tx_void.h * i);
			else if ((e->tab)[j][i] == TOKEN_YELLOW)
				mlx_put_image_to_window(e->mlx, e->win, e->tx_yellow.img, e->tx_yellow.w * j, e->tx_yellow.h * i);
			j++;
		}
		i++;
	}
}

void	insert_token(int tab[][6], int column, int elem)
{
	int i;

	i = 5;
	while (i >= 0 && tab[column][i] != TOKEN_VOID)
	{
		i--;
	}
	if (tab[column][i] == TOKEN_VOID)
	{
		tab[column][i] = elem;
	}
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 7)
		{
			ft_putnbr(tab[j][i]);
			j++;
			ft_putchar('\t');
		}
		ft_putendl("");
		i++;
	}
}
void	set_env(t_env *e, char *title, int w, int h)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, w, h, title);
	e->img = mlx_new_image(e->mlx, w, h);
	e->tx_red.img = mlx_xpm_file_to_image(e->mlx, "./xpm/red.xpm",
			&(e->tx_red.w), &(e->tx_red.h));
	e->tx_yellow.img = mlx_xpm_file_to_image(e->mlx, "./xpm/yellow.xpm",
			&(e->tx_yellow.w), &(e->tx_yellow.h));
	e->tx_void.img = mlx_xpm_file_to_image(e->mlx, "./xpm/void.xpm",
			&(e->tx_void.w), &(e->tx_void.h));
	e->color_turn = YELLOW;
	tab_init(e->tab);
}

int		mouse_hook(int boutton, int x, int y, t_env *e)
{
	printf("bouton = %d, x = %d, y = %d\n", boutton, x / 85, y);
	if (boutton == LEFT_CLIC)
	{
		if (e->color_turn == TOKEN_RED)
			e->color_turn = TOKEN_YELLOW;
		else
			e->color_turn = TOKEN_RED;
		insert_token(e->tab, x / 85, e->color_turn);
		update_tab(e);
	}
	return (0);
}

int		main(void)
{
	t_env e;

	set_env(&e, "Puissance 4(2)", 700,700);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
