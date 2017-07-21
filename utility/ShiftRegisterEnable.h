#ifndef SHIFTREGISTERENABLE_H
#define SHIFTREGISTERENABLE_H

#include <utility/ShiftRegisterBase.h>

namespace ShiftReg595 {
    class OutputEnable {
    public:
    private:
    };

    class ShiftRegisterEnable : public ShiftRegisterBase {
    public:
        ShiftRegisterEnable(pin serial, pin storageCLK,
                pin shiftCLK, pin outputEnable);
        virtual ~ShiftRegisterEnable();

        void enableOutput() const;
        void disableOutput() const;

    protected:
        const pin OutEn_;
    };
}
#endif
