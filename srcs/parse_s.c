/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:33:13 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 03:37:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void parse_sq(char c, int *i, t_estado_parse_s *estado)
{
	if (ft_is_in(c, "\'"))
	{
		if (*estado == NORMAL)
			*estado = SINGLE_QUOTE;
		else if (*estado == SINGLE_QUOTE)
			*estado = NORMAL;
		(*i)++;
		if (*estado == DOUBLE_QUOTE)
			(*i)--;
	}
}

void parse_dq(char c, int *i, t_estado_parse_s *estado)
{
	if (ft_is_in(c, "\""))
	{
		if (*estado == NORMAL)
			*estado = DOUBLE_QUOTE;
		else if (*estado == DOUBLE_QUOTE)
			*estado = NORMAL;
		(*i)++;
		if (*estado == SINGLE_QUOTE)
			(*i)--;
	}
}

int	parse_s(t_v *v, char *linha)
{
	int						i;
	int						j;
	t_estado_parse_s		estado;

	//v->expandido = (char*)malloc(1000);
	//ft_bzero(v->expandido,1000);
	v->expandido = (char*)ft_calloc(1000, sizeof(char));
	estado = NORMAL;
	i = 0;
	j = 0;
	while (linha[i] != 0)
	{
		parse_sq(linha[i], &i, &estado);
		parse_dq(linha[i], &i, &estado);
		if (ft_is_in(linha[i],"$") && 
			(estado == NORMAL || estado == DOUBLE_QUOTE))
		{
				//EXPANDE
				expande(v, &linha[i], &i, &j);
				//expande(v, "$DISPLAY", &i, &j);
				//ft_memcpy(&v->expandido[j], "xxx" ,3);
				//j+=3;
		}
		else
		{
			ft_memcpy(&v->expandido[j], &linha[i],2);
			j++;
		}
		i++;
	}
	printf("\n");
	printf("expandido: %s\n", v->expandido);
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
