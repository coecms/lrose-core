// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program MdvPlayback
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
using namespace std;

#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params path ] specify params file path\n"
        << "   [ -check_params] check which params are not set\n"
        << "   [ -print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("MdvPlayback");
    tt->comment_text = tdrpStrDup("This program allows simulation of real time MDV data arrival from a set of URL's. It mirrors what came in from the original URL's, writing to similar URL's on localhost. The playback rate is based on the 'time_written' field in the MDV headers, and the writing is in order of 'time_written', with sleep between writes when appropriate.");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("Synchronization");
    tt->comment_text = tdrpStrDup("Synchronization is supported, in which one particular input is synchronized with specific outputs, in that playback pauses until the outputs 'catch up' with input. This is for the case where an app or apps read the playback output and generate their own output.  The single synchronization input URL can be thought of as the most upstream input to the playback, and the synchronization outputs as the most downstream output.  The synchronization prevents playback from getting ahead of the downstream apps.");
    tt++;
    
    // Parameter 'debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("debug");
    tt->help = tdrpStrDup("If TRUE, debugging is enabled");
    tt->val_offset = (char *) &debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'inputData'
    // ctype is '_data_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("inputData");
    tt->descr = tdrpStrDup("The playback data");
    tt->help = tdrpStrDup("This is the data to be played back:\n  url = source location, mdvp:://host::path\n  isObs = TRUE for flat (non-forecast) data, FALSE for forecasts\n  useDataTime = TRUE to ignore 'time_written' and use data_time\n  latencyHoursMax = Expected maximum latency (hours) of the data\nA positive latency means the time_written is ahead of the data_time, as would be found in most real-time numerical model data.");
    tt->array_offset = (char *) &_inputData - &_start_;
    tt->array_n_offset = (char *) &inputData_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(data_t);
    tt->array_n = 0;
    tt->struct_def.name = tdrpStrDup("data_t");
    tt->struct_def.nfields = 4;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("url");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_inputData->url - (char *) _inputData;
      tt->struct_def.fields[1].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[1].fname = tdrpStrDup("isObs");
      tt->struct_def.fields[1].ptype = BOOL_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_inputData->isObs - (char *) _inputData;
      tt->struct_def.fields[2].ftype = tdrpStrDup("boolean");
      tt->struct_def.fields[2].fname = tdrpStrDup("useDataTime");
      tt->struct_def.fields[2].ptype = BOOL_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_inputData->useDataTime - (char *) _inputData;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("latencyHoursMax");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_inputData->latencyHoursMax - (char *) _inputData;
    tt->n_struct_vals = 0;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
    tt++;
    
    // Parameter 'path'
    // ctype is '_input_output_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("path");
    tt->descr = tdrpStrDup("Input/output path pairs");
    tt->help = tdrpStrDup("Each pair gives a subsitution string for input to output URL. The first string, if found in inputData[i].url will be replaced with the second string for plabyack into the corresponding output url. Either the input_path or output_path in the pair can be the empty string.  This is an easy way to playback by reading from one location and writing to another that differs slightly");
    tt->array_offset = (char *) &_path - &_start_;
    tt->array_n_offset = (char *) &path_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(input_output_t);
    tt->array_n = 1;
    tt->struct_def.name = tdrpStrDup("input_output_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("string");
      tt->struct_def.fields[0].fname = tdrpStrDup("input_path");
      tt->struct_def.fields[0].ptype = STRING_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_path->input_path - (char *) _path;
      tt->struct_def.fields[1].ftype = tdrpStrDup("string");
      tt->struct_def.fields[1].fname = tdrpStrDup("output_path");
      tt->struct_def.fields[1].ptype = STRING_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_path->output_path - (char *) _path;
    tt->n_struct_vals = 2;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].s = tdrpStrDup("");
      tt->struct_vals[1].s = tdrpStrDup("");
    tt++;
    
    // Parameter 'mode'
    // ctype is '_playback_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("mode");
    tt->descr = tdrpStrDup("playback mode");
    tt->help = tdrpStrDup("Two modes are supported. PRE_PLAYBACK mode is a way to create latest data info files for the very latest data for which time < start time. The purpose of this mode is to create a latest data info file that is what would be in existance at the start time of 'regular' playback.   PLAYBACK mode is the normal mode, in which data written between start_time and end_time is played back.");
    tt->val_offset = (char *) &mode - &_start_;
    tt->enum_def.name = tdrpStrDup("playback_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("PRE_PLAYBACK");
      tt->enum_def.fields[0].val = PRE_PLAYBACK;
      tt->enum_def.fields[1].name = tdrpStrDup("PLAYBACK");
      tt->enum_def.fields[1].val = PLAYBACK;
    tt->single_val.e = PLAYBACK;
    tt++;
    
    // Parameter 'start_time'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("start_time");
    tt->descr = tdrpStrDup("Start time");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_start_time - &_start_;
    tt->array_n_offset = (char *) &start_time_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = TRUE;
    tt->array_elem_size = sizeof(int);
    tt->array_n = 6;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].i = 2012;
      tt->array_vals[1].i = 11;
      tt->array_vals[2].i = 1;
      tt->array_vals[3].i = 0;
      tt->array_vals[4].i = 0;
      tt->array_vals[5].i = 0;
    tt++;
    
    // Parameter 'end_time'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("end_time");
    tt->descr = tdrpStrDup("End time");
    tt->help = tdrpStrDup("");
    tt->array_offset = (char *) &_end_time - &_start_;
    tt->array_n_offset = (char *) &end_time_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = TRUE;
    tt->array_elem_size = sizeof(int);
    tt->array_n = 6;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
      tt->array_vals[0].i = 2012;
      tt->array_vals[1].i = 11;
      tt->array_vals[2].i = 1;
      tt->array_vals[3].i = 1;
      tt->array_vals[4].i = 0;
      tt->array_vals[5].i = 0;
    tt++;
    
    // Parameter 'speedup'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("speedup");
    tt->descr = tdrpStrDup("speedup");
    tt->help = tdrpStrDup("Speed of playback.  Set to > 1 to speed up the playback. Set < 1 to slow down playback. If <= 0, it is an error.");
    tt->val_offset = (char *) &speedup - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'show_realtime'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("show_realtime");
    tt->descr = tdrpStrDup("show realtime");
    tt->help = tdrpStrDup("TRUE to print the real time each playback happens, FALSE to print only the time_written and data time");
    tt->val_offset = (char *) &show_realtime - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'minutes_delay_before_exit'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("minutes_delay_before_exit");
    tt->descr = tdrpStrDup("delay at end");
    tt->help = tdrpStrDup("Number of minutes to delay when playback is complete before exiting the app, typically to allow downstream apps to 'catch up' prior to exit.");
    tt->val_offset = (char *) &minutes_delay_before_exit - &_start_;
    tt->single_val.d = 0;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("Playback with synchronization");
    tt->comment_text = tdrpStrDup("The input_sync_url is monitored, and the data times written to that URL are synchronized with a set of output_sync_url's. The input_sync_url should be one of the playback output URL's, and the output_sync_url's should be URL's that are written to by apps that are downstream of MdvPlayback.");
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("Synchronization event");
    tt->comment_text = tdrpStrDup("The event that triggers synchronization is a change in time values from the playback data stream.  If sync_to_time_written=TRUE, this event is when time_written changes from one 'interval' to the next. The 'intervals' are specified by 'resolution_minutes_sync'.  If sync_to_time_written=FALSE, this event is whenever data_time changes.  Using data_time only makes sense if playback data does not have any data with latency, because if there is latency in some but not all of the playback data, time will 'go backwards' when data with latency is played back, which confuses the synchronization");
    tt++;
    
    // Parameter 'input_sync_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("input_sync_url");
    tt->descr = tdrpStrDup("input sync");
    tt->help = tdrpStrDup("If empty, there is no playback synchronization. If it is not empty, time values for playback data from this URL are captured for use in synchronizing with downstream outputs. This must be one of the inputData[i] URL's after conversion to output using path[]");
    tt->val_offset = (char *) &input_sync_url - &_start_;
    tt->single_val.s = tdrpStrDup("");
    tt++;
    
    // Parameter 'output_sync_url'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_sync_url");
    tt->descr = tdrpStrDup("output sync");
    tt->help = tdrpStrDup("Used only when input_sync_url is not empty. During the synchronization step, these URL's are queried until data_time values agree with the latest data_time value from input_sync_url.");
    tt->array_offset = (char *) &_output_sync_url - &_start_;
    tt->array_n_offset = (char *) &output_sync_url_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(char*);
    tt->array_n = 0;
    tt->array_vals = (tdrpVal_t *)
        tdrpMalloc(tt->array_n * sizeof(tdrpVal_t));
    tt++;
    
    // Parameter 'max_sync_wait_minutes'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_sync_wait_minutes");
    tt->descr = tdrpStrDup("Max wait minutes");
    tt->help = tdrpStrDup("When synchronizing, the app will wait for times to match, but will give up after this many minutes of waiting");
    tt->val_offset = (char *) &max_sync_wait_minutes - &_start_;
    tt->single_val.d = 15;
    tt++;
    
    // Parameter 'sync_to_time_written'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("sync_to_time_written");
    tt->descr = tdrpStrDup("Synchronize using time written");
    tt->help = tdrpStrDup("If TRUE, synchronization is over fixed length intervals specified by resolution_minutes_sync, with sychronization happening whenever time_written changes to a newer interval.  If FALSE, synchronization is initiated whenever data_time values from the played back data change");
    tt->val_offset = (char *) &sync_to_time_written - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'resolution_minutes_sync'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("resolution_minutes_sync");
    tt->descr = tdrpStrDup("sync resolution minutes");
    tt->help = tdrpStrDup("Used only when sync_to_time_written=TRUE. In this case, The playback time range is broken into intervals of this length, with assumed alignment to minute/second=0,0. For example if resolution_minutes_sync=15, The intervals are [0,15), [15,30), [30,45), [45,60).  When time_written crosses over into a new interval, synchronization is initiated");
    tt->val_offset = (char *) &resolution_minutes_sync - &_start_;
    tt->single_val.d = 15;
    tt++;
    
    // Parameter 'debug_sync'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("debug_sync");
    tt->descr = tdrpStrDup("sync debugging");
    tt->help = tdrpStrDup("If TRUE and doing the synchronization actions, debug output regarding the synchronization will be printed");
    tt->val_offset = (char *) &debug_sync - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("Threading");
    tt->comment_text = tdrpStrDup("Threading is supported, with threading on the reading in of data. This speeds things up specifically for multiple inputs having the same written time");
    tt++;
    
    // Parameter 'num_threads'
    // ctype is 'int'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = INT_TYPE;
    tt->param_name = tdrpStrDup("num_threads");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("Set to 0 for no threading");
    tt->val_offset = (char *) &num_threads - &_start_;
    tt->single_val.i = 0;
    tt++;
    
    // Parameter 'thread_debug'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("thread_debug");
    tt->descr = tdrpStrDup("");
    tt->help = tdrpStrDup("Set to TRUE to see thread debug information");
    tt->val_offset = (char *) &thread_debug - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
