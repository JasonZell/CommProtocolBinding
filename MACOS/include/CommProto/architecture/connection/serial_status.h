/*
  serial status configuration.

  Copyright (C) 2016  Michael Wallace, Kartik Soni, Mario Garcia.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (At your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __SERIAL_STATUS_H
#define __SERIAL_STATUS_H

#include <CommProto/architecture/os/include_defines.h>
#include <CommProto/architecture/api.h>

/**
Indicate the status of serial connection.
*/
enum serial_status_t {

  SERIAL_OPEN,
  SERIAL_CLOSED,
  SERIAL_CONNECTED,
  SERIAL_TRANSMIT
};

typedef enum serial_status_t serial_status; /** Status of serial connection */
typedef int32_t port_id; /** Port ID for the serial connection */

#if COMMPROTO_TARGET_OS == COMMMPROTO_OS_WINDOWS
 typedef uint32_t speed_t; 
#endif

#endif // __SERIAL_STATUS_H
