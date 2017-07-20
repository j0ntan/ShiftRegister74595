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
    ShiftRegisterEnable::ShiftRegisterEnable(pin serial, pin storageCLK,
            pin shiftCLK, pin outputEnable) : OutEn_(outputEnable),
            ShiftRegisterBase(serial, storageCLK, shiftCLK) {
        setPinModes(SER_, SRCLK_, RCLK_, OutEn_);
        outputAllOff();
    }
    ShiftRegisterEnable::~ShiftRegisterEnable() {}

    void
    ShiftRegisterEnable::enableOutput() const {
        // signal is active low
        digitalWrite(OutEn_, 0);
    }
    void
    ShiftRegisterEnable::disableOutput() const {
        digitalWrite(OutEn_, 1);
    }
}
