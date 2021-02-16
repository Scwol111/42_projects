/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:35:25 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:43:05 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fill_philo(t_philo *philo, t_data *data)
{
	philo->time_die = data->time_die;
	philo->time_eat = data->time_eat;
	philo->time_sleep = data->time_sleep;
	philo->num_eat = data->num_eat;
	philo->output = data->output;
	philo->death = data->death;
	philo->death_flag = &data->death_flag;
	philo->start = ft_gettime();
	philo->last_eat = 0;
}

void		*end_simulation(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	return (NULL);
}

int			start_simulation(t_data *data)
{
	t_philo *philo;
	int		i;

	if (!(philo = (t_philo*)malloc(sizeof(t_philo) * (data->philo))))
		return (ft_errors(ALLER));
	pthread_mutex_lock(data->death);
	i = -1;
	while (++i < data->philo)
	{
		philo[i].name = i + 1;
		fill_philo(&philo[i], data);
		philo[i].left = data->forks[i];
		if (i + 1 < data->philo)
			philo[i].right = data->forks[i + 1];
		else
			philo[i].right = data->forks[0];
		if (pthread_create(&data->threads[i], NULL, simulation, &philo[i]) != 0)
			return (ft_errors(THRDE));
	}
	i = -1;
	while (++i < data->philo)
		pthread_join(data->threads[i], NULL);
	free(philo);
	return (1);
}
