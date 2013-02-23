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

#ifndef FrSky_h
#define FrSky_h

#define FRSKY_MSG_LENGTH 9                // Frame length without leading and trailing 0x7E
#define FRSKY_MSG_ID_VOLTAGE_LINK 0xFE    // A1 and A2 voltage, up- and downlink RSSI

class FrSky {
  public:
    FrSky();
    char update(char c,char* msg);
    unsigned char getRX_a1();
    unsigned char getRX_a2();
    unsigned char getLink_up();
    unsigned char getLink_dn();
  private:
    void handle_message(char* msg);
    char parse_char(char c,char* msg);
    char frsky_msg[FRSKY_MSG_LENGTH+2];
    unsigned char _rx_a1;
    unsigned char _rx_a2;
    unsigned char _link_up;
    unsigned char _link_dn;
};
#endif