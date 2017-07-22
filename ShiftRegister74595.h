#ifndef SHIFTREGISTER74595_H
#define SHIFTREGISTER74595_H

#include <utility/ShiftRegisterBase.h>
#include <utility/ShiftRegisterEnable.h>
#include <utility/ShiftRegisterClear.h>

namespace ShiftReg595 {
    class ShiftRegister : public ShiftRegisterBase{
    public:
        ShiftRegister(pin serial, pin storageCLK,
                pin shiftCLK, pin outputEnable, pin serialClear);

        void enableOutput() const;
        void disableOutput() const;

        void clearShiftRegisters() const;
        void outputAllOff() const;

    private:
        const OutputEnable OutEn_;
        const SRClear SRCLR_;
    };
}

#endif
