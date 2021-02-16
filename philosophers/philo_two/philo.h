/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:46:14 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:45:44 by tclaudin         ###   ########.fr       */
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

# define EAT 1
# define SLEEP 2
# define THINK 3
# define FORK 4

# define ARGVE "Error: bad arguments\n"
# define NARGE "Error: bad number of arguments\n"
# define INITE "Error: semaphore initialisation error\n"
# define DESTE "Error: semaphore destruction error\n"
# define ALLER "Error: memory allocation error\n"
# define STERR "Error: simulation initialisation failed\n"
# define THRDE "Error: thread initialisation failed\n"

typedef struct timeval	t_times;

typedef struct	s_data
{
	int			philo;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			num_eat;
	int			death_flag;
	pthread_t	*threads;
	sem_t		*forks;
	sem_t		*output;
	sem_t		*waiter;
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
}				t_philo;

int				ft_atoi(const char *string);
int				ft_errors(char *line);
int				start_simulation(t_data *data);

size_t			ft_strlen(const char *string);
size_t			ft_gettime(void);

void			*ft_errors_null(char *line);
void			*simulation(void *param);
void			ft_sleep(int usec);

#endif
