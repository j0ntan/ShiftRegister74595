#include <utility/ShiftRegisterBase.h>
#include <Arduino.h>

namespace {
    using SR595::pin;
    void
    setPinModes(const pin& serial, const pin& storageCLK, const pin& shiftCLK) {
        pinMode(serial, OUTPUT);
        pinMode(storageCLK, OUTPUT);
        pinMode(shiftCLK, OUTPUT);
    }
}

namespace SR595 {
    ShiftRegisterBase::ShiftRegisterBase(pin serial, pin storageCLK, pin shiftCLK) :
            SER_(serial), RCLK_(storageCLK), SRCLK_(shiftCLK) {
                setPinModes(serial, storageCLK, shiftCLK);
    }
    
    void
    ShiftRegisterBase::setSerial(BIT serialBit) const {
        digitalWrite(SER_, static_cast<bool>(serialBit));
    }
    void
    ShiftRegisterBase::ticSRCLK() const {
        digitalWrite(SRCLK_, 1);
        delay(period_SRCLK);
        digitalWrite(SRCLK_, 0);
        delay(period_SRCLK);
    }
    void
    ShiftRegisterBase::ticRCLK() const {
        digitalWrite(RCLK_, 1);
        delay(period_RCLK);
        digitalWrite(RCLK_, 0);
        delay(period_RCLK);
    }

    void
    ShiftRegisterBase::setPeriodSRCLK(const milliseconds& ms) {
        period_SRCLK = ms;
    }
    void
    ShiftRegisterBase::setPeriodRCLK(const milliseconds& ms) {
        period_RCLK = ms;
    }

    void
    ShiftRegisterBase::shiftBit(BIT bit) const {
        setSerial(bit);
        ticSRCLK();
    }
    void
    ShiftRegisterBase::shiftNBits(byte b, num N) const {
        // bits are big endian, B0,...,B7
        for(num i=0; i<N; ++i)
            shiftBit(static_cast<BIT>( b>>i & B00000001 ));
    }
    void
    ShiftRegisterBase::shiftByte(byte b) const {
        shiftNBits(b, 8);
    }
    void
    ShiftRegisterBase::shiftAllOn() const {
        shiftByte(B11111111);
    }
    void
    ShiftRegisterBase::shiftAllOff() const {
        shiftByte(B00000000);
    }
    
    void
    ShiftRegisterBase::outputBit(BIT bit) const {
        shiftBit(bit);
        ticRCLK();
    }
    void
    ShiftRegisterBase::outputNBits(byte b, num N) const {
        shiftNBits(b, N);
        ticRCLK();
    }
    void
    ShiftRegisterBase::outputByte(byte b) const {
        shiftByte(b);
        ticRCLK();
    }
    void
    ShiftRegisterBase::outputAllOn() const {
        shiftAllOn();
        ticRCLK();
    }
    void
    ShiftRegisterBase::outputAllOff() const {
        shiftAllOff();
        ticRCLK();
    }

    void
    ShiftRegisterBase::updateOutput() const {
        ticRCLK();
    }
}
