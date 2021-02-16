/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:17:56 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:46:18 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		sem_wait(philo->output);
		if (type == EAT)
			printf("%zu %d is eating\n", now, philo->name);
		if (type == SLEEP)
			printf("%zu %d is sleeping\n", now, philo->name);
		if (type == THINK)
			printf("%zu %d is thinking\n", now, philo->name);
		if (type == FORK)
			printf("%zu %d has taken a fork\n", now, philo->name);
		sem_post(philo->output);
	}
	return (0);
}

static void		*end_simulation(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
	sem_post(philo->waiter);
	return (NULL);
}

static void		*supervisor(void *param)
{
	t_philo *philo;
	size_t	now;

	philo = (t_philo*)param;
	while (1)
	{
		if (*philo->death_flag == 0)
		{
			if (philo->num_eat == 0)
				return (NULL);
			now = ft_gettime() - philo->start;
			if (now - philo->last_eat > philo->time_die)
			{
				*philo->death_flag = 1;
				sem_wait(philo->output);
				printf("%zu %d died\n", now, philo->name);
				return (end_simulation(philo));
			}
			usleep(100);
		}
	}
	return (NULL);
}

static int		take_forks(t_philo *philo)
{
	sem_wait(philo->waiter);
	sem_wait(philo->forks);
	if (try_not_to_die(philo, FORK))
		return (1);
	sem_wait(philo->forks);
	if (try_not_to_die(philo, FORK))
		return (1);
	sem_post(philo->waiter);
	return (0);
}

void			*simulation(void *param)
{
	t_philo		*philo;
	pthread_t	th;

	philo = (t_philo*)param;
	if (pthread_create(&th, NULL, supervisor, philo) != 0)
		return (ft_errors_null(THRDE));
	while (philo->num_eat-- != 0)
	{
		if (take_forks(philo))
			return (end_simulation(philo));
		if (try_not_to_die(philo, EAT))
			return (end_simulation(philo));
		ft_sleep(philo->time_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		if (try_not_to_die(philo, SLEEP))
			return (end_simulation(philo));
		ft_sleep(philo->time_sleep);
		if (try_not_to_die(philo, THINK))
			return (end_simulation(philo));
	}
	return (NULL);
}
