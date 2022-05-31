/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:42:39 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/30 16:42:40 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../ms_head.h"

void	cd_path(t_env *env, t_arg *arg)
{
	t_env	*lst;
	char	*OLDPWD;
	char	*newdir;
	
	lst = env;
	if (arg->str[0] != '/' && arg->str[0] != '.')
	{
		newdir = ft_strjoin(pwd(env), "/");
		newdir = ft_strjoin(newdir, arg->str);
	}
	else if  (arg->str[0] == '/')
		newdir = arg->str;
	else if (arg->str[0] == '.' && arg->str[1] == '/' && arg->str[2] != '\0')
		newdir = ft_strjoin(pwd(env), ft_substr(arg->str, 1, ft_strlen(arg->str) - 1));
	if (chdir(newdir))
	{
		printf("commad not found\n");
		exit(0);
		return ;
	}
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			if (lst->value)
				OLDPWD = lst->value;
			lst->value = newdir;
			break ;
		}
		lst = lst->next;
	}
	if (!pwd(env))
	{
		printf("commad not found\n");
		exit(0);
	}
	lst = env;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "OLDPWD"))
		{
			lst->value = OLDPWD;
			return ;
		}
		lst = lst->next;
	}
}