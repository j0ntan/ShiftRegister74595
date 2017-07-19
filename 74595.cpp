#include <74595.h>
#include <Arduino.h>

namespace ShiftReg595 {
    void
    setPinModes(const pin& serial, const pin& storageCLK, const pin& shiftCLK) {
        pinMode(serial, OUTPUT);
        pinMode(storageCLK, OUTPUT);
        pinMode(shiftCLK, OUTPUT);
    }
    
    ShiftRegBase::ShiftRegBase(pin serial, pin storageCLK, pin shiftCLK) :
            SER_(serial), RCLK_(storageCLK), SRCLK_(shiftCLK) {
                setPinModes(serial, storageCLK, shiftCLK);
    }
    
    void
    ShiftRegBase::setSerial(BIT serialBit) const {
        digitalWrite(SER_, static_cast<bool>(serialBit));
    }
    void
    ShiftRegBase::ticSRCLK() const {
        digitalWrite(SRCLK_, 1);
        delay(period_SRCLK);
        digitalWrite(SRCLK_, 0);
        delay(period_SRCLK);
    }
    void
    ShiftRegBase::ticRCLK() const {
        digitalWrite(RCLK_, 1);
        delay(period_RCLK);
        digitalWrite(RCLK_, 0);
        delay(period_RCLK);
    }

    void
    ShiftRegBase::setPeriodSRCLK(const milliseconds& ms) {
        period_SRCLK = ms;
    }
    void
    ShiftRegBase::setPeriodRCLK(const milliseconds& ms) {
        period_RCLK = ms;
    }

    void
    ShiftRegBase::shiftBit(BIT bit) const {
        setSerial(bit);
        ticSRCLK();
    }
    void
    ShiftRegBase::shiftNBits(byte b, num N) const {
        // bits are big endian, B0,...,B7
        for(num i=0; i<N; ++i)
            shiftBit(static_cast<BIT>( b>>i & B00000001 ));
    }
    void
    ShiftRegBase::shiftByte(byte b) const {
        shiftNBits(b, 8);
    }
    void
    ShiftRegBase::shiftAllOn() const {
        shiftByte(B11111111);
    }
    void
    ShiftRegBase::shiftAllOff() const {
        shiftByte(B00000000);
    }
    
    void
    ShiftRegBase::outputBit(BIT bit) const {
        shiftBit(bit);
        ticRCLK();
    }
    void
    ShiftRegBase::outputNBits(byte b, num N) const {
        shiftNBits(b, N);
        ticRCLK();
    }
    void
    ShiftRegBase::outputByte(byte b) const {
        shiftByte(b);
        ticRCLK();
    }
    void
    ShiftRegBase::outputAllOn() const {
        shiftAllOn();
        ticRCLK();
    }
    void
    ShiftRegBase::outputAllOff() const {
        shiftAllOff();
        ticRCLK();
    }
}
