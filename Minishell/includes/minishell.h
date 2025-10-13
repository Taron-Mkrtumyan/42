/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkankia <gkankia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:56:22 by gkankia           #+#    #+#             */
/*   Updated: 2025/10/03 17:30:23 by gkankia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/wait.h>
# include <limits.h>
# include <linux/limits.h>
# include "libft.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>

# define RESET      "\001\033[0m\002"
# define RED  "\001\033[1;31m\002"
# define CYAN   "\001\033[1;36m\002"

extern volatile sig_atomic_t g_received_signal;

typedef struct s_subprocess_data
{
	int		pipe_fd[2];
	int		has_pipe;
	char	**cmd;
	int		redir_error;
}	t_subprocess_data;

typedef struct s_minishell
{
	char				*line;
	char				**args;
	char				**envp;
	char				*path;
	char				*oldpwd;
	int					in_fd;
	int					out_fd;
	int					is_running;
	int					exit_code;
	int					is_two_operator;
	int					data_is_init;
	pid_t				last_pid;
	t_subprocess_data	*data;
}	t_minishell;

typedef struct s_builtin_exec
{
	t_minishell	*sh;
	int			start;
	int			end;
	int			saved_stdin;
	int			saved_stdout;
	char		**cmd_argv;
}	t_builtin_exec;

void	init_shell(t_minishell *sh);
int		init_env(t_minishell *sh, char **envp);
void	setup_signals(void);
void	check_signal(t_minishell *sh);
void	execute_command(t_minishell *sh);
void	free_minishell(t_minishell *sh);
int	here_doc(char *delimiter, t_minishell *sh);
int		has_pipe(char **args);
int		execute_builtin(t_minishell *sh);
void	handle_child_fds(t_minishell *sh, int pipe_fd[2], int has_pipe);
void	handle_parent_fds(t_minishell *sh, int pipe_fd[2],\
	int has_pipe, int *prev_fd);

char	**build_argv(char **args, int start, int end);
int		handle_redirections(t_minishell *sh, int start, int end);
void	child_process(t_minishell *sh, t_subprocess_data *data,\
	int start);
void	exec_subcmd(t_minishell *sh, int start, int end, int *prev_fd);

char	**parse_input(t_minishell *sh);
int		append_arg(char **args, int *k, t_minishell *sh, int *i);
char	*copy_quoted_arg(t_minishell *sh, int *i);
char	*copy_unquoted_arg(t_minishell *sh, int *i);
char	*copy_double_quoted(t_minishell *sh, int *i, int end);
char	*copy_double_quoted_part(t_minishell *sh, int *i,\
	int end, char *result);
char	*parse_dollar(t_minishell *sh, int *i);
char	*copy_single_quoted(char *line, int *i, int end);
char	*copy_segment(char *line, int start, int end);
int		skip_spaces(char *line, int i);
int		find_closing_quote(char *line, int i, char quote);
int		is_quote(char c);
int		is_special(char c);
void	free_all(char **args, int count);
char	*str_join_free(char *s1, char *s2);
char	*get_env_value(char **envp, char *name);
int		check_infiles(char **args, t_minishell *sh);

void	free_args(char **args);
char	*get_prompt(t_minishell *sh);
char	*find_in_path(t_minishell *sh, char *cmd);
char	*join_path(char *dir, char *cmd);
int		exit_with_error(t_minishell *sh, char *msg, int status, int num);

int		change_directory(t_minishell *sh);
int		builtin_exit(t_minishell *sh);
int		builtin_env(t_minishell *sh);
int		builtin_export(t_minishell *sh);
int		builtin_unset(t_minishell *sh);

int		set_env_value(char ***envp, const char *key, const char *value);
char	*copy_escaped_char(char *line, int *i);
char	*append_segment(t_minishell *sh, int *i, int end, char *result);
char	*handle_backslash_dquote(t_minishell *sh, int *i, int end,\
	char *result);
char	*handle_dollar_dquote(t_minishell *sh, int *i, char *result);
char	*process_dollar(t_minishell *sh, int *i, char *result);

int		is_builtin_cmd(char *cmd);
void	execute_builtin_in_parent(t_minishell *sh, int start, int end);
char	**add_env_entry(char **envp, char *new_entry);
int		print_working_directory(t_minishell *sh);
int		builtin_echo(t_minishell *sh);
void	update_fds(t_minishell *sh, int *prev_fd);
int		is_redirections(t_minishell *sh, int i);
int		check_no_command_redirection(t_minishell *sh, int i);
void	free_array(char **arr);
void	validate_exec_args(t_minishell *sh, char *path, int start,\
	t_subprocess_data *data);
void	free_temp_data(t_minishell *sh);
short	check_double_op(char **args);
short	is_redirection(char *s);
void	heredoc_sigint(int sig);
char	valid_operators(t_minishell *sh);
int		prepare_subcmd(t_minishell *sh, t_subprocess_data *data,\
	int start, int end);
pid_t	fork_and_exec_child(t_minishell *sh,\
		t_subprocess_data *data, int start);
int		process_redirection(t_minishell *sh, char *redir, char *file);
#endif
