#ifndef SHIFTREGISTERENABLE_H
#define SHIFTREGISTERENABLE_H

#include <utility/ShiftRegisterBase.h>

namespace ShiftReg595 {
    class OutputEnable {
    public:
        OutputEnable(pin outputEnable);

        void enableOutput() const;
        void disableOutput() const;

        operator pin() const;

    private:
        const pin OutEn_;
    };

    class ShiftRegisterEnable : public ShiftRegisterBase {
    public:
        ShiftRegisterEnable(pin serial, pin storageCLK,
                pin shiftCLK, pin outputEnable);
        virtual ~ShiftRegisterEnable();

        void enableOutput() const;
        void disableOutput() const;

    private:
        const OutputEnable OutEn_;
    };
}
#endif
