#!/bin/sh
export LD_LIBRARY_PATH="$PWD/lib:$LD_LIBRARY_PATH"
echo $LD_LIBRARY_PATH
./USB_ADC_Test
