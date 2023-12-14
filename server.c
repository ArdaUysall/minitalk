/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auysal <auysal@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:24:02 by auysal            #+#    #+#             */
/*   Updated: 2023/10/16 12:24:04 by auysal           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int num)
{
	char	c;

	if (num > 9)
		ft_putnbr (num / 10);
	c = (num % 10) + 48;
	write(1, &c, 1);
}

void	ft_handle(int sig)
{
	static int	a = 128;
	static char	c;

	if (sig == SIGUSR1)
		c += a;
	a = a / 2;
	if (a == 0)
	{
		write(1, &c, 1);
		a = 128;
		c = 0;
	}
}

int	main(void)
{
	write(1, "PID:", 4);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	while (1)
		pause();
	return (0);
}
