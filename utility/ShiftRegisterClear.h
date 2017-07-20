#ifndef SHIFTREGISTERCLEAR_H
#define SHIFTREGISTERCLEAR_H

#include <utility/ShiftRegisterBase.h>

namespace ShiftReg595 {
    class ShiftRegisterClear : public ShiftRegisterBase {
    public:
        ShiftRegisterClear(pin serial, pin storageCLK,
                pin shiftCLK, pin serialClear);
        virtual ~ShiftRegisterClear();

        void clearShiftRegisters();
        void outputAllOff();
        
    protected:
        const pin SRCLR_;
    };
}
#endif
