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
    SRClear::SRClear(pin shiftRegisterClear) 
            : SRCLR_(shiftRegisterClear) {}

    void
    SRClear::clearShiftRegisters(milliseconds period_SRCLK) const {
        // signal is active low
        pinMode(SRCLR_, 0);
        delay(period_SRCLK);
        pinMode(SRCLR_, 1);
        delay(period_SRCLK);
    }

    SRClear::operator pin() const {
        return SRCLR_;
    }

    ShiftRegisterClear::ShiftRegisterClear(pin serial, pin storageCLK,
            pin shiftCLK, pin serialClear) : SRCLR_(serialClear),
            ShiftRegisterBase(serial, storageCLK, shiftCLK) {
        setPinModes(SER_, SRCLK_, RCLK_, SRCLR_);
        outputAllOff();
    }
    ShiftRegisterClear::~ShiftRegisterClear() {}

    void
    ShiftRegisterClear::clearShiftRegisters() const {
        SRCLR_.clearShiftRegisters(period_SRCLK);
    }
    void
    ShiftRegisterClear::outputAllOff() const {
        // override inherited, faster with SRCLR
        SRCLR_.clearShiftRegisters(period_SRCLK);
        ticRCLK();
    }
}
