/* vi:set ts=8 sts=4 sw=4:
 *
 * VIM - Vi IMproved	by Bram Moolenaar
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 */

/*
 * definition of global variables
 *
 * EXTERN is only defined in main.c (and in option.h)
 */

#ifndef EXTERN
# define EXTERN extern
# define INIT(x)
#else
# ifndef INIT
#  define INIT(x) x
#  define DO_INIT
# endif
#endif

/*
 * Number of Rows and Columns in the screen.
 * Must be long to be able to use them as options in option.c.
 */
EXTERN long	Rows INIT(= MIN_ROWS + 1);   /* nr of rows in the screen */
EXTERN long	Columns INIT(= MIN_COLUMNS); /* nr of columns in the screen */

/*
 * The characters that are currently on the screen are kept in NextScreen.
 * It is a single block of characters, twice the size of the screen.
 * First come the characters for one line, then the attributes for that line.
 *
 * "LinePointers[n]" points into NextScreen, at the start of line 'n'.
 * "LinePointers[n] + Columns" points to the attibutes of line 'n'.
 */
EXTERN char_u	*NextScreen INIT(= NULL);
EXTERN char_u	**LinePointers INIT(= NULL);

EXTERN int	screen_Rows INIT(= 0);	    /* actual size of NextScreen */
EXTERN int	screen_Columns INIT(= 0);   /* actual size of NextScreen */

/*
 * When vgetc() is called, it sets mod_mask to the set of modifiers that are
 * held down based on the KSMOD_* symbols that are read first.
 */
EXTERN int	mod_mask INIT(= 0x0);		/* current key modifiers */

/*
 * Cmdline_row is the row where the command line starts, just below the
 * last window.
 * When the cmdline gets longer than the available space the screen gets
 * scrolled up. After a CTRL-D (show matches), after hitting ':' after
 * "hit return", and for the :global command, the command line is
 * temporarily moved. The old position is restored with the next call to
 * update_screen().
 */
EXTERN int	cmdline_row;

EXTERN int	redraw_cmdline INIT(= FALSE);	/* cmdline must be redrawn */
EXTERN int	clear_cmdline INIT(= FALSE);	/* cmdline must be cleared */
EXTERN int	modified INIT(= FALSE);		/* buffer was modified since
						    last redraw */
EXTERN int	tag_modified INIT(= FALSE);	/* buffer was modified since
						    start of tag command */
EXTERN int	screen_cleared INIT(= FALSE);	/* screen has been cleared */

/*
 * When '$' is included in 'cpoptions' option set:
 * When a change command is given that deletes only part of a line, a dollar
 * is put at the end of the changed text. dollar_vcol is set to the virtual
 * column of this '$'.
 */
EXTERN colnr_t	dollar_vcol INIT(= 0);

/*
 * used for completion on the command line
 */
EXTERN int	expand_context INIT(= CONTEXT_UNKNOWN);
EXTERN char_u	*expand_pattern INIT(= NULL);
EXTERN int	expand_interactively INIT(= FALSE);

#define CONT_ADDING	(1)	/* "normal" or "adding" expansion */
#define CONT_INTRPT	(2 + 4)	/* a ^X interrupted the current expansion */
				/* it's set only iff N_ADDS is set */
#define CONT_N_ADDS	(4)	/* next ^X<> will add-new or expand-current */
#define CONT_S_IPOS	(8)	/* next ^X<> will set initial_pos?
				 * if so, word-wise-expansion will set SOL */
#define CONT_SOL	(16)	/* pattern includes start of line, just for
				 * word-wise expansion, not set for ^X^L */
#define CONT_LOCAL	(32)	/* for ctrl_x_mode 0, ^X^P/^X^N do a local
				 * expansion, (eg use complete=.) */

EXTERN int		completion_length INIT(= 0);
EXTERN int		continue_status   INIT(= 0);

/*
 * Keep the last (typed) count for a Normal mode command.  Used for the
 * "count" built-in variable.
 */
EXTERN linenr_t		global_opnum INIT(= 0);

/*
 * Functions for putting characters in the command line,
 * while keeping NextScreen updated.
 */
EXTERN int	msg_col;
EXTERN int	msg_row;
EXTERN int	msg_scrolled;

