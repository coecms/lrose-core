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
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* RCS info
 *   $Author: dixon $
 *   $Locker:  $
 *   $Date: 2016/03/03 18:09:41 $
 *   $Id: NumObsStatCalc.hh,v 1.3 2016/03/03 18:09:41 dixon Exp $
 *   $Revision: 1.3 $
 *   $State: Exp $
 */
 
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

/************************************************************************
 * NumObsStatCalc: Class for calculating the number of observations statistic.
 *
 * RAP, NCAR, Boulder CO
 *
 * July 2004
 *
 * Nancy Rehak
 *
 ************************************************************************/

#ifndef NumObsStatCalc_HH
#define NumObsStatCalc_HH

#include <Mdv/climo/StatCalc.hh>

using namespace std;

class NumObsStatCalc : public StatCalc
{
 public:

  /////////////////////////////
  // Constructors/destructor //
  /////////////////////////////

  /**********************************************************************
   * Constructor
   */

  NumObsStatCalc(const bool debug_flag = false,
		 const bool check_z_levels = true);
  

  /**********************************************************************
   * Destructor
   */

  virtual ~NumObsStatCalc(void);
  

  /////////////////////
  // Utility methods //
  /////////////////////

  /**********************************************************************
   * calcStatistic() - Calculate the statistic field using the given
   *                   information.
   */

  virtual MdvxField *calcStatistic(const DsMdvx &climo_file,
				   const MdvxField &data_field,
				   const DateTime &climo_time);
  

  /**********************************************************************
   * getStatName() - Return the name for this statistic.
   */

  virtual string getStatName(const string field_name = "")
  {
    return StatNamer::getStatFieldName(Mdvx::CLIMO_TYPE_NUM_OBS,
				       field_name);
  }
  

protected:
  
  ///////////////////////
  // Protected members //
  ///////////////////////


  ///////////////////////
  // Protected methods //
  ///////////////////////

  /*********************************************************************
   * _createField() - Create a new num obs climatology field from the
   *                  given data field.
   *
   * Return the newly created field on success, 0 on failure.
   */

  MdvxField *_createField(const MdvxField &data_field,
			  const DateTime &climo_time) const;
  

  /*********************************************************************
   * _getStatFieldName() - Gets the field name for this statistic.
   */

  virtual string _getStatFieldName(const string &data_field_name) const
  {
    return StatNamer::getStatFieldName(Mdvx::CLIMO_TYPE_NUM_OBS,
				       data_field_name);
  }


  /*********************************************************************
   * _meetsCondition() - Checks condition for this counter statistic.
   *
   * Returns true if the data point meets the condition set for this
   * statistic, false otherwise.
   */

  virtual bool _meetsCondition(const double data_value) const
  {
    return true;
  }


  /*********************************************************************
   * _updateField() - Create a new num obs climatology field that is an
   *                  update of the current num obs field using the given
   *                  information.
   *
   * Return the newly created field on success, 0 on failure.
   */

  MdvxField *_updateField(const DsMdvx &climo_file,
			  const MdvxField &data_field,
			  const MdvxField &curr_num_obs_field) const;
  

};


#endif
