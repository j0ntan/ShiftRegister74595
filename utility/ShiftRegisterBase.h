#ifndef SHIFTREGISTERBASE_H
#define SHIFTREGISTERBASE_H

namespace ShiftReg595 {
    typedef unsigned char pin;
    typedef unsigned char byte;
    typedef unsigned long milliseconds;
    typedef unsigned int num;

    enum class BIT : byte {LO=0, HI=1};

    class ShiftRegisterBase {
    public:
        ShiftRegisterBase(pin serial, pin storageCLK, pin shiftCLK);
        
        // basic shift register functions
        void setSerial(BIT serialBit) const;
        void ticSRCLK() const;
        void ticRCLK() const;

        // config clock periods
        void setPeriodSRCLK(const milliseconds& ms);
        void setPeriodRCLK(const milliseconds& ms);
        
        // more useful shift register functions
        void shiftBit(BIT bit) const;
        void shiftNBits(byte b, num N) const;
        void shiftByte(byte b) const;
        void shiftAllOn() const;
        void shiftAllOff() const;

        // direct to output versions
        void outputBit(BIT bit) const;
        void outputNBits(byte b, num N) const;
        void outputByte(byte b) const;
        void outputAllOn() const;
        void outputAllOff() const;

    protected:
        const pin SER_;
        const pin RCLK_;
        const pin SRCLK_;

        milliseconds period_SRCLK = 5;
        milliseconds period_RCLK = 5;
    };

}
#endif
