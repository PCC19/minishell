/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcunha <pcunha@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:04:21 by pcunha            #+#    #+#             */
/*   Updated: 2021/05/10 18:16:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bit(int x)
{
	int	i;

	i = sizeof(x) * 8 - 1;
	while (i >= 0)
	{
		ft_putchar_fd((x >> i & 1) + '0', 1);
		i--;
	}
}
