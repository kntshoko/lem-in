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

typedef	struct	q_list
{
	struct	q_list	*next;
	char		*room;
	int		occupied;
	int		ant_count;
	char		*links[10000];
}		r_list;

void ft_add_rooms(r_list **rooms, char *room)
{
	r_list *p;
	p = (r_list *)malloc(sizeof(r_list));
	p->room = room;
	p->occupied = 0;
	p->ant_count = 0;
	p->links[0] = NULL;
	if(*rooms == NULL)
	{
		p -> next = NULL;
		*rooms = p;
	}
	else
	{
		p->next = *rooms;
		*rooms = p;
	}
}

static void	ft_creat_rooms_list(r_list **head, char **rooms)
{
	size_t i = 0;
	while(rooms[i] != NULL)
	{
		ft_add_rooms(head,rooms[i]);
		i++;
	}
}

void add_link(char **con, r_list **head, char *cp)
{
	int x;
	char **sp;
	char *s = *con;
	sp = ft_strsplit(s,'-');
	x = 0;
	while(sp[x] != NULL)
	{
		if(ft_strcmp(sp[x], cp) == 0)
		{
			int y = 0;
			r_list *tmp = *head;
			while(tmp != NULL && ft_strcmp(tmp->room,cp) != 0)
				tmp = tmp->next;
			while(tmp->links[y] != NULL)
				y++;
			if(x == 0)
			{
				tmp->links[y] = sp[1];
				tmp->links[y+1] = NULL;
			}
			else
			{
				tmp->links[y] = sp[0];
				tmp->links[y+1] = NULL;
			}
			*con = "  ";		
		}
		x++;
	}
}

void make_path(r_list **head, char **path, char *room, char *end)
{
	r_list *temp = *head;
	while(temp != NULL && ft_strcmp(temp->room,room) != 0)
		temp = temp->next;
	if(temp->links[0] != NULL)
	{
		ft_strcat(*path," ");
		ft_strcat(*path,temp->links[0]);
		if(temp != NULL && ft_strcmp(temp->links[0],end) != 0)
			make_path(head, path, temp->links[0], end);
	}
}

void call_add_link(char **con, r_list **head, char *start, char **names, char *end)
{
	int j = 0;
	int i = 0;
	while(con[i] != NULL)
	{
		add_link(&con[i], head, start);
		i++;
	}
	while(names[j] != NULL)
	{
		i = 0;
		if((ft_strcmp(names[j],end) != 0))
		{
			while(con[i] != NULL)
			{
				add_link(&con[i], head, names[j]);
				i++;
			}
		}
		j++;
	}

}

int main()
{
	char **con = ft_strsplit("start-1;3-4;2-4;1-5;6-5;end-6;1-2;2-end;3-start",';');
	char *paths= (char *)malloc(sizeof(char) * 100);
	char start[100]= "start";
	char end[100]= "end";
	r_list *head ;
	char **names= ft_strsplit("3 start end 4 1 2 5 6",' ');
	head = NULL;
	ft_creat_rooms_list(&head, ft_strsplit("3 start end 4 1 2 5 6",' '));
	int j = 0;
	int i = 0;

	call_add_link(con, &head, start,names, end);

/*	r_list *temp = head;
	while(temp != NULL)
	{
		int x = 0;
			printf("room %s  links [  ", temp->room);
		while(temp->links[x] != NULL)
			printf("%d-%s  ",x, temp->links[x++]);
		printf("]\n");
		temp = temp->next;
	}
	j = 0;

	while(con[j])
		printf("%s, ", con[j++]);

*/
ft_strcpy(paths,start);
make_path(&head,&paths,start,end);


		printf("\n%s\n",paths);
	return(0);
}
