/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 19:59:32 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/15 20:16:41 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int evalgame(int tab[][6])
{
	int i;
	int j;
	int token_ali;

	token_ali = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 7)
		{
			if (tab[j][i] != TOKEN_VOID)
			{
				if (tab[j][i] == tab[j + 1][i])
				{
					if (token_ali < 2)
						token_ali = 2;
					if (tab[j][i] == tab[j + 2][i])
					{
						if (token_ali < 3)
							token_ali = 3;
						if (tab[j][i] == tab[j + 3][i])
						{
							token_ali = 4;
							return (100);
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
