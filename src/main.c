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

/* list new_token(const char *x, int token, char *text) */
/* { */
/*   list * return_list; */
/*   char *save_p = (char *)malloc(sizeof( */
/*   strtok_r(text, x,  */
/* 	   } */

int main(void)
{
  list first_list;
  list * now_list;
  list * next_list;

  list stack_list;
  list env_list;
  list code_list;
  list dump_list;

enum {
	TOKEN_NUM,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_MUL,
	TOKEN_DIV,
};
 char * buffer_p, * buf;
 char delim[] = "*";
  buffer_p = malloc_input();
  putchar('\n');
  for(int i=0; buffer_p[i] != NULL  && printf("%d\n", i); i++)
    if(buffer_p[i] == '*')
      strncpy(buf = (char *)malloc(sizeof(char) * i), buffer_p, sizeof(char) * i);
  printf("%s\n", buf);
  /* int code_stack[sizeof(buffer_p)], code_pointa=0; */
  /* for(int x=0; x < sizeof(buffer_p); x++) */
  /* { */
  /*   switch(buffer_p[x]){ */
  /*     case '1': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '2': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '3': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '4': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '5': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '6': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '7': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '8': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '9': code_stack[code_pointa++] = TOKEN_NUM; break; */
  /*     case '*': code_stack[code_pointa++] = TOKEN_MUL; break; */
  /*     case '/': code_stack[code_pointa++] = TOKEN_DIV; break; */
  /*     case '+': code_stack[code_pointa++] = TOKEN_ADD; break; */
  /*     case '-': code_stack[code_pointa++] = TOKEN_SUB; break; */
  /*     default: code_pointa++; break; */
  /*   } */
  /* } */
  /* for(code_pointa=0; code_stack[code_pointa] != TOKEN_MUL; code_pointa++){ */
  /*   code_stack */
  /* } */
  /* for(int x=0; x < sizeof(buffer_p); x++) */
  /*   printf("%c : %d\n", buffer_p[x], code_stack[x]); */
// 1+1*5 -> EXPR -> MUL + MUL -> NUM + NUM * NUM
// EXPR <- MUL ("+" MUL | "-" MUL)*
// MUL <- NUM ("*" NUM | "/" NUM)*

//  for(int i=0, deps=0; buffer_p[i] != '\0'; i++)
//    {
//      //      printf("\n%d\n", i);
//      //      for(; buffer_p[i] == ';' && buffer_p[i+1] == ';' || buffer_p[i] ; i++);
//      for(; buffer_p[i] == ' ' && buffer_p[i] != '\0';i++);
//      for(; buffer_p[i] != ' ' && buffer_p[i] != '\0';i++)
//	{
//	  if(buffer_p[i] == ';')
//	      for(; buffer_p[i] != '\n'; i++);
//	  if(buffer_p[i] == '(')
//	    {
//	      deps++; fprintf(stdout, ":%d:", deps);
//	    }
//	  else if(buffer_p[i] == ')')
//	    {
//	      deps--; fprintf(stdout, ":%d:", deps);
//	    }
//	  fprintf(stdout, "%c", buffer_p[i]);
//	}
//    }
  printf("\n");
  printf("%s", buffer_p);


  return 0;
}
