#ifdef LIST_FUNC
#define LIST_FUNC
#endif

typedef struct {
  void * car;
  void * cdr;
}list;

typedef struct{
  char val;
  struct string_list * listp;
} string_list;

list * pushlist(list * listp, void * value);

string_list * push_chrlist(string_list * listp, char value);

list * poplist(list * listp);

list * addcdrlist(list * listp);

list * addcarlist(list * listp);
