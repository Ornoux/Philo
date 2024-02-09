/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:10:04 by npatron           #+#    #+#             */
/*   Updated: 2024/02/09 21:44:23 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_init(&data->philo[i].fork, NULL);
	return ;
}

void    init_struct(t_data *data)
{
	int	i;
	
	i = 0;
	init_mutexes(data);
	while (i < data->nbr_philo)
	{
		data->philo[i].id = i;
		data->philo[i].eat = 0;
		data->philo[i].sleep = 0;
		data->philo[i].dead = false;
		data->philo[i].nb_fork = 0;
		data->philo[i].data = data;
		i++;
	}
	return ;
}

void start(t_data *data)
{
	int	i;

	i = 0;
	init_struct(data);
	while (i < data->nbr_philo)
	{
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		//ft_usleep(1500);
		i++;
	}
	return ;
}