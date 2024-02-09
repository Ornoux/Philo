/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:27:10 by npatron           #+#    #+#             */
/*   Updated: 2024/02/09 21:38:54 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(char **tab, int a, t_data *data)
{
    if (a != 5 && a != 6)
        return (print_error(0));
    if (lil_atoi(tab[1]) == -1)
        return (print_error(1));
    if (lil_atoi(tab[2]) == -1)
        return (print_error(2));
    if (lil_atoi(tab[3]) == -1)
        return (print_error(3));
    if (lil_atoi(tab[4]) == -1)
        return (print_error(4));
    if (tab[5] && lil_atoi(tab[5]) == -1)
        return (print_error(5));
    else
    {
        data->nbr_philo = lil_atoi(tab[1]);
        data->tt_die = lil_atoi(tab[2]) * 1000;
        data->tt_eat = lil_atoi(tab[3]);
        data->tt_sleep = lil_atoi(tab[4]);
        data->nbr_meals = -1;
        data->start_simulation = get_current_time();
        //pthread_mutex_init(&data->print, NULL);
        if (tab[5])
            data->nbr_meals = lil_atoi(tab[5]);
    }
        return (0);
}
