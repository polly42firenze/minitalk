/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <pdi-pint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:30:58 by pdi-pint          #+#    #+#             */
/*   Updated: 2024/04/10 15:57:18 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	client(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (1 << i))
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	static int	pid;
	int			i;
	const char	*c;
	int			j;

	if (ac == 3)
	{
		j = 0;
		while (av[1][j])
		{
			if (av[1][j] >= '0' && av[1][j] <= '9')
				j++;
			else
				return (ft_printf("INVALID PID\n"), 0);
		}
		pid = ft_atoi(av[1]);
		c = av[2];
		i = 0;
		while (c[i])
			client(pid, c[i++]);
	}
	else
		ft_printf("ERRORE\n");
	client (pid, '\0');
	return (0);
}
