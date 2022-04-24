#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

struct list{
  void * car;
  void * cdr;
};

/* enum { */
  
/* } */

//char * straddlist(void)
//{
//  char * new_list;
  //new_list = (struct strlist *)malloc(sizeof(struct strlist));
  //  strcpy(new_list->str_list, "");
//  new_list = (char *)malloc(sizeof(char) * 500);
//  return new_list;
//}

struct list * pushlist(struct list * listp, void * value)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  new_list->car = value;
  if(listp != NULL && new_list != NULL)
    new_list->cdr = listp;
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
  //  strcpy(new_list->car, "");
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

/* struct list * removelist(struct list * listp) */
/* { */
  
/* } */

/* void parser(char *string) */
/* { */
/*   if( */
/* } */

void eval(struct list * listp)
{
}

int main(void){
  struct list first_list;
  struct list stack_list;
  struct list * temp_list;
  struct list * now_list;
  struct list * stacktemp_list;
  struct list * stacknow_list;
//  char * temp_strlist;
//  char * now_strlist;
  char input[500];
  char a[10][500];
  //  int index[10]={0,1,2,3,4,5,6,7,8,9};
  //  char (*a_ptr)[10];
  long int a_max=0;
  now_list = &first_list;
  stacknow_list = &stack_list;
  for(int x=0; x<max; x++)
    {
      //      strcpy(now_strlist, a);
//      temp_strlist = straddlist();
//      now_strlist = temp_strlist;
      fscanf(stdin, "%s", input);
      //      now_list->car = (char *)now_list->car;
      strncpy(((*a)+(500*x)), input, 500);
      now_list->car = ((*a)+(500*x));
      stacktemp_list = pushlist(stacknow_list, now_list);
      //      stacktemp_list = pushlist(stacknow_list, &index[x]);
      stacknow_list = stacktemp_list;
      //      now_list->car = a[x];
//      strcpy(now_strlist, a);
//      now_list->car = (char *)now_strlist;
      temp_list = addcdrlist( now_list );
      now_list = temp_list;
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      //      printf("%s:%p reverse-index:%d:%p\n", (char *)now_list->car, now_list, *((int *)stacknow_list->car), stacknow_list);
      printf("%s:%p listp:%p:%p\n", (char *)now_list->car, now_list, (struct list *)stacknow_list->car, stacknow_list);
      temp_list = now_list->cdr;
      now_list = temp_list;
      stacktemp_list = poplist(stacknow_list);
      stacknow_list = stacktemp_list;
      if(now_list == NULL || stacknow_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      a_max += atoi((char *)now_list->car);
      printf("%ld\n", a_max);
      temp_list = now_list->cdr;
      now_list = temp_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  temp_list = now_list->cdr;
  now_list = temp_list;
  fscanf(stdin, "%s", input);
  for(int x=0; x<(max-1); x++)
    {
      temp_list = now_list->cdr;
      printf("%p is freeing ...\n", now_list);
      free(now_list);
      printf("%p is free!\n", now_list);
      now_list = temp_list;
      if(now_list == NULL)
        {
          printf("error");
          return -1;
        }
    }
  return 0;

}
