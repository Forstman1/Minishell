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
#include "../../ms_head.h"

// void	handler(int signal)
// {
// 	int i;

// 	i = 0;
// 	if (signal == SIGINT)
// 		printf("\nMinishell ");
// 	else if (signal == SIGQUIT)
// 		i++;
// }

// void	signals(void)
// {
// 	struct sigaction sa;

// 	sa.sa_sigaction = handler;
// 	sigaction(SIGINT, &sa, NULL);
// }