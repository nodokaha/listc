#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_func.h"

#define max 10

char * malloc_input(void)
{
  string_list first_chrlist;
  string_list * now_chrlist;
  string_list * next_chrlist;

  first_chrlist.listp = NULL;

  int counter = 0;
  now_chrlist = &first_chrlist;
  char one_char;
  for(counter = 0; fscanf(stdin, "%c", &one_char) != EOF && one_char != EOF && one_char != '\0' && one_char != '$'; counter++)
    {
      next_chrlist = push_chrlist(now_chrlist, one_char);
      now_chrlist = next_chrlist;
      if(now_chrlist == NULL)
	printf("Error!");
    }
  printf("%d", counter);
  char * buffer = (char *)malloc(sizeof(char) * (counter+1));
  buffer[0] = '\n';
  for(int i=0; i<counter; i++)
    {
      buffer[counter - i] = now_chrlist->val;
      next_chrlist = now_chrlist->listp;
      free(now_chrlist);
      now_chrlist = next_chrlist;
      if(NULL == now_chrlist)
	printf("Error!");
    }
  buffer[counter+1] = '\0';
  return buffer;
}

/* struct list * parser(char * buffer) */
/* { */
/*   //  for(int i=0; i< */
/* 	//  switch  */
/* } */

int main(void)
{
  list first_list;
  list * now_list;
  list * next_list;

  list stack_list;
  list env_list;
  list code_list;
  list dump_list;

  char * buffer_p;

  buffer_p = malloc_input();
  for(int i=0, deps=0; buffer_p[i] != '\0'; i++)
    {
      //      printf("\n%d\n", i);
      //      for(; buffer_p[i] == ';' && buffer_p[i+1] == ';' || buffer_p[i] ; i++);
      for(; buffer_p[i] == ' ' && buffer_p[i] != '\0';i++);
      for(; buffer_p[i] != ' ' && buffer_p[i] != '\0';i++)
	{
	  if(buffer_p[i] == '(')
	    deps++;
	  else if(buffer_p[i] == ')')
	    deps--;
	  fprintf(stdout, "%c:%d:", buffer_p[i], deps);
	}
    }
  printf("\n");
  printf("%s", buffer_p);


  return 0;
}
