/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:37 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 16:07:38 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../ms_head.h"


void	cd_env(t_env *env, t_arg *arg)
{
	int	i;

	i = 0;
	if (!ft_strcmp(arg->str, NULL))
		cd_home(env, arg);
	else if (!ft_strcmp(arg->str, ".."))
		cd_back(env, arg);
	else if (!ft_strcmp(arg->str, "."))
		i++;
	else if (!ft_strcmp(arg->str, "-"))
		cd_dash(env, arg);
	else if (!ft_strcmp(arg->str, "/"))
		cd_root(env, arg);
	else if (!ft_strcmp(arg->str, "./"))
		cd_samdir(env, arg);
	else
		cd_path(env, arg);
}