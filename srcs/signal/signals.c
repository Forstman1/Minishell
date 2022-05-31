/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:21:18 by            #+#    #+#             */
/*   Updated: 2022/05/27 18:21:19 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	handler(int signal)
{
	int i;

	i = 0;
	if (signal == SIGINT)
		printf("\n");
	else if (signal == SIGQUIT)
		i++;
}

void	signals()
{
	struct sigaction sa;

	sa.sa_sigaction = handler;
	sigaction(SIGINT, &sa, NULL);
}