/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmkrtumy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:38:12 by tmkrtumy          #+#    #+#             */
/*   Updated: 2025/07/07 16:49:28 by tmkrtumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILO_H
# define FILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <string.h>

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

typedef pthread_mutex_t	t_mtx;
typedef struct s_philo	t_philo;

typedef enum s_action
{
	JOIN,
	CREATE,
	DETACH,
	LOCK,
	UNLOCK,
	INIT,
	DESTROY
}	t_action;

typedef enum a_result
{
	UNKNOWN,
	SUCCESS,
	FAIL
}	t_result;

typedef struct a_fork
{
	t_mtx	fork;
	int		fid;
}	t_fork;

typedef struct s_data
{
	unsigned int	phil_num;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	unsigned int	no_spaghetti;
	long long		start_time;
	t_result		end;
	bool			all_threads_ready;
	t_mtx			data_mutex;
	t_mtx			write_mutex;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor_die;
	pthread_t		monitor_full;
	long long		threads_running_num;
}	t_data;

typedef struct s_philo
{
	pthread_t		tid;
	t_mtx			philo_mutex;
	t_fork			*second_fork;
	t_fork			*first_fork;
	t_data			*data;
	unsigned int	last_meal_time;
	int				id;
	unsigned int	meals_eaten;
}	t_philo;

typedef enum a_time_type
{
	SECOND,
	MILISECOND,
	MICROSECOND
}	t_time_type;

typedef enum a_status
{
	EATING,
	THINKING,
	SLEEPING,
	LOCK_FIRST,
	LOCK_SECOND,
	UNLOCK_FIRST,
	UNLOCK_SECOND,
	TOOK,
	DIED
}	t_philo_status;

bool			valid_args(int ac, char **av);
unsigned int	ft_atoi(const char *str);
void			clean_all(t_data *data);
void			simulate(t_data *data);
t_data			*data_init(t_data *data, char **av);
bool			mutex_op(t_mtx *mutex, t_action action);
void			set_bool(t_mtx *mutex, bool *dest, bool value);
bool			get_bool(t_mtx *mutex, bool *value);
unsigned int	get_uint(t_mtx *mutex, unsigned int *value);
void			set_uint(t_mtx *mutex, unsigned int *dest, unsigned int value);
t_result		get_res(t_data *data);
void			set_res(t_data *data, t_result value);
bool			sim_ended(t_data *data);
void			wait_all_threads(t_data *data);
long long		ft_get_time(t_time_type time_type);
void			ft_sleep(long long usec, t_data *data);
void			think(t_philo *philo, bool print);
void			write_status(t_philo_status state, t_philo *philo);
void			increase_ctr(t_mtx *mutex, long long *value);
void			de_synchro(t_philo *philo);
bool			all_threads_running(t_mtx *mutex, long long *threads,
					long long philo_nbr);
void			*monitor_dinner_die(void *info);
void			*monitor_dinner_full(void *info);
void			thread_op(pthread_t *thread, void *data, t_action action,
					void *(*function)(void *));

#endif
