/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:16:18 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/05/01 19:47:12 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct a_cmds
{
	char	**cmd1;
	char	**cmd2;
	char	**envp;
	char	*path1;
	char	*path2;
}	t_cmds;

void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		word_count(char const *s, char c);
char	cmds_init(t_cmds *cmds, char **av);
void	free_split(char **w);

#endif
