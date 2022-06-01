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
	char	*value;
	char	*key;
	int		i;
	
	lst = env;
	i = 0;
	if (arg->str[0] != '/' && arg->str[0] != '.')
	{
		newdir = ft_strjoin(pwd(env), "/");
		newdir = ft_strjoin(newdir, arg->str);
	}
	else if  (arg->str[0] == '/')
		newdir = arg->str;
	else if (arg->str[0] == '.' && arg->str[1] == '/' && arg->str[2] != '\0')
		newdir = ft_strjoin(pwd(env), ft_substr(arg->str, 1, ft_strlen(arg->str) - 1));
	else if (arg->str[0] == '.' && arg->str[1] == '.' && arg->str[2] == '/' && arg->str[3] != '\0')
	{
		cd_back(env, arg);
		newdir = ft_strjoin(pwd(env), ft_substr(arg->str, 2, ft_strlen(arg->str) - 2));
		i = 1;
	}
	if (chdir(newdir))
	{
		printf("no sush file or directory %s\n", newdir);
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
	if (i == 1)
		return ;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "OLDPWD"))
		{
			lst->value = OLDPWD;
			return ;
		}
		lst = lst->next;
	}
	lst = NULL;
	value = ft_strdup(OLDPWD);
	key = ft_strdup("OLDPWD");
	lst = ft_lstnew1(key, value);
	ft_lstadd_back1(&env, lst);
}