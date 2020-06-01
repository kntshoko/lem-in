#include "lemin.h"

int	ft_cmp(const char *s1, const char *s2)
{
	size_t l;

	l = 0;
	while (s1[l] && (unsigned char)s1[l] == (unsigned char)s2[l])
		l++;
	if ((unsigned char)s1[l] > (unsigned char)s2[l])
		return (-1);
	else if ((unsigned char)s1[l] < (unsigned char)s2[l])
		return (1);
	return (0);
}



int main()
{
	char **con;
//	char paths[100][100];
	char start[100]= "0";
/*	char room0[100][100];
	char room2[100][100];
	char room3[100][100];
	char room4[100][100];
	char room1[100][100];*/
	con[0] = "0-2";
	con[1] = "2-3";
	con[2] = "0-4";
	con[3] = "3-1";
	con[4] = "4-1";
	con[5] = NULL;
	int i = 0;
	int j = 0;
	char **sp;
	int x;
	printf("check == %d\n", i);
	while(con[i] != NULL)
	{
		sp = ft_strsplit(con[i], '-');
		x = 0;
		while(sp[x] != NULL)
		{
			if(ft_strchr("000", '0') == 0)
				j++;
		
			printf("i == %d  x == %d str == %s\n",i,x, sp[x]);
			x++;
		}
		i++;
	}
	printf("conn == %d\n", i);
	printf("start == %d\n", j);
	return(0);
}
