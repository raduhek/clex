#ifndef VT_HG
#define VT_Hg

char **value_table;
int vt_len;

void prepare_value_table();
void free_value_table();
char *get_value(int);
int get_or_create_entry(char *v, int l);


#endif
