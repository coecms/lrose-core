/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR (c) 1990 - 2016                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/*******************************************
 * inspectRawFmq_tdrp.c
 *
 * TDRP C code file 'inspectRawFmq' module.
 *
 * Code for program inspectRawFmq
 *
 * This file has been automatically
 * generated by TDRP, do not modify.
 *
 *******************************************/

#include "inspectRawFmq_tdrp.h"
#include <string.h>

/*
 * file scope variables
 */

static TDRPtable Table[5];
static inspectRawFmq_tdrp_struct *Params;
static char *Module = "inspectRawFmq";

/*************************************************************
 * inspectRawFmq_tdrp_load_from_args()
 *
 * Loads up TDRP using the command line args.
 *
 * Check TDRP_usage() for command line actions associated with
 * this function.
 *
 *   argc, argv: command line args
 *
 *   inspectRawFmq_tdrp_struct *params: loads up this struct
 * 
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *   char **params_path_p: if non-NULL, this is set to point to
 *                         the path of the params file used.
 *
 *  Returns 0 on success, -1 on failure.
 */

int inspectRawFmq_tdrp_load_from_args(int argc, char **argv,
                         inspectRawFmq_tdrp_struct *params,
                         char **override_list,
                         char **params_path_p)
{
  Params = params;
  inspectRawFmq_tdrp_init(Params);
  if (tdrpLoadFromArgs(argc, argv,
                       Table, Params,
                       override_list, params_path_p)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * inspectRawFmq_tdrp_load()
 *
 * Loads up TDRP for a given module.
 *
 * This version of load gives the programmer the option to load
 * up more than one module for a single application. It is a
 * lower-level routine than inspectRawFmq_tdrp_load_from_args,
 * and hence more flexible, but the programmer must do more work.
 *
 *   char *param_file_path: the parameter file to be read in.
 *
 *   inspectRawFmq_tdrp_struct *params: loads up this struct
 *
 *   char **override_list: A null-terminated list of overrides
 *     to the parameter file.
 *     An override string has exactly the format of an entry
 *     in the parameter file itself.
 *
 *  expand_env: flag to control environment variable
 *                expansion during tokenization.
 *              If TRUE, environment expansion is set on.
 *              If FALSE, environment expansion is set off.
 *
 *  Returns 0 on success, -1 on failure.
 */

int inspectRawFmq_tdrp_load(char *param_file_path,
               inspectRawFmq_tdrp_struct *params,
               char **override_list,
               int expand_env, int debug)
{
  Params = params;
  inspectRawFmq_tdrp_init(Params);
  if (tdrpLoad(param_file_path, Table,
               params, override_list,
               expand_env, debug)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * inspectRawFmq_tdrp_load_defaults()
 *
 * Loads up defaults for a given module.
 *
 * See inspectRawFmq_tdrp_load() for more details.
 *
 *  Returns 0 on success, -1 on failure.
 */

int inspectRawFmq_tdrp_load_defaults(inspectRawFmq_tdrp_struct *params,
                        int expand_env)
{
  Params = params;
  inspectRawFmq_tdrp_init(Params);
  if (tdrpLoad(NULL, Table,
               params, NULL,
               expand_env, FALSE)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * inspectRawFmq_tdrp_sync()
 *
 * Syncs the user struct data back into the parameter table,
 * in preparation for printing.
 */

void inspectRawFmq_tdrp_sync(void)
{
  tdrpUser2Table(Table, Params);
}

/*************************************************************
 * inspectRawFmq_tdrp_print()
 * 
 * Print params file
 *
 * The modes supported are:
 *
 *   PRINT_SHORT:   main comments only, no help or descriptions
 *                  structs and arrays on a single line
 *   PRINT_NORM:    short + descriptions and help
 *   PRINT_LONG:    norm  + arrays and structs expanded
 *   PRINT_VERBOSE: long  + private params included
 */

void inspectRawFmq_tdrp_print(FILE *out, tdrp_print_mode_t mode)
{
  tdrpPrint(out, Table, Module, mode);
}

/*************************************************************
 * inspectRawFmq_tdrp_check_all_set()
 *
 * Return TRUE if all set, FALSE if not.
 *
 * If out is non-NULL, prints out warning messages for those
 * parameters which are not set.
 */

int inspectRawFmq_tdrp_check_all_set(FILE *out)
{
  return (tdrpCheckAllSet(out, Table, Params));
}

/*************************************************************
 * inspectRawFmq_tdrp_check_is_set()
 *
 * Return TRUE if parameter is set, FALSE if not.
 *
 */

int inspectRawFmq_tdrp_check_is_set(char *param_name)
{
  return (tdrpCheckIsSet(param_name, Table, Params));
}

/*************************************************************
 * inspectRawFmq_tdrp_free_all()
 *
 * Frees up all TDRP dynamic memory.
 */

void inspectRawFmq_tdrp_free_all(void)
{
  tdrpFreeAll(Table, Params);
}

/*************************************************************
 * inspectRawFmq_tdrp_array_realloc()
 *
 * Realloc 1D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int inspectRawFmq_tdrp_array_realloc(char *param_name, int new_array_n)
{
  if (tdrpArrayRealloc(Table, Params, param_name, new_array_n)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * inspectRawFmq_tdrp_array2D_realloc()
 *
 * Realloc 2D array.
 *
 * If size is increased, the values from the last array entry is
 * copied into the new space.
 *
 * Returns 0 on success, -1 on error.
 */

int inspectRawFmq_tdrp_array2D_realloc(char *param_name,
                          int new_array_n1,
                          int new_array_n2)
{
  if (tdrpArray2DRealloc(Table, Params, param_name,
			 new_array_n1, new_array_n2)) {
    return (-1);
  } else {
    return (0);
  }
}

/*************************************************************
 * inspectRawFmq_tdrp_table()
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *inspectRawFmq_tdrp_table(void)
{
  return (Table);
}

/*************************************************************
 * inspectRawFmq_tdrp_init()
 *
 * Module table initialization function.
 *
 *
 * Returns pointer to static Table for this module.
 */

TDRPtable *inspectRawFmq_tdrp_init(inspectRawFmq_tdrp_struct *params)

{

  TDRPtable *tt = Table;

  inspectRawFmq_tdrp_struct pp; /* for computing byte_offsets */

  /* zero out struct, and store size */

  memset(params, 0, sizeof(inspectRawFmq_tdrp_struct));
  params->struct_size = sizeof(inspectRawFmq_tdrp_struct);

  /* Parameter 'Comment 0' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = COMMENT_TYPE;
  tt->param_name = tdrpStrDup("Comment 0");
  tt->comment_hdr = tdrpStrDup("Small program that reads a draw FMQ from CIDD, starts\nreading at the start of the queue and prints what it finds.\nMay be useful for debugging. Niles Oien Feb 2011.");
  tt->comment_text = tdrpStrDup("");
  tt++;
  
  /* Parameter 'draw_fmq_url' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("draw_fmq_url");
  tt->descr = tdrpStrDup("Draw fmw to inspect ");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.draw_fmq_url) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("fmqp:://localhost::draw.fmq");
  tt++;
  
  /* Parameter 'debug' */
  /* ctype is 'tdrp_bool_t' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = BOOL_TYPE;
  tt->param_name = tdrpStrDup("debug");
  tt->descr = tdrpStrDup("Debug messaging option beyond what is normally printed");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.debug) - (char *) &pp;
  tt->single_val.b = pFALSE;
  tt++;
  
  /* Parameter 'log_dir' */
  /* ctype is 'char*' */
  
  memset(tt, 0, sizeof(TDRPtable));
  tt->ptype = STRING_TYPE;
  tt->param_name = tdrpStrDup("log_dir");
  tt->descr = tdrpStrDup("Directory for log file output");
  tt->help = tdrpStrDup("");
  tt->val_offset = (char *) &(pp.log_dir) - (char *) &pp;
  tt->single_val.s = tdrpStrDup("");
  tt++;
  
  /* trailing entry has param_name set to NULL */
  
  tt->param_name = NULL;
  
  return (Table);

}