EXTERN char_u	*keep_msg INIT(= NULL);	    /* msg to be shown after redraw */
EXTERN int	keep_msg_attr INIT(= 0);    /* highlight attr for keep_msg */
EXTERN int	need_fileinfo INIT(= FALSE);/* do fileinfo() after redraw */
EXTERN int	msg_scroll INIT(= FALSE);   /* msg_start() will scroll */
EXTERN int	msg_didout INIT(= FALSE);   /* msg_outstr() was used in line */
EXTERN int	msg_didany INIT(= FALSE);   /* msg_outstr() was used at all */
EXTERN int	msg_nowait INIT(= FALSE);   /* don't wait for this msg */
EXTERN int	emsg_off INIT(= FALSE);	    /* don't display errors for now */
EXTERN int	did_emsg;		    /* set by emsg() for DoOneCmd() */
EXTERN int	emsg_on_display INIT(= FALSE);	/* there is an error message */
EXTERN int	rc_did_emsg INIT(= FALSE);  /* vim_regcomp() called emsg() */
EXTERN int	no_wait_return INIT(= 0);   /* don't wait for return now */
EXTERN int	need_wait_return INIT(= 0); /* need to wait for return later */
EXTERN int	dont_wait_return INIT(= 0); /* no need to wait for return */
EXTERN int	quit_more INIT(= FALSE);    /* 'q' hit at "--more--" msg */
#if defined(UNIX) || defined(__EMX__)
EXTERN int	newline_on_exit INIT(= FALSE);	/* did msg in altern. screen */
EXTERN int	intr_char INIT(= 0);	    /* extra interrupt character */
#endif
EXTERN int	vgetc_busy INIT(= FALSE);   /* inside vgetc() now */

/*
 * Lines left before a "more" message.	Ex mode needs to be able to reset this
 * after you type something.
 */
EXTERN int lines_left INIT(= -1);	/* lines left for listing */


EXTERN char_u	*sourcing_name INIT( = NULL);/* name of error message source */
EXTERN linenr_t	sourcing_lnum INIT(= 0);    /* line number of the source file */
EXTERN int	file_on_stdin INIT(= FALSE);	/* read file from stdin */

EXTERN int	scroll_region INIT(= FALSE); /* term supports scroll region */
EXTERN int	highlight_match INIT(= FALSE);	/* show search match pos */
EXTERN int	search_match_len;		/* length of matched string */
EXTERN int	no_smartcase INIT(= FALSE);	/* don't use 'smartcase' once */
EXTERN int	need_check_timestamps INIT(= FALSE); /* got STOP signal */
EXTERN int	highlight_attr[HLF_COUNT];  /* Highl. attr for each context. */
EXTERN char_u	*use_gvimrc INIT(= NULL);	/* "-U" cmdline argument */
EXTERN int	cterm_normal_fg_color INIT(= 0);
EXTERN int	cterm_normal_fg_bold INIT(= 0);
EXTERN int	cterm_normal_bg_color INIT(= 0);

#ifdef AUTOCMD
EXTERN int	autocmd_busy INIT(= FALSE);	/* Is apply_autocmds() busy? */
EXTERN int	autocmd_no_enter INIT(= FALSE); /* *Enter autocmds disabled */
EXTERN int	autocmd_no_leave INIT(= FALSE); /* *Leave autocmds disabled */
EXTERN int	modified_was_set;		/* did ":set modified" */
#endif

#ifdef USE_MOUSE
/*
 * Mouse coordinates, set by check_termcode()
 */
EXTERN int	mouse_row;
EXTERN int	mouse_col;
EXTERN int	mouse_past_bottom INIT(= FALSE);/* mouse below last line */
EXTERN int	mouse_past_eol INIT(= FALSE);	/* mouse right of line */
#if defined(DEC_MOUSE)
/*
 * When the DEC mouse has been pressed but not yet released we enable
 * automatic querys for the mouse position.
 */
EXTERN int	WantQueryMouse INIT(= 0);
#endif

#endif

#ifdef USE_GUI
/*
 * Menu item just selected, set by check_termcode()
 */
EXTERN GuiMenu	*current_menu;

/*
 * Scrollbar moved and new value, set by check_termcode()
 */
