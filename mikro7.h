#ifndef mikro7_h
#define mikro7_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define DOT 0
#define NOT 1	

class mikro7
{
    private:
    byte DATA;
    byte LATCH;
    byte CLOCK;
	uint8_t bit_flag;

	uint8_t decDigits[10] = {0b11101110,0b10001000,0b11000111,0b11001101,0b10101001,0b01101101,0b01101111,0b11001000,0b11101111,0b11101101};
    uint16_t dt_temp;
    uint8_t satuan_POS1, puluhan_POS1, ratusan_POS1, ribuan_POS1, puluhanRibu_POS1,ratusanRibu_POS1;
	
    
    public:
    mikro7(byte Data, byte Latch, byte Clock);
	mikro7();
	virtual ~mikro7();
    void begin(byte Data, byte Latch, byte Clock);
    void display(uint16_t POS1, bool flag);
    void off();
	void on();
};

#endif