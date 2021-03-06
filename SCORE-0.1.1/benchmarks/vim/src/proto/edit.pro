/* edit.c */
int edit __ARGS((int cmdchar, int startln, long count));
void display_dollar __ARGS((colnr_t col));
int vim_is_ctrl_x_key __ARGS((int c));
int add_completion_and_infercase __ARGS((char_u *str, int len, char_u *fname, int dir, int reuse));
int get_literal __ARGS((void));
void insertchar __ARGS((unsigned c, int force_formatting, int second_indent, int ctrlv));
void stop_arrow __ARGS((void));
void set_last_insert __ARGS((int c));
void beginline __ARGS((int flags));
int oneright __ARGS((void));
int oneleft __ARGS((void));
int cursor_up __ARGS((long n, int upd_topline));
int cursor_down __ARGS((long n, int upd_topline));
int stuff_inserted __ARGS((int c, long count, int no_esc));
char_u *get_last_insert __ARGS((void));
char_u *get_last_insert_save __ARGS((void));
void replace_push __ARGS((int c));
void fixthisline __ARGS((int (*get_the_indent)(void)));
int in_cinkeys __ARGS((int keytyped, int when, int line_is_empty));
int hkmap __ARGS((int c));
void ins_scroll __ARGS((void));
void ins_horscroll __ARGS((void));
