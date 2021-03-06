/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"
#include "PinConfigured.h"

#ifdef __cplusplus
extern "C" {
#endif


void pinMode(uint32_t ulPin, uint32_t ulMode)
{
    PinName p = DIGITAL_TO_PINNAME(ulPin);
    switch(ulMode) {
        case INPUT:
            pin_function(p, GD_PIN_FUNCTION3(PIN_MODE_IN_FLOATING, 0, 0));
            break;
        case INPUT_PULLUP:
            pin_function(p, GD_PIN_FUNCTION3(PIN_MODE_IPU, 0, 0));
            break;
        case INPUT_PULLDOWN:
            pin_function(p, GD_PIN_FUNCTION3(PIN_MODE_IPD, 0, 0));
            break;
        case INPUT_ANALOG:
            pin_function(p, GD_PIN_FUNCTION3(PIN_MODE_AIN, 0, 0));
            break;
        case OUTPUT:
            pin_function(p, GD_PIN_FUNCTION3(PIN_MODE_OUT_PP, 0, 0));
            break;
        case OUTPUT_OPEN_DRAIN:
            pin_function(p, GD_PIN_FUNCTION3(PIN_MODE_OUT_OD, 0, 0));
            break;
        default:
            //Error_Handler();
            break;
    }
}

void digitalWrite(uint32_t ulPin, uint32_t ulVal)
{
    PinName pinname = DIGITAL_TO_PINNAME(ulPin);
    uint32_t pin =  gpio_pin[GD_PIN_GET(pinname)];
    uint32_t port = gpio_port[GD_PORT_GET(pinname)];
    gpio_bit_write(port, pin, (bit_status)ulVal);
}

int digitalRead(uint32_t ulPin)
{
    PinName pinname = DIGITAL_TO_PINNAME(ulPin);
    uint32_t pin =  gpio_pin[GD_PIN_GET(pinname)];
    uint32_t port = gpio_port[GD_PORT_GET(pinname)];
    return (int)gpio_input_bit_get(port, pin);
}

void digitalToggle(uint32_t ulPin)
{
    PinName pinname = DIGITAL_TO_PINNAME(ulPin);
    uint32_t pin =  gpio_pin[GD_PIN_GET(pinname)];
    uint32_t port = gpio_port[GD_PORT_GET(pinname)];
    gpio_bit_write(port, pin, (bit_status)(1 - (int)gpio_input_bit_get(port, pin)));
}

#ifdef __cplusplus
}
#endif

