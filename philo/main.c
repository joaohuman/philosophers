/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:14:55 by jvictor-          #+#    #+#             */
/*   Updated: 2023/04/17 02:07:49 by jvictor-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_param	p;

	if (check_args(argc, argv))
		return (ERROR);
	if (init_param(&p, argc, argv))
		return (printf("Error init_param"), ERROR);
	if (init_philo(&p))
		return (printf("Error init_philo"), ERROR);
	if (give_life_to_philo(&p))
		return (printf("Error give_life_to_philo"), ERROR);
	return (SUCCESS);
}
