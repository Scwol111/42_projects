/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:46:22 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/25 15:41:09 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		validate(t_data *data)
{
	if (data->philo < 2 || data->num_eat == 0 || data->time_die <= 0)
		return (ft_errors(ARGVE));
	if (data->time_eat <= 0 || data->time_sleep <= 0)
		return (ft_errors(ARGVE));
	return (0);
}

static int		init_sem(t_data *data)
{
	int x;

	x = data->philo;
	sem_unlink("forks");
	sem_unlink("output");
	sem_unlink("waiter");
	if (!(data->forks = sem_open("forks", O_CREAT | O_EXCL, S_IRWXU, x)))
		return (ft_errors(INITE));
	if (!(data->output = sem_open("output", O_CREAT | O_EXCL, S_IRWXU, 1)))
		return (ft_errors(INITE));
	if (!(data->waiter = sem_open("waiter", O_CREAT | O_EXCL, S_IRWXU, 1)))
		return (ft_errors(INITE));
	return (0);
}

static t_data	*init(int argc, char **argv)
{
	t_data *data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (ft_errors_null(ALLER));
	data->philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->num_eat = -1;
	data->death_flag = 0;
	if (argc == 6)
		data->num_eat = ft_atoi(argv[5]);
	if (validate(data) || init_sem(data) || !(data->threads =
	(pthread_t*)malloc(sizeof(pthread_t) * (data->philo + 1))))
	{
		free(data);
		return (ft_errors_null(STERR));
	}
	return (data);
}

static int		clear_data(t_data *data)
{
	if (sem_close(data->output) != 0)
		return (ft_errors(DESTE));
	if (sem_close(data->forks) != 0)
		return (ft_errors(DESTE));
	if (sem_close(data->waiter) != 0)
		return (ft_errors(DESTE));
	sem_unlink("waiter");
	sem_unlink("output");
	sem_unlink("forks");
	free(data->threads);
	free(data);
	return (0);
}

int				main(int argc, char **argv)
{
	t_data *data;

	if ((argc == 5 || argc == 6))
	{
		if ((data = init(argc, argv)))
		{
			start_simulation(data);
			clear_data(data);
		}
	}
	else
		return (ft_errors(NARGE));
	return (0);
}
