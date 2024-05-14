/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouboul <ebouboul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:44:19 by ebouboul          #+#    #+#             */
/*   Updated: 2024/05/14 13:45:50 by ebouboul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while ((char)c != s[i])
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}
