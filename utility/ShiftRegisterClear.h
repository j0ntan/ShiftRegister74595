#ifndef SHIFTREGISTERCLEAR_H
#define SHIFTREGISTERCLEAR_H

#include <utility/ShiftRegisterBase.h>

namespace ShiftReg595 {
    class SRClear {
    public:
        SRClear(pin shiftRegisterClear);

        void clearShiftRegisters(milliseconds period_SRCLK) const;

        operator pin() const;

    private:
        const pin SRCLR_;
    };

    class ShiftRegisterClear : public ShiftRegisterBase {
    public:
        ShiftRegisterClear(pin serial, pin storageCLK,
                pin shiftCLK, pin serialClear);
        virtual ~ShiftRegisterClear();

        void clearShiftRegisters() const;
        void outputAllOff() const;
        
    private:
        const SRClear SRCLR_;
    };
}
#endif
