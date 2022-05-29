#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

struct list{
  void * car;
  void * cdr;
};

struct string_list{
  char val;
  void * listp;
};


struct list * pushlist(struct list * listp, void * value)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  new_list->car = value;
  if(listp != NULL && new_list != NULL)
    new_list->cdr = listp;
  return new_list;
}

struct string_list * push_chrlist(struct string_list * listp, char value)
{
  struct string_list * new_list;
  new_list = (struct string_list *)malloc(sizeof(struct string_list));
  new_list->val = value;
  if(listp != NULL && new_list != NULL)
    new_list->listp = listp;
  return new_list;
}

struct list * poplist(struct list * listp)
{
  struct list * old_list;
  old_list = listp->cdr;
  free(listp);
  return old_list;
}

struct list * addcdrlist(struct list * listp)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  new_list->car = NULL;
  if(listp != NULL)
    listp->cdr = new_list;
  new_list->cdr = NULL;
  return new_list;
}

struct list * addcarlist(struct list * listp)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  new_list->cdr = NULL;
  if(listp != NULL)
    listp->car = new_list;
  new_list->car = NULL;
  return new_list;
}

int main(void)
{
  struct list first_list;
  struct list * now_list;
  struct list * next_list;

  struct list stack_list;
  struct list env_list;
  struct list code_list;
  struct list dump_list;

  struct string_list first_chrlist;
  struct string_list * now_chrlist;
  struct string_list * next_chrlist;
  
  int counter = 0;
  now_chrlist = &first_chrlist;
  char one_char;
  for(counter = 0; fscanf(stdin, "%c", &one_char) && one_char != '\n'; counter++)
    {
      next_chrlist = push_chrlist(now_chrlist, one_char);
      now_chrlist = next_chrlist;
      if(now_chrlist == NULL)
	return -1;
    }
  printf("%d", counter);
  char buffer[counter+1];
  for(int i=0; NULL != now_chrlist->listp; i++)
    {
      buffer[i] = now_chrlist->val;
      next_chrlist = now_chrlist->listp;
      now_chrlist = next_chrlist;
      if(NULL == now_chrlist)
	return -1;
    }
  buffer[counter+1] = '\0';
  printf("%s", buffer);
  return 0;
}
