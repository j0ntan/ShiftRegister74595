#include <utility/ShiftRegisterClear.h>
#include <Arduino.h>

namespace {
    using ShiftReg595::pin;
    void
    setPinModes(const pin& serial, const pin& shiftCLK,
            const pin& storageCLK, const pin& shiftClear) {
        pinMode(serial, OUTPUT);
        pinMode(shiftCLK, OUTPUT);
        pinMode(storageCLK, OUTPUT);
        pinMode(shiftClear, OUTPUT);
    }
}

namespace ShiftReg595 {
    ShiftRegisterClear::ShiftRegisterClear(pin serial, pin storageCLK,
            pin shiftCLK, pin serialClear) : SRCLR_(serialClear),
            ShiftRegisterBase(serial, storageCLK, shiftCLK) {
        setPinModes(SER_, SRCLK_, RCLK_, SRCLR_);
        outputAllOff();
    }
    ShiftRegisterClear::~ShiftRegisterClear() {}

    void
    ShiftRegisterClear::clearShiftRegisters() {
        // signal is active low
        pinMode(SRCLR_, 0);
        delay(period_SRCLK);
        pinMode(SRCLR_, 1);
        delay(period_SRCLK);
    }
    void
    ShiftRegisterClear::outputAllOff() {
        // override inherited, faster with SRCLR
        clearShiftRegisters();
        ticRCLK();
    }
}
