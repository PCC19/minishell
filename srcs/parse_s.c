/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:33:13 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 23:55:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	parse_s(t_v *v, char *linha)
{
	int						i;
	int						j;
	enum e_estado_parse_s	estado;

	v->expandido = (char*)malloc(1000);
	ft_bzero(v->expandido,1000);
	estado = NORMAL;
	i = 0;
	j = 0;
	while (linha[i] != 0)
	{
		if (ft_is_in(linha[i], "\'"))
		{
			if (estado == NORMAL)
				estado = SINGLE_QUOTE;
			else if (estado == SINGLE_QUOTE)
				estado = NORMAL;
			i++;
			if (estado == DOUBLE_QUOTE)
				i--;
			//printf(".");
			printf("%d",(int)estado);
		}
		if (ft_is_in(linha[i], "\""))
		{
			if (estado == NORMAL)
				estado = DOUBLE_QUOTE;
			else if (estado == DOUBLE_QUOTE)
				estado = NORMAL;
			i++;
			if (estado == SINGLE_QUOTE)
				i--;
			//printf(":");
			printf("%d",(int)estado);
		}
		if (ft_is_in(linha[i],"$"))
		{
			if(estado == NORMAL || estado == DOUBLE_QUOTE)
			{
				i++;
				printf("%d",(int)estado);
				//EXPANDE
				//incr GDE
			}
		}
		else
		{
			printf("%d",(int)estado);
			ft_memcpy(&v->expandido[j], &linha[i],2);
			//printf("%c",v->expandido[j]);
			j++;
		}
		i++;
	}
	printf("\n");
	printf("expandido: %s\n", v->expandido);
	free(v->expandido);
	return (0);
}



/*
estado = NORMAL
loop ate chegar no fim da string linha
	se ' ou " muda estado e incrementa
	se char dif $
		copia char
		incr
	se $ e estado == NORMAL ou estado = "
		incr
		EXPANDE
		incrementa gde
	else
		copia char
		incrementa
*/