EXTERN int	current_scrollbar;
EXTERN long_u	scrollbar_value;

/* found "-rv" or "-reverse" in command line args */
EXTERN int	found_reverse_arg INIT(= FALSE);
EXTERN char *	font_opt INIT(= NULL);
#endif

#ifdef USE_CLIPBOARD
EXTERN VimClipboard clipboard;
#endif

/*
 * All windows are linked in a list. firstwin points to the first entry, lastwin
 * to the last entry (can be the same as firstwin) and curwin to the currently
 * active window.
 */
EXTERN WIN	*firstwin;	/* first window */
EXTERN WIN	*lastwin;	/* last window */
EXTERN WIN	*curwin;	/* currently active window */

/*
 * All buffers are linked in a list. 'firstbuf' points to the first entry,
 * 'lastbuf' to the last entry and 'curbuf' to the currently active buffer.
 */
EXTERN BUF	*firstbuf INIT(= NULL);	/* first buffer */
EXTERN BUF	*lastbuf INIT(= NULL);	/* last buffer */
EXTERN BUF	*curbuf INIT(= NULL);	/* currently active buffer */

/*
 * list of files being edited (argument list)
 */
EXTERN char_u	**arg_files;	/* list of files */
EXTERN int	arg_file_count;	/* number of files */
EXTERN int	arg_had_last INIT(= FALSE); /* accessed last file in arglist */

EXTERN int	ru_col;		/* column for ruler */
EXTERN int	sc_col;		/* column for shown command */

/*
 * When starting or exiting some things are done differently (e.g. screen
 * updating).
 */
EXTERN int	starting INIT(= TRUE);
				/* set to FALSE when starting up finished */
EXTERN int	exiting INIT(= FALSE);
				/* set to TRUE when abandoning Vim */
EXTERN int	full_screen INIT(= FALSE);
				/* set to TRUE when doing full-screen output
				 * otherwise only writing some messages */

EXTERN int	restricted INIT(= FALSE);
				/* set to TRUE when started as "rvim" */
EXTERN int	secure INIT(= FALSE);
				/* set to TRUE when only "safe" commands are
				 * allowed, e.g. when sourcing .exrc or .vimrc
				 * in current directory */

EXTERN int	silent_mode INIT(= FALSE);
				/* set to TRUE when "-s" commandline argument
				 * used for ex */

EXTERN FPOS	VIsual;		/* start position of active Visual selection */
EXTERN int	VIsual_active INIT(= FALSE);
				/* wheter Visual mode is active */

EXTERN int	VIsual_mode INIT(= 'v');
				/* type of Visual mode */
EXTERN int	redo_VIsual_busy INIT(= FALSE);
				/* TRUE when redoing Visual */

#ifdef USE_MOUSE
/*
 * When pasting text with the middle mouse button in visual mode with
 * restart_edit set, remember where it started so we can set Insstart.
 */
EXTERN FPOS	where_paste_started;
#endif

/*
 * This flag is used to make auto-indent work right on lines where only a
 * <RETURN> or <ESC> is typed. It is set when an auto-indent is done, and
 * reset when any other editting is done on the line. If an <ESC> or <RETURN>
 * is received, and did_ai is TRUE, the line is truncated.
 */
EXTERN int     did_ai INIT(= FALSE);

#ifdef SMARTINDENT
/*
 * This flag is set when a smart indent has been performed. When the next typed
 * character is a '{' the inserted tab will be deleted again.
 */
EXTERN int	did_si INIT(= FALSE);

/*
 * This flag is set after an auto indent. If the next typed character is a '}'
 * one indent will be removed.
 */
EXTERN int	can_si INIT(= FALSE);

/*
 * This flag is set after an "O" command. If the next typed character is a '{'
 * one indent will be removed.
 */
EXTERN int	can_si_back INIT(= FALSE);
#endif

EXTERN int	State INIT(= NORMAL);	/* This is the current state of the
					 * command interpreter. */
/*
 * ex mode (Q) state
 */
EXTERN int exmode_active INIT(= FALSE);
EXTERN int ex_no_reprint INIT(= FALSE); /* no need to print after z or p */

EXTERN int	Recording INIT(= FALSE);/* TRUE when recording into a reg. */
EXTERN int	Exec_reg INIT(= FALSE);	/* TRUE when executing a register */

