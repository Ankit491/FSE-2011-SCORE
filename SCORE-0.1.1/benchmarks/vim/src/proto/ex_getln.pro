/* ex_getln.c */
char_u *getcmdline __ARGS((int firstc, long count, int indent));
char_u *getexline __ARGS((int c, void *dummy, int indent));
char_u *getexmodeline __ARGS((int c, void *dummy, int indent));
int cmdline_overstrike __ARGS((void));
int cmdline_at_end __ARGS((void));
int put_on_cmdline __ARGS((char_u *str, int len, int redraw));
void redrawcmdline __ARGS((void));
void compute_cmdrow __ARGS((void));
void gotocmdline __ARGS((int clr));
char_u *ExpandOne __ARGS((char_u *str, char_u *orig, int options, int mode));
void tilde_replace __ARGS((char_u *orig_pat, int num_files, char_u **files));
char_u *addstar __ARGS((char_u *fname, int len));
int ExpandGeneric __ARGS((vim_regexp *prog, int *num_file, char_u ***file, char_u *((*func)(int))));
void add_to_history __ARGS((int histype, char_u *new_entry));
void prepare_viminfo_history __ARGS((int asklen));
int read_viminfo_history __ARGS((char_u *line, FILE *fp));
void finish_viminfo_history __ARGS((void));
void write_viminfo_history __ARGS((FILE *fp));
