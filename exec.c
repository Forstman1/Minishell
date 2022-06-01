/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:        <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:                     by                   #+#    #+#             */
/*   Updated:                     by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_head.h"


void	create_env(t_env **env, char **envirement, int i)
{
	t_env	*lst;
	int		j;
	char	*key;
	char	*value;

	j = 0;
	if (i == 0)
	{
		printf("env not set\n");
		exit(0);
	}
	while (i > 0)
	{
		value = ft_strdup(ft_strchr(envirement[j], '=') + 1);
		key = ft_strdup(get_keys(envirement[j], '='));
		lst = ft_lstnew1(key, value);
		ft_lstadd_back1(env, lst);
		j++;
		i--;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_env	*envi;
	t_arg	arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	create_env(&envi, env, i);
	arg.str = av[1];
	pipes(envi, &arg);

	//cd_env(envi, &arg);
	// unset_env(&envi, av[1]);
	// export_env(&envi, av[1]);
	// exit1();
	
	// while (envi)
	// {
	// 	printf("%s=%s\n", envi->key ,envi->value);
	// 	envi = envi->next;
	// }

	return (0);
}