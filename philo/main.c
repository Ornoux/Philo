/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:10:07 by npatron           #+#    #+#             */
/*   Updated: 2024/02/16 20:58:11 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		perror("Error, memory.\n");
	philo = NULL;
	if (!check_args(argv, argc, data))
	{
		data->philo = malloc(sizeof(t_philo) * data->nbr_philo);
		start(data);
		free(data->forks);
		free(data->philo);
		free(data);
		free(philo);
	}
	(void)philo;
	return (0);
}
