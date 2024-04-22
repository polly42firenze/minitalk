/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:27:12 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/04/09 16:27:41 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	server(int signum)
{
	static unsigned char	c;
	static int				i;

	if (signum == SIGUSR1)
		c |= 1 << i;
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID:%d\n", getpid());
	signal(SIGUSR1, server);
	signal(SIGUSR2, server);
	while (1)
		;
	return (0);
}
