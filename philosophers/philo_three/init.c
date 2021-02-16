/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:51:02 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:40:01 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_philo(t_philo *philo, t_data *data)
{
	philo->time_die = data->time_die;
	philo->time_eat = data->time_eat;
	philo->time_sleep = data->time_sleep;
	philo->num_eat = data->num_eat;
	philo->death_flag = &data->death_flag;
	philo->start = ft_gettime();
	philo->last_eat = 0;
	philo->forks = data->forks;
	philo->output = data->output;
	philo->waiter = data->waiter;
	philo->death = data->death;
}

void		end_simulation(t_philo *philo, int type)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
	sem_post(philo->waiter);
	if (type == DEATH)
		sem_post(philo->death);
	exit(1);
}

int			start_simulation(t_data *data)
{
	t_philo *philo;
	int		i;
	int		ret;

	if (!(philo = (t_philo*)malloc(sizeof(t_philo))))
		return (ft_errors(ALLER));
	i = -1;
	sem_wait(data->death);
	while (++i < data->philo)
	{
		philo->name = i + 1;
		fill_philo(philo, data);
		if ((data->pids[i] = fork()) == 0)
			simulation(philo);
		if (data->pids[i] == -1)
			return (ft_errors(FORKE));
	}
	i = -1;
	while (++i < data->philo)
		waitpid(data->pids[i], &ret, 0);
	return (0);
}