EXTERN int	finish_op INIT(= FALSE);/* TRUE while an operator is pending */

EXTERN int	no_mapping INIT(= FALSE);   /* currently no mapping allowed */
EXTERN int	allow_keys INIT(= FALSE);   /* allow key codes when no_mapping
					     * is set */
EXTERN int	no_u_sync INIT(= 0);	/* Don't call u_sync() */

EXTERN int	restart_edit INIT(= 0);	/* call edit when next cmd finished */
EXTERN int	arrow_used;		/* Normally FALSE, set to TRUE after
					 * hitting cursor key in insert mode.
					 * Used by vgetorpeek() to decide when
					 * to call u_sync() */
#ifdef INSERT_EXPAND
EXTERN char_u	*edit_submode INIT(= NULL); /* msg for CTRL-X submode */
EXTERN char_u	*edit_submode_extra INIT(= NULL);/* extra info for msg */
EXTERN enum hlf_value	edit_submode_highl; /* highl. method for extra info */
EXTERN int	ctrl_x_mode INIT(= 0);	/* Which Ctrl-X mode are we in? */
#endif

EXTERN int	no_abbr INIT(= TRUE);	/* TRUE when no abbreviations loaded */
EXTERN int	fo_do_comments INIT(= FALSE);
					/* TRUE when comments are to be
					 * formatted */
#ifdef MSDOS
EXTERN int	beep_count INIT(= 0);	/* nr of beeps since last char typed */
#endif

#ifdef USE_EXE_NAME
EXTERN char_u	*exe_name;		/* the name of the executable */
#endif

#ifdef USE_GUI_WIN32
EXTERN	int	dont_scroll INIT(= FALSE);/* don't use scrollbars when TRUE */
#endif

EXTERN char_u	*IObuff;		/* sprintf's are done in this buffer */
EXTERN char_u	*NameBuff;		/* file names are expanded in this
					 * buffer */
EXTERN char_u	msg_buf[MSG_BUF_LEN];	/* small buffer for messages */

EXTERN int	RedrawingDisabled INIT(= FALSE);
					/* Set to TRUE if doing :g */
EXTERN int	display_hint INIT(= HINT_NONE);
					/* hint to insert/delete character */

EXTERN int	readonlymode INIT(= FALSE); /* Set to TRUE for "view" */
EXTERN int	recoverymode INIT(= FALSE); /* Set to TRUE for "-r" option */

EXTERN char_u	*typebuf INIT(= NULL);	/* buffer for typed characters */
EXTERN int	typebuflen;		/* size of typebuf */
EXTERN int	typeoff;		/* current position in typebuf */
EXTERN int	typelen;		/* number of valid chars in typebuf */
EXTERN int	KeyTyped;		/* TRUE if user typed current char */
EXTERN int	KeyStuffed;		/* TRUE if current char from stuffbuf */
EXTERN int	maptick INIT(= 0);	/* tick for each non-mapped char */

EXTERN char_u	chartab[256];		/* table used in charset.c */

EXTERN int	must_redraw INIT(= 0);	    /* type of redraw necessary */
EXTERN int	skip_redraw INIT(= FALSE);  /* skip redraw once */
EXTERN int	do_redraw INIT(= FALSE);    /* extra redraw once */

EXTERN int	need_highlight_changed INIT(= TRUE);
EXTERN char_u	*use_viminfo INIT(= NULL);  /* name of viminfo file to use */

#define NSCRIPT 15
EXTERN FILE	*scriptin[NSCRIPT];	    /* streams to read script from */
EXTERN int	curscript INIT(= 0);	    /* index in scriptin[] */
EXTERN FILE	*scriptout  INIT(= NULL);   /* stream to write script to */
EXTERN int	read_cmd_fd INIT(= 0);	    /* fd to read commands from */

EXTERN int	got_int INIT(= FALSE);	    /* set to TRUE when interrupt
						signal occurred */
