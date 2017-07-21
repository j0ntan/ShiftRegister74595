#include <utility/ShiftRegisterEnable.h>
#include <Arduino.h>

namespace {
    using ShiftReg595::pin;
    void
    setPinModes(const pin& serial, const pin& shiftCLK,
            const pin& storageCLK, const pin& outEn) {
        pinMode(serial, OUTPUT);
        pinMode(shiftCLK, OUTPUT);
        pinMode(storageCLK, OUTPUT);
        pinMode(outEn, OUTPUT);
    }
}

namespace ShiftReg595 {
    OutputEnable::OutputEnable(pin outputEnable)
            : OutEn_(outputEnable) {}

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
        setPinModes(SER_, SRCLK_, RCLK_, OutEn_);
        outputAllOff();
        enableOutput();
    }
    ShiftRegisterEnable::~ShiftRegisterEnable() {}

    void
    ShiftRegisterEnable::enableOutput() const {
        OutEn_.enableOutput();
    }
    void
    ShiftRegisterEnable::disableOutput() const {
        OutEn_.disableOutput();
    }
}
