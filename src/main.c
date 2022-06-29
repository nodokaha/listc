#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_func.h"
#include "input_func.h"

//#define max 10

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
	  if(buffer_p[i] == ';')
	      for(; buffer_p[i] != '\n'; i++);
	  if(buffer_p[i] == '(')
	    {
	      deps++; fprintf(stdout, ":%d:", deps);
	    }
	  else if(buffer_p[i] == ')')
	    {
	      deps--; fprintf(stdout, ":%d:", deps);
	    }
	  fprintf(stdout, "%c", buffer_p[i]);
	}
    }
  printf("\n");
  printf("%s", buffer_p);


  return 0;
}
