/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:46:14 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:31:47 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define FORK 4
# define DEATH 1
# define LIVE 0

# define ARGVE "Error: bad arguments\n"
# define NARGE "Error: bad number of arguments\n"
# define INITE "Error: semaphore initialisation error\n"
# define DESTE "Error: semaphore destruction error\n"
# define ALLER "Error: memory allocation error\n"
# define STERR "Error: simulation initialisation failed\n"
# define THRDE "Error: thread creation failed\n"
# define FORKE "Error: process creation failed\n"

typedef struct timeval	t_times;

typedef struct	s_data
{
	int		philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_eat;
	int		death_flag;
	pid_t	*pids;
	sem_t	*forks;
	sem_t	*output;
	sem_t	*waiter;
	sem_t	*death;
}				t_data;

typedef struct	s_philo
{
	int		*death_flag;
	int		name;
	int		num_eat;
	size_t	time_die;
	size_t	time_eat;
	size_t	time_sleep;
	size_t	start;
	size_t	last_eat;
	sem_t	*forks;
	sem_t	*output;
	sem_t	*waiter;
	sem_t	*death;
}				t_philo;

int				ft_atoi(const char *string);
int				ft_errors(char *line);
int				start_simulation(t_data *data);

size_t			ft_strlen(const char *string);
size_t			ft_gettime(void);

void			*ft_errors_null(char *line);
void			ft_sleep(int usec);
int				simulation(t_philo *philo);
void			end_simulation(t_philo *philo, int type);

#endif
