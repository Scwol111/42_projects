/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:29:34 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:44:25 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		take_fork(t_mutex *fork, t_mutex *output, t_philo *philo)
{
	size_t now;

	pthread_mutex_lock(fork);
	if (!*philo->death_flag)
		pthread_mutex_lock(output);
	else
		return ;
	now = ft_gettime() - philo->start;
	printf("%zu %d has taken a fork\n", now, philo->name);
	pthread_mutex_unlock(output);
}

static int		try_not_to_die(t_philo *philo, int type)
{
	size_t now;

	now = ft_gettime() - philo->start;
	if (type == EAT)
		philo->last_eat = now;
	if (*philo->death_flag)
		return (1);
	else
	{
		pthread_mutex_lock(philo->output);
		if (type == EAT)
			printf("%zu %d is eating\n", now, philo->name);
		if (type == SLEEP)
			printf("%zu %d is sleeping\n", now, philo->name);
		if (type == THINK)
			printf("%zu %d is thinking\n", now, philo->name);
		pthread_mutex_unlock(philo->output);
	}
	return (0);
}

static void		*supervisor(void *param)
{
	t_philo *philo;
	size_t	now;

	philo = (t_philo*)param;
	while (1)
	{
		if (!*philo->death_flag)
		{
			if (philo->num_eat == 0)
				return (NULL);
			now = ft_gettime() - philo->start;
			if (now - philo->last_eat > philo->time_die)
			{
				*philo->death_flag = 1;
				pthread_mutex_lock(philo->output);
				printf("%zu %d died\n", now, philo->name);
				pthread_mutex_unlock(philo->death);
				return (NULL);
			}
		}
		else
			return (NULL);
		usleep(50);
	}
	return (NULL);
}

static void		forking(t_philo *philo)
{
	if ((philo->name & 0x1) == 1)
	{
		take_fork(philo->left, philo->output, philo);
		take_fork(philo->right, philo->output, philo);
	}
	else
	{
		take_fork(philo->right, philo->output, philo);
		take_fork(philo->left, philo->output, philo);
	}
}

void			*simulation(void *param)
{
	t_philo		*philo;
	pthread_t	th;

	philo = (t_philo*)param;
	if (pthread_create(&th, NULL, supervisor, philo) != 0)
		return (ft_errors_null(THRDE));
	while (philo->num_eat != 0 && !*philo->death_flag)
	{
		forking(philo);
		if (*philo->death_flag)
			return (end_simulation(philo));
		if (try_not_to_die(philo, EAT))
			return (end_simulation(philo));
		ft_sleep(philo->time_eat);
		philo->num_eat--;
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		if (try_not_to_die(philo, SLEEP))
			return (end_simulation(philo));
		ft_sleep(philo->time_sleep);
		if (try_not_to_die(philo, THINK))
			return (end_simulation(philo));
	}
	return (NULL);
}
