#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char *rest;
	char buf[BUFF_SIZE + 1];
	char *str;
	int ret;

	str = ft_strnew(0);
	if(rest)
		str = ft_strdup(rest);
	while((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		str = ft_strjoin(str, ft_strdup(buf));
		if((rest = ft_strchr(ft_strdup(buf), '\n'))) 
			break;
	}
	ft_split_line(str, line);
	return (ret);
}

void	ft_split_line(char *str, char **line)
{
	int i;
	char *str2;

	str2 = ft_strnew(0);
	i = -1;
	while(str[++i])
	{
		if(str[i] == '\n')
		{
			str2[i] = 0;
			break;
		}
		str2[i] = str[i];
	}
	*line = str2;
}

int 	main(int ac, char **av)
{
	char *line;
	int ret;
	int fd;
	int count;

	fd = open("test", O_RDONLY);
	if(fd > 2)
	{
		count = 0;
		line = NULL;
		while((ret = get_next_line(fd, &line)) > 0)
		{
			count++;
			printf("%s", line);
			if (count > 50)
				break;
		}
		close(fd);
		printf("\n%d\n", count);
	}
	return (0);
}
