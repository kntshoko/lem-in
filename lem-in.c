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

char *end(char **str)
{
 char *start;
 char *end;
 char *point;
 int i; 
 int c;

 i = 0;
   start = ft_strnew(0);
   end = ft_strnew(0);
 while(str[i] != NULL)
 {
   c = 0;
   if (ft_strstr(str[i],"##start") != NULL)
   {
     ft_strdel(&start);
     while (str[i + 1][c] != ' ' && str[i + 1][c] != '\0')
     c++;
     start = ft_strsub(str[i + 1], 0, c);
   }
   else if (ft_strstr(str[i],"##end") != NULL)
   {
     ft_strdel(&end);
     while (str[i + 1][c] != ' ' && str[i + 1][c] != '\0')
     c++;
     end = ft_strsub(str[i + 1], 0, c);
   }
  i++;
 }
 point = ft_joint(start,"|",end);
   ft_strdel(&start);
   ft_strdel(&end);
 return (point);
}

char *conn(char **str)
{
  char *con;
  char *temp;
  char *s;
  int i;

  i = 0;  
  con = ft_strnew(0);
 ft_putendl("******************");
  while(str[i] != NULL)
  {
	
   s = ft_strstr(str[i], "-");
   if (s != NULL)
   {
    temp = ft_joint(con, " ; ", str[i]);
    ft_strdel(&con);
    con = ft_strdup(temp);
    ft_strdel(&temp);    
   }
    i++;
  }
 ft_putendl("******************");
 return(con);
}

int main (void){
 char *s = rd();
 char **str = ft_strsplit(s, '\n');
 char *rooms = room(str);
 char *points = end(str);
 char *connections = conn(str);
 ft_putendl(rooms);
 ft_putendl(points);
 ft_putendl(connections);
 return (0);
}
