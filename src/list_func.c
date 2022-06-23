#include <stdio.h>
#include <stdlib.h>
#include "list_func.h"

list * pushlist(list * listp, void * value)
{
  list * new_list;
  new_list = (list *)malloc(sizeof(list));
  new_list->car = value;
  if(listp != NULL && new_list != NULL)
    new_list->cdr = listp;
  return new_list;
}

string_list * push_chrlist(string_list * listp, char value)
{
  string_list * new_list;
  new_list = (string_list *)malloc(sizeof(string_list));
  new_list->val = value;
  if(listp != NULL && new_list != NULL)
    new_list->listp = listp;
  else
   exit(1);
  return new_list;
}

list * poplist(list * listp)
{
  list * old_list;
  old_list = listp->cdr;
  free(listp);
  return old_list;
}

list * addcdrlist(list * listp)
{
  list * new_list;
  new_list = (list *)malloc(sizeof(list));
  new_list->car = NULL;
  if(listp != NULL)
    listp->cdr = new_list;
  new_list->cdr = NULL;
  return new_list;
}

list * addcarlist(list * listp)
{
  list * new_list;
  new_list = (list *)malloc(sizeof( list));
  new_list->cdr = NULL;
  if(listp != NULL)
    listp->car = new_list;
  new_list->car = NULL;
  return new_list;
}
