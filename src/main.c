#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 10

struct list{
  void * value;
  void * nextlist;
};

//char * straddlist(void)
//{
//  char * new_list;
  //new_list = (struct strlist *)malloc(sizeof(struct strlist));
  //  strcpy(new_list->str_list, "");
//  new_list = (char *)malloc(sizeof(char) * 500);
//  return new_list;
//}

struct list * addlist(struct list * listp)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  //  strcpy(new_list->value, "");
  new_list->value = NULL;
  if(listp != NULL)
    listp->nextlist = new_list;
  new_list->nextlist = NULL;
  return new_list;
}

int main(void){
  struct list first_list;
  struct list * temp_list;
  struct list * now_list;
//  char * temp_strlist;
//  char * now_strlist;
  char input[500];
  char a[10][500];
  //  char (*a_ptr)[10];
  int a_max=0;
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      //      strcpy(now_strlist, a);
//      temp_strlist = straddlist();
//      now_strlist = temp_strlist;
      fscanf(stdin, "%s", input);
      //      now_list->value = (char *)now_list->value;
      strncpy(((*a)+(500*x)), input, 500);
      now_list->value = ((*a)+(500*x));
      //      now_list->value = a[x];
//      strcpy(now_strlist, a);
//      now_list->value = (char *)now_strlist;
      temp_list = addlist( now_list );
      now_list = temp_list;
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      printf("%s:%p\n", (char *)now_list->value, now_list);
      temp_list = now_list->nextlist;
      now_list = temp_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      a_max += atoi((char *)now_list->value);
      printf("%d\n", a_max);
      temp_list = now_list->nextlist;
      now_list = temp_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  temp_list = now_list->nextlist;
  now_list = temp_list;
  fscanf(stdin, "%s", input);
  for(int x=0; x<(max-1); x++)
    {
      temp_list = now_list->nextlist;
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
