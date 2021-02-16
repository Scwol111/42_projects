/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:41:56 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 18:45:48 by tclaudin         ###   ########.fr       */
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
	philo->death_flag = &data->death_flag;
	philo->start = ft_gettime();
	philo->last_eat = 0;
	philo->forks = data->forks;
	philo->waiter = data->waiter;
}

int			start_simulation(t_data *data)
{
	t_philo	*philo;
	int		i;

	if (!(philo = (t_philo*)malloc(sizeof(t_philo) * (data->philo))))
		return (ft_errors(ALLER));
	i = -1;
	while (++i < data->philo)
	{
		philo[i].name = i + 1;
		fill_philo(&philo[i], data);
		if (pthread_create(&data->threads[i], NULL, simulation, &philo[i]) != 0)
			return (ft_errors(THRDE));
	}
	i = -1;
	while (++i < data->philo)
		pthread_join(data->threads[i], NULL);
	free(philo);
	return (0);
}
