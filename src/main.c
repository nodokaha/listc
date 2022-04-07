#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

struct list{
  char value[500];
  struct list* nextlist;
};

struct list * addlist(struct list * listp)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  strcpy(new_list->value, "");
  if(listp != NULL)
    listp->nextlist = new_list;
  new_list->nextlist = NULL;
  return new_list;
}

int main(void){
  struct list first_list;
  struct list * old_list;
  struct list * now_list;
  char a[500];
  int a_max;
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      fscanf(stdin, "%s", a);
      strcpy(now_list->value,a);
      old_list = addlist( now_list );
      now_list = old_list;
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      printf("%s:%p\n", now_list->value, now_list);
      old_list = now_list->nextlist;
      now_list = old_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      a_max += atoi(now_list->value);
      printf("%d\n", a_max);
      old_list = now_list->nextlist;
      now_list = old_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  old_list = now_list->nextlist;
  now_list = old_list;
  fscanf(stdin, "%s", a);
  for(int x=0; x<(max-1); x++)
    {
      old_list = now_list->nextlist;
      printf("%p is freeing ...\n", now_list);
      free(now_list);
      printf("%p is free!\n", now_list);
      now_list = old_list;
      if(now_list == NULL)
        {
          printf("error");
          return -1;
        }
    }
  return 0;

}
