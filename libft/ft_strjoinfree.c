#include "libft.h"

char    *ft_strjoinfree(char *s1, char *s2)
{
	int	i;
	int	j;
	char    *str;

	if (!(s1) || !(s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = 0;
	free(s1);
	free(s2);
	return (str);
}
