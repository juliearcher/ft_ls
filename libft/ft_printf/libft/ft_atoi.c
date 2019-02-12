/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 15:40:09 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 09:41:53 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					i;
	int					neg;
	unsigned int		val;

	i = 0;
	val = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == ' ')
		i = i + 1;
	if (str[i] == '-')
	{
		neg = -1;
		i = i + 1;
	}
	else if (str[i] == '+')
		i = i + 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val * 10 + str[i] - '0';
		i = i + 1;
	}
	return (val * neg);
}
