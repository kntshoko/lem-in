#include "lemin.h"

static	size_t	ft_wordc(char const *s, int c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			l++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (l);
}


char *rd(void)
{
 char *line;
 char *str;
 char *temp;

 str = ft_strnew(0);
 while(get_next_line(0,&line) > 0)
 {
   temp = ft_strdup(str);
   ft_strdel(&str);
   str = ft_joint(temp,"\n",line);
   ft_strdel(&temp);
 }
 return (str);
}

char *room(char **str)
{
 char *rooms;
 char *temp;
 char *temp2;
 int i;
 int j;
 int c;

 i = 0;
 rooms = ft_strnew(0);
 while (str[i] != NULL)
 {
  if (ft_wordc(str[i],' ') == 3)
  {
   j = 0;
   c = 0;
   while (str[i][c] != ' ')
    c++;
   temp = ft_strdup(rooms);
   ft_strdel(&rooms);
   temp2 = ft_strsub(str[i],0,c);
   rooms = ft_joint(temp," ",temp2);
   ft_strdel(&temp);
   ft_strdel(&temp2);
  }
  i++;
 } 
 return(rooms);
}

int main (void){
 char *s = rd();
 char **str = ft_strsplit(s, '\n');
 char *rooms = room(str);
 char *points = ends(str);
 ft_putendl(rooms);
 ft_putendl(points);
 return (0);
}
