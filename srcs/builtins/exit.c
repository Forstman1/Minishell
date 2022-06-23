/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:08:04 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 14:08:05 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ms_head.h"

void	exit10(void)
{
	printf("exit\n");
	status.exit_status = 0;
	exit(0);
}

void	exit11(int	i)
{
	if (ft_isdigit(i))
	{
		printf("exit\n");
		status.exit_status = i;
		exit(i);
	}
	else {
		printf("exit\n");
		ft_putstr_fd("numeric argument required\n", 2);
		exit(0);
	}
}