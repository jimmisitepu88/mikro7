#include <Arduino.h>
#include <mikro7.h>

#if ARDUINO_VERSION <= 106
    // "yield" is not implemented as noop in older Arduino Core releases, so let's define it.
    // See also: https://stackoverflow.com/questions/34497758/what-is-the-secret-of-the-arduino-yieldfunction/34498165#34498165
    void yield(void) {};
#endif

mikro7::mikro7(byte Data, byte Latch, byte Clock){
    begin(Data, Latch, Clock);
}

mikro7::mikro7(){
}
mikro7::~mikro7(){
}

void mikro7::begin(byte Data, byte Latch, byte Clock){
    DATA = Data;
    LATCH = Latch;
    CLOCK = Clock;
    pinMode(DATA, OUTPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLOCK, OUTPUT);
}
void mikro7::display(uint16_t POS1, bool flag){ 
	dt_temp = POS1;
	if(flag == DOT){
		bit_flag = 0b10000000;
	}
	else {
		bit_flag = 0b00000000;
	}
	
    satuan_POS1 = dt_temp%10;
    puluhan_POS1 = (dt_temp/10)%10;
    ratusan_POS1 = (dt_temp/100)%10;
    ribuan_POS1 = (dt_temp/1000)%10;
    puluhanRibu_POS1 = (dt_temp/10000)%10;
    ratusanRibu_POS1 = (dt_temp/100000)%10;
	
	digitalWrite(LATCH, LOW);  //LATCH_0;
  if (POS1 < 10){
        shiftOut(DATA, CLOCK,MSBFIRST,decDigits[satuan_POS1]);
	if ( flag == DOT ){
		shiftOut(DATA, CLOCK,MSBFIRST,decDigits[0]^bit_flag);
	}else shiftOut(DATA, CLOCK,MSBFIRST,0x00^bit_flag);
		shiftOut(DATA, CLOCK,MSBFIRST,0x00);
		shiftOut(DATA, CLOCK,MSBFIRST,0x00);
  }

  if (POS1 < 100 && POS1 >= 10){
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[satuan_POS1]);
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[puluhan_POS1]^bit_flag);
    shiftOut(DATA, CLOCK,MSBFIRST,0x00);
    shiftOut(DATA, CLOCK,MSBFIRST,0x00);
  }

  if (POS1 < 1000 && POS1 >= 100){
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[satuan_POS1]);
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[puluhan_POS1]^bit_flag);
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[ratusan_POS1]);
    shiftOut(DATA, CLOCK,MSBFIRST,0x00);
  }

  if (POS1 < 10000 && POS1 >= 1000){
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[satuan_POS1]);
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[puluhan_POS1]^bit_flag);
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[ratusan_POS1]);
    shiftOut(DATA, CLOCK,MSBFIRST,decDigits[ribuan_POS1]);
  }

    digitalWrite(LATCH, HIGH);//LATCH_1;


}

void mikro7::off(){
  digitalWrite(LATCH, LOW);//LATCH_0;

  shiftOut(DATA, CLOCK,MSBFIRST,0xff);
  shiftOut(DATA, CLOCK,MSBFIRST,0xff);
  shiftOut(DATA, CLOCK,MSBFIRST,0xff);
  shiftOut(DATA, CLOCK,MSBFIRST,0xff);

  digitalWrite(LATCH, HIGH);//LATCH_1;
}

void mikro7::on(){
  digitalWrite(LATCH, LOW);//LATCH_0;
  shiftOut(DATA, CLOCK,MSBFIRST,0x00);
  shiftOut(DATA, CLOCK,MSBFIRST,0x00);
  shiftOut(DATA, CLOCK,MSBFIRST,0x00);
  shiftOut(DATA, CLOCK,MSBFIRST,0x00);
  digitalWrite(LATCH, HIGH);//LATCH_1;
}
void mikro7::test(){
	for ( check_all = 0; check_all < 10; check_all++){
	  digitalWrite(LATCH, LOW);//LATCH_0;
	  shiftOut(DATA, CLOCK,MSBFIRST,decDigits[check_all]);
	  shiftOut(DATA, CLOCK,MSBFIRST,decDigits[check_all]);
	  shiftOut(DATA, CLOCK,MSBFIRST,decDigits[check_all]);
	  shiftOut(DATA, CLOCK,MSBFIRST,decDigits[check_all]);
	  digitalWrite(LATCH, HIGH);//LATCH_1;	
	  delay(500);
	}
}
