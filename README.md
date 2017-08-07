Shift Register -595
===================
The -595 integrated circuit (IC) series is a [Serial-in Parallel-out (SIPO) shift register](https://en.wikipedia.org/wiki/Shift_register#Serial-in_parallel-out_.28SIPO.29) that allows the conversion of an 8-bit serial input stream to a parallel ouptut. The [74HC595](http://www.ti.com/lit/ds/symlink/sn74hc595.pdf) IC is commonly used to add  outputs to an Arduino that is usually limited in I/O pins. Additional functionalty is provided with a global clear control and an enable/disable control of the tri-state output.

Basic Usage
===========
The 74HC595 is composed of two individual registers, an internal buffer register and a latched output register, each with their own clock. An input stream can be clocked in and shifted into the buffer register. A clock pulse can then load the buffer into the latched output register and update the output pins.

Operating Modes
---------------
In addition to the basic shift register functionality, the 74HC595 allows the user to clear the internal buffer and also to enable or disable the output. Some applications do not require the use of these features. In those cases, we want to prevent accidentally calling the functions that use those features. Doing so results in a compilation error. This is accomplished by providing several operating modes for the shift register, according to the features available in that mode.

* `ShiftRegister` - Full funtionality is available.
* `ShiftRegisterBase` - Only the basic input/output methods can be used.
* `ShiftRegisterClear` - The basic methods can be used and the function `clearShiftRegisters` clears the internal buffer.
* `ShiftRegisterEnable` - The basic methods can be used and the functions `enableOutput` and  `disableOutput` change the output state.

Input Methods
-------------
This library facilitates inputting data and controlling the shift register outputs. Several methods of input are provided to load an input stream into either the internal buffer or into the output storage registers.

Two versions of the input methods are provided so that the buffer register can be set individually from the output register. An input stream can be shited into the buffer by calling the `shift-` functions. The output registers can take in those values at a later time with a clock pulse. If desired, both of these steps can be done as a single call using the `ouptut-` functions. A function pair exists for each type of input method.

* Single Bit - A single `BIT::HI` or `BIT::LO` can be shifted into the registers.
* Byte - A byte will replace the entire buffer register and change all output pins.
* Selected Bits - A selected number of bits is taken from a passed byte and are shifted into the buffer registers.
* Global Set - Set all outputs to ON state/Vcc.
* Global Clear - Set all output to OFF state/GND.

**NOTE:** Refer to the examples to see usage of the input methods.
