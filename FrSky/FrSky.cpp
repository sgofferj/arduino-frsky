//
// Library for decoding FrSky telemetry packages
//
//      Copyright (c) 2013 Stefan Gofferje. All rights reserved.
//
//      This library is free software; you can redistribute it and/or
//      modify it under the terms of the GNU Lesser General Public
//      License as published by the Free Software Foundation; either
//      version 2.1 of the License, or (at your option) any later
//      version.
//
//      This library is distributed in the hope that it will be
//      useful, but WITHOUT ANY WARRANTY; without even the implied
//      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//      PURPOSE.  See the GNU Lesser General Public License for more
//      details.
//
//      You should have received a copy of the GNU Lesser General
//      Public License along with this library; if not, write to the
//      Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
//      Boston, MA 02110-1301 USA
//

#include <FrSky.h>

// ----- Constructor ---------------------------------------------------------
FrSky::FrSky() {
  _rx_a1=0;
  _rx_a2=0;
  _link_up=0;
  _link_dn=0;
}

// ----- Private -------------------------------------------------------------
void FrSky::handle_message(char* msg) {
  switch (msg[0]) {
    case FRSKY_MSG_ID_VOLTAGE_LINK:
    {
      _rx_a1 = msg[1];
      _rx_a2 = msg[2];
      _link_up = msg[3];
      _link_dn = msg[4];
    } 
  }
}

char FrSky::parse_char(char c,char* msg) {
  static char bufferIndex; 
  static bool msgBegin;
  char result = 0;
  if (c == 0x7E)  {
    if (bufferIndex == FRSKY_MSG_LENGTH) {
      bufferIndex = 0;
      result=1;
      msgBegin=false;
    }
    else if ( (bufferIndex > 0) && (bufferIndex < FRSKY_MSG_LENGTH) ) {
      bufferIndex = 0;
      msgBegin=false;
    }
    else {
      msgBegin = true;
    }
  }
  if ( (msgBegin) && (c != 0x7E) ) {
    msg[bufferIndex] = c;
    bufferIndex++;
  }
  return result;  
}

// ----- Public --------------------------------------------------------------
char FrSky::update(char c) {
  char result = 0;
  result=parse_char(c,_frsky_msg);
  if(result) {
    handle_message(_frsky_msg);
  }
  return result;
}

unsigned char FrSky::getRX_a1() {
  unsigned char result = _rx_a1;
  return result;
}

unsigned char FrSky::getRX_a2() {
  unsigned char result = _rx_a2;
  return result;
}

unsigned char FrSky::getLink_up() {
  unsigned char result = _link_up;
  return result;
}

unsigned char FrSky::getLink_dn() {
  unsigned char result = _link_dn;
  return result;
}

