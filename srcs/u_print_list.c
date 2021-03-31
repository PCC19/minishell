/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 01:15:40 by user42            #+#    #+#             */
/*   Updated: 2021/03/31 02:14:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	u_print_list(t_list *list)
{
	printf("LISTA LIGADA !!!!\n");
	while (list)
	{
		//printf("%p\n", list);
		printf("%s\n", list->content);
		list = list->next;
	}
}
