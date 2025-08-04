/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:42:04 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/30 14:28:48 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

//includes

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define RE		"\033[0m"
# define R		"\033[31m"
# define G		"\033[32m"
# define Y		"\033[33m"
# define B		"\033[34m"
# define M		"\033[35m"
# define C		"\033[36m"
# define W		"\033[37m"

# define BOLD	"\033[1;30m"
# define BR		"\033[1;31m"
# define BG		"\033[1;32m"
# define BY		"\033[1;33m"
# define BB		"\033[1;34m"
# define BM		"\033[1;35m"
# define BC		"\033[1;36m"
# define BW		"\033[1;37m"

typedef struct s_token
{
	char			*str;
	char			*str_backup;
	bool			var_exists;
	int				type;
	int				status;
	bool			join;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;
typedef struct s_io_fds
{
	char	*infile;
	char	*outfile;
	char	*heredoc_delimiter;
	bool	heredoc_quotes;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
}	t_io_fds;
typedef struct s_command
{
	char				*command;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_io_fds			*io_fds;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;
typedef struct a_data
{
	bool		interactive;
	t_token		*token;
	char		*user_input;
	char		**env;
	char		*working_dir;
	char		*old_working_dir;
	t_command	*cmd;
	pid_t		pid;
}	t_data;

//functions

bool	data_init(t_data *data, int ac, char **av, char **env);
void	clean_all(t_data *data);
void	ft_exit(char *message);

#endif