EXTERN int	term_console INIT(= FALSE); /* set to TRUE when consule used */
EXTERN int	termcap_active INIT(= FALSE);	/* set by starttermcap() */
EXTERN int	bangredo INIT(= FALSE);	    /* set to TRUE whith ! command */
EXTERN int	searchcmdlen;		    /* length of previous search cmd */
EXTERN int	reg_ic INIT(= 0);	    /* p_ic passed to vim_regexec() */
EXTERN int	reg_syn INIT(= 0);	    /* vim_regexec() used for syntax */

EXTERN int	did_outofmem_msg INIT(= FALSE);
					    /* set after out of memory msg */
EXTERN int	did_swapwrite_msg INIT(= FALSE);
					    /* set after swap write error msg */
EXTERN int	undo_off INIT(= FALSE);	    /* undo switched off for now */
EXTERN int	global_busy INIT(= 0);	    /* set when :global is executing */
EXTERN int	need_start_insertmode INIT(= FALSE);
					    /* start insert mode soon */
EXTERN char_u	*last_cmdline INIT(= NULL); /* last command line (for ":) */
EXTERN char_u	*new_last_cmdline INIT(= NULL);	/* new value for last_cmdline */
#ifdef AUTOCMD
EXTERN char_u	*autocmd_fname INIT(= NULL); /* fname for <afile> on cmdline */
#endif

EXTERN int	postponed_split INIT(= 0);  /* for CTRL-W CTRL-] command */
EXTERN int	replace_offset INIT(= 0);   /* offset for replace_push() */

EXTERN char_u	*escape_chars INIT(= (char_u *)" \t\\\"|");
					    /* need backslash in cmd line */

EXTERN char_u	*help_save_isk INIT(= NULL);/* 'isk' saved by do_help() */
EXTERN long	help_save_ts INIT(= 0);	    /* 'ts' saved by do_help() */
EXTERN int	keep_help_flag INIT(= FALSE); /* doing :ta from help file */

/*
 * When a string option is NULL (which only happens in out-of-memory
 * situations), it is set to empty_option, to avoid having to check for NULL
 * everywhere.
 */
EXTERN char_u	*empty_option INIT(= (char_u *)"");

#ifdef DEBUG
EXTERN FILE *debugfp INIT(= NULL);
#endif

EXTERN FILE *redir_fd INIT(= NULL);	/* message redirection file */
EXTERN int  redir_off INIT(= FALSE);	/* no redirection for a moment */

#ifdef HAVE_LANGMAP
EXTERN char_u	langmap_mapchar[256];	/* mapping for language keys */
#endif

#ifdef WIN32
EXTERN char_u	toupper_tab[256];	/* table for toupper() */
EXTERN char_u	tolower_tab[256];	/* table for tolower() */
#endif

EXTERN char	breakat_flags[256];	/* which characters are in 'breakat' */

extern char *Version;		/* this is in version.c */
extern char *mediumVersion;	/* this is in version.c */
extern char *longVersion;	/* this is in version.c */

/*
 * Some file names for Unix are stored in pathdef.c, to make their value
 * depend on the Makefile.
 */
#ifdef HAVE_PATHDEF
extern char_u *default_vim_dir;	    /* this is in pathdef.c */
extern char_u *all_cflags;	    /* this is in pathdef.c */
extern char_u *all_lflags;	    /* this is in pathdef.c */
#endif

EXTERN char_u no_lines_msg[]	    INIT(="--No lines in buffer--");

/*
 * The error messages that can be shared are included here.
 * Excluded are very specific errors and debugging messages.
 */
