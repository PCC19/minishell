/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:42:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/09 04:00:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	expande(t_v *v, char *linha, int *i, int *j)
{
	int		k;
	int		q;
	char	*substr;
	(void) *i;
	(void) *j;
	(void) *v;
	
	linha++;
	printf("linha: |%s|\n",linha);
	k = 0;
	//while(linha[k] != ' ' && k < (int)ft_strlen(linha))
	while(!(ft_is_in(linha[k], " \'\"")) && k < (int)ft_strlen(linha))
		k++;
	printf("k: %d\n", k);
	// busca esta string nas variaveis de ambiente
	q = 0;
	while(v->env[q] != 0)
	{
		if (!ft_strncmp(linha, v->env[q],k))
		{
			//pega conteudo da variavel
			substr = ft_strchr(v->env[q], '=');
			if(ft_strlen(substr) > 0)
				substr++;
		}
		q++;
	}
	// se nao encontrou variavel
	//copia para expandido
	ft_memcpy(&v->expandido[(*j)], substr, ft_strlen(substr));
	//pega conteudo da variavel
	//calcula len do conteudo da variavel
	(*j) = (*j) + ft_strlen(substr); 
	(*i) = (*i) + k;	

/*V


	k = 0;
	while(v->env[k] != 0)
	{
		if (ft_strncmp(substr, v->env[k], ft_strlen(substr)))
		{
			// achou
			// pega conteudo da variavel
			printf("env: %s\n", v->env[k]);
		}
		k++;
	}
	free(substr);
*/
}


/*pega substr ate prox SPC
busca esta string nas variaveis de ambiente
pega conteudo da variavel
calcula len do conteudo da variavel
incrementa j
copia para expandido
*/
