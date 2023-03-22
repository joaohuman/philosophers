/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 02:14:55 by jvictor-          #+#    #+#             */
/*   Updated: 2023/03/22 23:53:43 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (printf("ArgCounter diferente de 5 e 6\n"), 1);
	return (0);
}
