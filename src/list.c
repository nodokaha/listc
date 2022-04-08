#include <stdio.h>

struct list {
  void * car;
  void * cdr;
};

void * listadd(void * ptr)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  new_list->car = NULL;
  new_list->cdr = NULL;
  
