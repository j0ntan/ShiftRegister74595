#include <ShiftRegister74595.h>
#include <Arduino.h>

namespace {
    using ShiftReg595::pin;
    void
    setPinModes(const pin& serial, const pin& shiftCLK,
            const pin& storageCLK, const pin& outEn, const pin& shiftClear) {
        pinMode(serial, OUTPUT);
        pinMode(shiftCLK, OUTPUT);
        pinMode(storageCLK, OUTPUT);
        pinMode(outEn, OUTPUT);
        pinMode(shiftClear, OUTPUT);
    }
}

namespace ShiftReg595 {
    ShiftRegister::ShiftRegister(pin serial, pin storageCLK,
            pin shiftCLK, pin outputEnable, pin serialClear)  : 
            OutEn_(outputEnable), SRCLR_(serialClear),
            ShiftRegisterBase(serial, storageCLK, shiftCLK) {
        setPinModes(SER_, SRCLK_, RCLK_, OutEn_, SRCLR_);
        outputAllOff();
        enableOutput();
    }

    void
    ShiftRegister::enableOutput() const {
        OutEn_.enableOutput();
    }
    void
    ShiftRegister::disableOutput() const {
        OutEn_.disableOutput();
    }

    void
    ShiftRegister::clearShiftRegisters() const {
        SRCLR_.clearShiftRegisters(period_SRCLK);
    }
    void
    ShiftRegister::outputAllOff() const {
        // override inherited, faster with SRCLR
        SRCLR_.clearShiftRegisters(period_SRCLK);
        ticRCLK();
    }
}
