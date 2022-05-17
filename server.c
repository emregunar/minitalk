/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egunar <egunar@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:28:39 by egunar            #+#    #+#             */
/*   Updated: 2022/03/31 17:16:36 by egunar           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	sig2(siginfo_t *info, int k)
{
	if (k == 0)
		kill(info->si_pid, SIGUSR2);
	else
	{
		kill(info->si_pid, SIGUSR1);
		write (1, &k, 1);
	}
}

void	sig(int sign, siginfo_t *info, void *context)
{
	static char	k = 0;
	static int	b = 0;

	(void)context;
	if (sign == SIGUSR1)
	{
		k <<= 1;
		k |= 1;
		b++;
	}
	else if (sign == SIGUSR2)
	{
		k <<= 1;
		b++;
	}
	if (b == 8)
	{
		sig2(info, k);
		b = 0;
		k = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sig;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	s_sig.sa_sigaction = sig;
	s_sig.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &s_sig, 0);
	sigaction (SIGUSR2, &s_sig, 0);
	while (1)
		;
	return (0);
}
