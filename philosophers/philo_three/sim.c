/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:17:01 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:31:15 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	try_not_to_die(t_philo *philo, int type)
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

static int	take_forks(t_philo *philo)
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

static void	*death_watch(void *param)
{
	t_philo	*philo;

	philo = (t_philo*)param;
	sem_wait(philo->death);
	end_simulation(philo, DEATH);
	return (NULL);
}

static void	*supervisor(void *param)
{
	size_t	now;
	t_philo	*philo;

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
				sem_post(philo->death);
				end_simulation(philo, LIVE);
			}
			usleep(100);
		}
		else
			end_simulation(philo, LIVE);
	}
	return (NULL);
}

int			simulation(t_philo *philo)
{
	pthread_t su;
	pthread_t de;

	if (pthread_create(&su, NULL, supervisor, philo) != 0)
		return (ft_errors(THRDE));
	if (pthread_create(&de, NULL, death_watch, philo) != 0)
		return (ft_errors(THRDE));
	while (philo->num_eat-- != 0)
	{
		if (take_forks(philo))
			end_simulation(philo, LIVE);
		if (try_not_to_die(philo, EAT))
			end_simulation(philo, LIVE);
		ft_sleep(philo->time_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		if (try_not_to_die(philo, SLEEP))
			end_simulation(philo, LIVE);
		ft_sleep(philo->time_sleep);
		if (try_not_to_die(philo, THINK))
			end_simulation(philo, LIVE);
	}
	exit(0);
	return (0);
}
