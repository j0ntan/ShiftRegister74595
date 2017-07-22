#include <utility/ShiftRegisterClear.h>
#include <Arduino.h>

namespace SR595 {
    SRClear::SRClear(pin shiftRegisterClear) 
            : SRCLR_(shiftRegisterClear) {
        pinMode(shiftRegisterClear, OUTPUT);
    }

    void
    SRClear::clearShiftRegisters(milliseconds period_SRCLK) const {
        // signal is active low
        digitalWrite(SRCLR_, 0);
        delay(period_SRCLK);
        digitalWrite(SRCLR_, 1);
        delay(period_SRCLK);
    }

    SRClear::operator pin() const {
        return SRCLR_;
    }

    ShiftRegisterClear::ShiftRegisterClear(pin serial, pin storageCLK,
            pin shiftCLK, pin serialClear) : SRCLR_(serialClear),
            ShiftRegisterBase(serial, storageCLK, shiftCLK) {
        outputAllOff();
    }

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
