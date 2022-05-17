/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:28:32 by egunar            #+#    #+#             */
/*   Updated: 2022/03/31 17:06:22 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	sig(int sign)
{
	static int	i = 0;

	if (sign == SIGUSR1)
		i++;
	else if (sign == SIGUSR2)
		ft_printf("Gönderilen = %d", i);
}

void	send_char(char *c, int pid, int count)
{
	int	i;

	i = -1;
	while (c[++i])
	{
		count = 9;
		while (--count > 0)
		{
			if (c[i] & 128)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			c[i] <<= 1;
		}
	}
	if (c[i] == 0)
	{
		count = 8;
		while (--count >= 0)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int argc, char *argv[])
{
	signal (SIGUSR1, sig);
	signal (SIGUSR2, sig);
	if (argc == 3 && !ft_isalpha(argv[1][0]))
	{
		send_char(argv[2], ft_atoi(argv[1]), 0);
	}
	else
		ft_printf("Hatali giris, lutfen tekrar deneyiniz");
}