EXTERN char_u e_abort[]	    INIT(="Command aborted");
EXTERN char_u e_ambmap[]    INIT(="Ambiguous mapping");
EXTERN char_u e_argreq[]    INIT(="Argument required");
EXTERN char_u e_backslash[] INIT(="\\ should be followed by /, ? or &");
EXTERN char_u e_curdir[]    INIT(="Command not allowed from exrc/vimrc in current dir or tag search");
EXTERN char_u e_exists[]    INIT(="File exists (use ! to override)");
EXTERN char_u e_failed[]    INIT(="Command failed");
EXTERN char_u e_internal[]  INIT(="Internal error");
EXTERN char_u e_interr[]    INIT(="Interrupted");
EXTERN char_u e_invaddr[]   INIT(="Invalid address");
EXTERN char_u e_invarg[]    INIT(="Invalid argument");
EXTERN char_u e_invarg2[]   INIT(="Invalid argument: %s");
EXTERN char_u e_invexpr2[]  INIT(="Invalid expression: %s");
EXTERN char_u e_invrange[]  INIT(="Invalid range");
EXTERN char_u e_invcmd[]    INIT(="Invalid command");
EXTERN char_u e_letunexp[]  INIT(="Unexpected characters before '='");
EXTERN char_u e_markinval[] INIT(="Mark has invalid line number");
EXTERN char_u e_marknotset[]	INIT(="Mark not set");
EXTERN char_u e_nesting[]   INIT(="Scripts nested too deep");
EXTERN char_u e_noalt[]	    INIT(="No alternate file");
EXTERN char_u e_nobang[]    INIT(="No ! allowed");
EXTERN char_u e_nogvim[]    INIT(="GUI cannot be used: Not enabled at compile time\n");
EXTERN char_u e_nohebrew[]  INIT(="Hebrew cannot be used: Not enabled at compile time\n");
EXTERN char_u e_nofarsi[]   INIT(="Farsi cannot be used: Not enabled at compile time\n");
EXTERN char_u e_noinstext[] INIT(="No inserted text yet");
EXTERN char_u e_nolastcmd[] INIT(="No previous command line");
EXTERN char_u e_nomap[]	    INIT(="No such mapping");
EXTERN char_u e_nomatch[]   INIT(="No match");
EXTERN char_u e_noname[]    INIT(="No file name");
EXTERN char_u e_nopresub[]  INIT(="No previous substitute regular expression");
EXTERN char_u e_noprev[]    INIT(="No previous command");
EXTERN char_u e_noprevre[]  INIT(="No previous regular expression");
EXTERN char_u e_norange[]   INIT(="No range allowed");
EXTERN char_u e_noroom[]    INIT(="Not enough room");
EXTERN char_u e_notcreate[] INIT(="Can't create file %s");
EXTERN char_u e_notmp[]	    INIT(="Can't get temp file name");
EXTERN char_u e_notopen[]   INIT(="Can't open file %s");
EXTERN char_u e_notread[]   INIT(="Can't read file %s");
EXTERN char_u e_nowrtmsg[]  INIT(="No write since last change (use ! to override)");
EXTERN char_u e_null[]	    INIT(="Null argument");
EXTERN char_u e_number[]    INIT(="Number expected");
EXTERN char_u e_openerrf[]  INIT(="Can't open errorfile %s");
EXTERN char_u e_outofmem[]  INIT(="Out of memory!");
EXTERN char_u e_patnotf[]   INIT(="Pattern not found");
EXTERN char_u e_positive[]  INIT(="Argument must be positive");
EXTERN char_u e_quickfix[]  INIT(="No Errors");
EXTERN char_u e_re_damg[]   INIT(="Damaged match string");
EXTERN char_u e_re_corr[]   INIT(="Corrupted regexp program");
EXTERN char_u e_readonly[]  INIT(="'readonly' option is set (use ! to override)");
EXTERN char_u e_readerrf[]  INIT(="Error while reading errorfile");
EXTERN char_u e_scroll[]    INIT(="Invalid scroll size");
EXTERN char_u e_tagformat[] INIT(="Format error in tags file \"%s\"");
EXTERN char_u e_tagstack[]  INIT(="tag stack empty");
EXTERN char_u e_toocompl[]  INIT(="Command too complex");
EXTERN char_u e_toombra[]   INIT(="Too many \\(");
EXTERN char_u e_toomket[]   INIT(="Too many \\)");
EXTERN char_u e_toomsbra[]  INIT(="Too many [");
EXTERN char_u e_toolong[]   INIT(="Command too long");
EXTERN char_u e_toomany[]   INIT(="Too many file names");
EXTERN char_u e_trailing[]  INIT(="Trailing characters");
EXTERN char_u e_umark[]	    INIT(="Unknown mark");
EXTERN char_u e_unknown[]   INIT(="Unknown");
EXTERN char_u e_write[]	    INIT(="Error while writing");
EXTERN char_u e_zerocount[] INIT(="Zero count");

/*
 * Optional Farsi support.  Include it here, so EXTERN and INIT are defined.
 */
#ifdef FKMAP
# include "farsi.h"
#endif
