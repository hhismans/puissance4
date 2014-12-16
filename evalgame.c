/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:59:32 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/16 17:26:47 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "libft.h"

int evalgame(int tab[][6], int TOKEN_COLOR)
{
	int i;
	int j;
	int token_ali;

	token_ali = 0;
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 7)
		{
			if (tab[j][i] == TOKEN_COLOR)
			{
				if (j + 1 < 7 && tab[j][i] == tab[j + 1][i])
				{
						token_ali += 2;
					if (j + 2 < 7 && tab[j][i] == tab[j + 2][i])
					{
							token_ali += 3;
						if (j + 3 < 7 && tab[j][i] == tab[j + 3][i])
						{
							token_ali += 100;
							//return (100);
						}
					}
				}
				if (i+1 < 6 && tab[j][i] == tab[j][i + 1])
				{
						token_ali += 2;
					if ( i + 2 < 6 && tab[j][i] == tab[j][i + 2])
					{
							token_ali += 3;
						if (i + 3 < 6 && tab[j][i] == tab[j][i + 3])
						{
							token_ali += 100;
						}
					}
				}
				if (i+1 < 6 && j + 1 < 7 && tab[j][i] == tab[j + 1][i + 1])
				{
						token_ali += 2;
					if (i+2 < 6 && j + 2 < 7 && tab[j][i] == tab[j + 2][i + 2])
					{
							token_ali += 3;
						if (i+3 < 6 && j + 3 < 7 && tab[j][i] == tab[j + 3][i + 3])
						{
							token_ali += 100;
						}
					}
				}
				if (i - 1 > 0 && j + 1 < 7 && tab[j][i] == tab[j + 1][i - 1])
				{
						token_ali += 2;
					if (i-2 > 0 && j + 2 < 7 && tab[j][i] == tab[j + 2][i - 2])
					{
							token_ali += 3;
						if (i-3 > 0 && j + 3 < 7 && tab[j][i] == tab[j + 3][i - 3])
						{
							token_ali += 100;
						}
					}
				}
			}
			j++;
		}
		i++;
	}
	return (token_ali * 10);
}

void	tabcpy(int tab_cmp[][6], int tab[][6])
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 7)
		{
			tab_cmp[j][i] = tab[j][i];
			j++;
		}
		i++;
	}
}


int		recur(int tab[][6], int profondeur, int TOKEN_IA, int TOKEN_TURN)
{
	int i;
	int tab_tmp[7][6];
	int valeur;
	int tmp;
	int ret;

	i = 0;
	while (i < 7)
	{
		ft_putendl("\nPROFONDEUR");
		ft_putnbr(profondeur);
		ft_putendl("\ncolone = ");
		ft_putnbr(i);
		tabcpy(tab_tmp, tab);
		insert_token(tab_tmp, i, TOKEN_TURN);
		puttab(tab_tmp);
		if (profondeur > 0)
			tmp = recur(tab_tmp, profondeur - 1, TOKEN_IA, TOKEN_TURN % 2 + 1);
		else
		{
			tmp = evalgame(tab_tmp, TOKEN_IA);
			tmp = tmp - evalgame(tab_tmp, TOKEN_IA % 2 +1);
			ft_putstr("\nevalgamei = ");
			ft_putnbr(tmp);
		}
		if (TOKEN_IA == TOKEN_TURN && tmp > valeur) //si c'est le tour de l'ia maximiser le score
		{
			valeur = tmp;
			ret = i;
		}
		else if (tmp < valeur)  // si tour joueur minimiser le score
		{
			valeur = tmp;
			ret = i;
		}
		i++;
	}
	if (profondeur == 3)
	{
		ft_putstr("\nreturn VALEUR");
		ft_putnbr(valeur);
		return (ret);
	}
	return (valeur);
}

/*
int		recur(int tab[][6], int TOKEN_IA, int profondeur)
{
	int i;
	int tab_tmp[7][6];
	int valeur;
	int tmp;
	int prof_tmp;

	valeur = -2000000000;
	i = 0;
	while (i < 7)
	{
		prof_tmp = profondeur;
		tabcpy(tab_tmp, tab);
		insert_token(tab_tmp, i, TOKEN_TURN);
		prof_tmp--;
		if (prof_tmp > 0)
			tmp = recur(tab_tmp, TOKEN_IA, prof_tmp);
		if (prof_tmp == 0)
			tmp = evalgame(tab, TOKEN_IA);
		if (tmp > valeur)
		{
			valeur = tmp;
			if (profondeur == 3)
				*column = i;
		}
		i++;
	}
	return (valeur);
}*/
