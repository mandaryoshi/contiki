/*
 * Copyright (c) 2017, Copyright Robert Olsson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the Contiki operating system.
 *
 *
 * Author  : Robert Olsson
 * Created : 2017-08-05
 * Updated : $Date: 2010/01/14 20:23:02 $
 *           $Revision: 1.2 $
 */

/* Only on rev 2.4 boards */

#include <avr/pgmspace.h>
#include "lib/sensors.h"
#include "core/dev/button-sensor.h"
#include "rss2.h"

const struct sensors_sensor button_sensor;
static int status(int type);

void
test_button(void)
{
  if( ! button_sensor.value(0) ) {
      sensors_changed(&button_sensor);
    }
}

static int
value(int type)
{
  return PINB & (1 << BUTTON);
}
static int
configure(int type, int c)
{
  DDRB &= ~(1 << BUTTON);
  return 0;
}
static int
status(int type)
{
  return 0;
}
SENSORS_SENSOR(button_sensor, BUTTON_SENSOR,
               value, configure, status);

//SENSORS(&button_sensor);
