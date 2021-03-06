/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:08:22 by sahafid           #+#    #+#             */
/*   Updated: 2022/05/29 16:08:23 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../ms_head.h"


void	execute_func(t_env	*env, t_arg *arg, int j)
{
	int i;

	i = fork();
	if (i == 0)
	{
		if (j == 1)
		{
			dup2(arg->fd[1], 1);
			dup2(arg->in_fd, 0);
			close(arg->fd[1]);
		}
		else
		{
			dup2(arg->in_fd, 0);
			// close(arg->fd[1]);
		}
		execve(arg->cmd_path, arg->cmd, arg->paths);
	}
	waitpid(i, &status.exit_status, 0);
	if (status.exit_status != 0)
		status.exit_status = 1;
}

int	one_cmd(t_env	*env, t_arg *arg)
{
	int i;

	i = 0;
	while (arg->args[i])
		i++;
	if (i == 1)
	{
		i = 0;
		if (check_builtins(env, arg->args[i]))
		{
			builtins(env, arg->args[i], arg);
			return (1);
		}
	}
	else if (i == 0)
		return (1);
	return (0);
}

void	ft_dup(t_arg *arg, int j)
{
	if (j == 1)
	{
		dup2(arg->fd[1], 1);
		dup2(arg->in_fd, 0);
		close(arg->fd[1]);
		close(arg->fd[0]);
	}
	else
	{
		close(arg->fd[1]);
		close(arg->fd[0]);
		dup2(arg->in_fd, 0);
	}
}

void	check_redirection(t_arg *arg)
{
	char **splited;

	splited = NULL;
	if (arg->args[0][0] == '<')
	{
		splited = ft_split(arg->args[0], ' ');
		if (!access(arg->args[1], X_OK))
			return ;
		arg->in_fd = open(arg->args[1], O_RDWR);
	}
}

void	her_doc(t_token *token, t_arg *arg)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = NULL;
	tmp = NULL;
	// while (true)
	// {
	// 	str = readline("");
	// 	if (!ft_strcmp(str, token->content))
	// 	{
	// 		return ;
	// 	}
	// 	else
	// 	{
	// 		ft_putstr_fd(str, arg->in_fd);
	// 		free(str);
	// 		str = NULL;
	// 	}
	// }
}

void	redirection(t_arg *arg, int i)
{
	char	**splited;

	splited = ft_split(arg->args[i], ' ');
	if (splitd[0][0] == '<')
	{
		arg->in_fd = open(splited[1], );
	}
}

void	check_command(t_env	*env, t_arg *arg)
{
	t_env	*lst;
	int		i;
	int		id;
	int		j;

	lst = env;
	i = 0;
	id = 0;
	j = 0;
	check_path(env, arg);
	if (one_cmd(env, arg))
		return ;
	i = 0;
	// check_redirection(arg);
	while (arg->args[i])
	{
		pipe(arg->fd);
		if (check_builtins(env, arg->args[i]))
		{
			id = fork();
			if (id == 0)
			{
				if (arg->args[i + 1] != NULL)
					ft_dup(arg, 1);
				else
					ft_dup(arg, 0);
				builtins(env, arg->args[i], arg);
				close(arg->fd[1]);
				exit(0);
			}
			i++;
		}
		else if (arg->args[i][0] == '<' || arg->args[i][0] == '>')
			redirection(arg, i);
		else
		{
			j = check_cmd(env, arg, arg->args[i]);
			if (j == 1)
			{
				if (arg->args[i + 1] != NULL)
					execute_func(env, arg, 1);
				else
					execute_func(env, arg, 0);
				i++;
			}
			else
				return ;
		}
		arg->in_fd = arg->fd[0];
		close(arg->fd[1]);
	}
	close(arg->in_fd);
	close(arg->fd[0]);
}
