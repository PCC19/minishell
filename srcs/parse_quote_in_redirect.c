/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote_in_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 00:26:49 by user42            #+#    #+#             */
/*   Updated: 2021/05/26 00:49:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_quote_in_redirect(t_v *v, int *k, char *c)
{	

	char aux[MIL];

	ft_bzero(aux, MIL);
	ff(v->expanded, k);
	copy_until(aux, v->expanded, c, k);
	add_line_to_cmd_args(v, aux);
}
