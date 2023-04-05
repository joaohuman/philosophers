/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:14:55 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/05 02:06:34 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_how_use(void)
{
	printf("\nuse: ");
	printf("philo ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[times_each_philosopher_must_eat] \n\n");
	printf("  number_of_philosophers \t\t");
	printf("number of philosophers.\n");
	printf("  time_to_die \t\t\t\t");
	printf("time in milliseconds that a philosopher die of starve.\n");
	printf("  time_to_eat \t\t\t\t");
	printf("time in milliseconds it takes a philosopher to eat.\n");
	printf("  time_to_sleep \t\t\t");
	printf("time in milliseconds it takes a philosopher to sleep.\n");
	printf("  [times_each_philosopher_must_eat] \t");
	printf("number of times each philosopher must eat\n\n");
}

void	*test_philo(void *philo)
{
	t_philo *phi;

	phi = (t_philo *)philo;
	phi->param->how_much_eat++;
	return(NULL);
}

int	main(int argc, char **argv)
{
	t_param	p;
	int		i;
	
	i = 0;
	if (check_args(argc, argv))
		return (ERROR);
	init_param(&p, argc, argv);
	init_philo(&p);
	while (i < p.num_philo)
	{
		if(pthread_create(&p.philo[i].phi_thread, NULL, test_philo, &p.philo[i]))
			return(printf("Error creating thread"), ERROR);
		i++;
	}
	i = 0;
	while (i < p.num_philo)
	{
		pthread_join(p.philo[i].phi_thread, NULL);
		i++;
	}
	usleep(100000);
	long long teste = get_time() - p.init_time;
	printf("%lli\n", teste);
	free(p.philo);
	return (SUCCESS);
}
