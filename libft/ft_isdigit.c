/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:20:19 by pdi-pint          #+#    #+#             */
/*   Updated: 2023/10/10 12:20:22 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	int i = '8';
	printf("%d\n", ft_isdigit(i));
	return (0);
}*/