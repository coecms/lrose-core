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
//////////////////////////////////////////////////////////////////////
// $Id: EndEOVStrategy.cc,v 1.2 2016/03/06 23:53:40 dixon Exp $
//
/////////////////////////////////////////////////////////////////////

#include "EndEOVStrategy.hh"
using namespace std;


EndEOVStrategy::EndEOVStrategy(const double end_elevation,
			       const ScanStrategy &scan_strategy) :
  EOVStrategy(),
  _endElevation(scan_strategy.getElevation(end_elevation)),
  _scanStrategy(scan_strategy),
  _prevElevation(-1.0)
{
}

EndEOVStrategy::~EndEOVStrategy() 
{
}

bool EndEOVStrategy::isEndOfVolume(double elevation) 
{
  bool return_value = false;
  
  // Get the elevation of the tilt

  double tilt_elevation = _scanStrategy.getElevation(elevation);
  
  // Get through the first volume before triggering a volume change

  if (_prevElevation != -1.0 &&
      tilt_elevation != _prevElevation &&
      _prevElevation == _endElevation)
    return_value = true;
  
  _prevElevation = tilt_elevation;
  
  return return_value;
}
