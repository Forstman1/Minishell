/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:08:22 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 16:08:23 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ms_head.h"

void	check_path(t_env	*env, t_arg *arg)
{
	t_env	*lst;
	int		i;

	lst = env;
	i = 0;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PATH"))
		{
			if (lst->value)
			{
				arg->paths = ft_split(lst->value, ':');
				i = 1;
			}
			break ;
		}
		lst = lst->next;
	}
	if (i != 1)
	{
		printf("PATH not found\n");
		exit(0);
	}
}

int	check_cmd(t_env	*env, t_arg *arg, char *str)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	arg->i++;
	arg->cmd = ft_split(str, ' ');
	str = arg->cmd[0];
	while (arg->paths[i])
	{
		cmd_path = ft_strjoin(arg->paths[i], "/");
		tmp = cmd_path;
		cmd_path = ft_strjoin(cmd_path, str);
		free(tmp);
		if (!access(cmd_path, X_OK))
		{
			arg->cmd_path = cmd_path;
			return (1);
		}
		i++;
	}
	printf("Command not found\n");
	return (0);
}

void	builtins(t_env	*envi, char *str)
{
	char	**splited;

	splited = ft_split(str, ' ');
	if (!ft_strcmp1(splited[0], "pwd"))
		pwd(envi, 1);
	else if (!ft_strcmp(splited[0], "export"))
		export_env(&envi, splited[0], splited[1]);
	else if (!ft_strcmp(splited[0], "unset"))
		unset_env(&envi, splited[0], splited[1]);
	else if (!ft_strcmp1(splited[0], "env"))
		env(envi);
	else if (!ft_strcmp(splited[0], "exit"))
		exit10();
	else if (!ft_strcmp(splited[0], "cd"))
		cd_env(envi, splited[0], splited[1]);
}

int	check_builtins(t_env	*envi, char *str)
{
	char	**splited;
	int		id;

	splited = ft_split(str, ' ');
	if (!ft_strcmp1(splited[0], "pdw"))
		return (1);
	else if (!ft_strcmp(splited[0], "export"))
		return (1);
	else if (!ft_strcmp(splited[0], "unset"))
		return (1);
	else if (!ft_strcmp1(splited[0], "env"))
		return (1);
	else if (!ft_strcmp(splited[0], "exit"))
		return (1);
	else if (!ft_strcmp(splited[0], "cd"))
		return (1);
	return (0);
}