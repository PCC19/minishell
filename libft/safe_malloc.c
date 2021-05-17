/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:15:53 by user42            #+#    #+#             */
/*   Updated: 2021/05/18 00:18:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void *safe_malloc(size_t size)
{
	//void *ptr = malloc(size); 

	if (!ptr && (size > 0))
	{ 
		perror("malloc failed!");
		exit(EXIT_FAILURE);
	}
	return ptr; 
} 
