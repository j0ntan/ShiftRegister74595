#include <utility/ShiftRegisterEnable.h>
#include <Arduino.h>

namespace ShiftReg595 {
    OutputEnable::OutputEnable(pin outputEnable)
            : OutEn_(outputEnable) {
        pinMode(outputEnable, OUTPUT);
    }

    void
    OutputEnable::enableOutput() const {
        // signal is active low
        digitalWrite(OutEn_, 0);
    }
    void
    OutputEnable::disableOutput() const {
        digitalWrite(OutEn_, 1);
    }

    OutputEnable::operator pin () const {
        return OutEn_;
    }


    ShiftRegisterEnable::ShiftRegisterEnable(pin serial, pin storageCLK,
            pin shiftCLK, pin outputEnable) : OutEn_(outputEnable),
            ShiftRegisterBase(serial, storageCLK, shiftCLK) {
        outputAllOff();
        enableOutput();
    }

    void
    ShiftRegisterEnable::enableOutput() const {
        OutEn_.enableOutput();
    }
    void
    ShiftRegisterEnable::disableOutput() const {
        OutEn_.disableOutput();
    }
}
