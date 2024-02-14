/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elon_musk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:45:46 by npatron           #+#    #+#             */
/*   Updated: 2024/02/14 18:30:47 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->deadlock);
	if (philo->data->dead == true)
		return (pthread_mutex_lock(&philo->data->deadlock), 1);
	pthread_mutex_unlock(&philo->data->deadlock);
	return (0);
}

int	condition_life(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->deadlock);
	if ((get_current_time() - philo->last_meal) >= (philo->data->tt_die) && philo->eat == 0)
	{
		philo->data->dead = true;
		pthread_mutex_unlock(&philo->data->deadlock);
		msg(philo, "dead");
		return (1);
	}
	pthread_mutex_unlock(&philo->data->deadlock);
	return (0);
}

int		check_all_feed(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->meal);
	if (philo->data->nbr_meals == -1)
	{
		pthread_mutex_unlock(&philo->data->meal);
		return (1);
	}
	while (i < philo->data->nbr_philo)
	{
		if (philo[i].meals < philo->data->nbr_meals)
		{
			pthread_mutex_unlock(&philo->data->meal);
			philo->data->dead = true;
			return (1);
		}
		else
			i++;
	}
	pthread_mutex_unlock(&philo->data->meal);
	return (0);
}

void	*meeting_security(void *ptr)
{
	int		i;
	t_philo *philo;
	
	philo = (t_philo *)ptr;
	while (1)
	{
		if (i == philo->data->nbr_philo)
			i = 0;
		condition_life(&philo[i]);
		if (dead_loop(philo) == 1) //|| check_all_feed(philo) == 0)
		{
			destroy_prog(philo);
			break;
		}
		i++;
	}
	return (ptr);
}

void	destroy_prog(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
		pthread_mutex_unlock(philo[i].r_fork);
		i++;
	}
}


