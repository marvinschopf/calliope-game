#include "CalliopeSettings.h"
#include "MicroBit.h"
#include "nrf_delay.h"
#include "nrf_gpio.h"

#ifdef CALLIOPE_MINIGAME

MicroBit uBit;

// Define images / Copyright by (C) calliope
const uint8_t full[25] = {1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1,
                          1, 1, 1, 1, 1
};
const uint8_t dot[25] = {0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0,
                         0, 0, 1, 0, 0,
                         0, 0, 0, 0, 0,
                         0, 0, 0, 0, 0
};
const uint8_t small[25] = {0, 0, 0, 0, 0,
                           0, 1, 1, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 0, 0, 0, 0
};
const uint8_t large[25] = {1, 1, 1, 1, 1,
                           1, 0, 0, 0, 1,
                           1, 0, 0, 0, 1,
                           1, 0, 0, 0, 1,
                           1, 1, 1, 1, 1,
};
const uint8_t arrow_left[25] = {0, 0, 1, 0, 0,
                                0, 1, 0, 0, 0,
                                1, 1, 1, 1, 1,
                                0, 1, 0, 0, 0,
                                0, 0, 1, 0, 0
};
const uint8_t arrow_right[25] = {0, 0, 1, 0, 0,
                                 0, 0, 0, 1, 0,
                                 1, 1, 1, 1, 1,
                                 0, 0, 0, 1, 0,
                                 0, 0, 1, 0, 0
};
const uint8_t arrow_leftright[25] = {0, 0, 1, 0, 0,
                                     0, 1, 0, 1, 0,
                                     1, 0, 0, 0, 1,
                                     0, 1, 0, 1, 0,
                                     0, 0, 1, 0, 0
};
const uint8_t double_row[25] = {0, 1, 1, 0, 0,
                                0, 1, 1, 0, 0,
                                0, 1, 1, 0, 0,
                                0, 1, 1, 0, 0,
                                0, 1, 1, 0, 0
};
const uint8_t tick[25] = {0, 0, 0, 0, 0,
                          0, 0, 0, 0, 1,
                          0, 0, 0, 1, 0,
                          1, 0, 1, 0, 0,
                          0, 1, 0, 0, 0
};
const uint8_t heart[25] = {0, 1, 0, 1, 0,
                           1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1,
                           0, 1, 1, 1, 0,
                           0, 0, 1, 0, 0
};
const uint8_t smiley[25] = {0, 1, 0, 1, 0,
                            0, 1, 0, 1, 0,
                            0, 0, 0, 0, 0,
                            1, 0, 0, 0, 1,
                            0, 1, 1, 1, 0
};
const uint8_t sadly[25] = {0, 1, 0, 1, 0,
                           0, 1, 0, 1, 0,
                           0, 0, 0, 0, 0,
                           0, 1, 1, 1, 0,
                           1, 0, 0, 0, 1
};
const uint8_t rock[25] = {0, 0, 0, 0, 0,
                          0, 1, 1, 1, 0,
                          0, 1, 1, 1, 0,
                          0, 1, 1, 1, 0,
                          0, 0, 0, 0, 0
};
const uint8_t scissors[25] = {1, 0, 0, 0, 1,
                              0, 1, 0, 1, 0,
                              0, 0, 1, 0, 0,
                              0, 1, 0, 1, 0,
                              1, 0, 0, 0, 1
};
const uint8_t well[25] = {0, 1, 1, 1, 0,
                          1, 0, 0, 0, 1,
                          1, 0, 0, 0, 1,
                          1, 0, 0, 0, 1,
                          0, 1, 1, 1, 0
};
const uint8_t flash[25] = {0, 0, 1, 1, 0,
                           0, 1, 1, 0, 0,
                           1, 1, 1, 1, 1,
                           0, 0, 1, 1, 0,
                           0, 1, 1, 0, 0,

};
const uint8_t wave[7 * 5] = {0, 0, 0, 0, 0, 0, 0,
                             0, 1, 1, 0, 0, 0, 0,
                             1, 0, 0, 1, 0, 0, 1,
                             0, 0, 0, 0, 1, 1, 0,
                             0, 0, 0, 0, 0, 0, 0
};




const MicroBitImage Full(5, 5, full);
const MicroBitImage Dot(5, 5, dot);
const MicroBitImage SmallRect(5, 5, small);
const MicroBitImage LargeRect(5, 5, large);
const MicroBitImage ArrowLeft(5, 5, arrow_left);
const MicroBitImage ArrowRight(5, 5, arrow_right);
const MicroBitImage ArrowLeftRight(5, 5, arrow_leftright);
const MicroBitImage DoubleRow(5, 5, double_row);
const MicroBitImage Tick(5, 5, tick);
const MicroBitImage Heart(5, 5, heart);
const MicroBitImage Smiley(5, 5, smiley);
const MicroBitImage Sadly(5, 5, sadly);
const MicroBitImage Rock(5, 5, rock);
const MicroBitImage Scissors(5, 5, scissors);
const MicroBitImage Well(5, 5, well);
const MicroBitImage Flash(5, 5, flash);
const MicroBitImage Wave(7, 5, wave);


// end images / copyright (C) by calliope

void leaveBeep() {
    uBit.soundmotor.soundOn(784);
    uBit.sleep(125);
    uBit.soundmotor.soundOff();
}

void dadadaSound() {
    for (int i = 0; i < 3; i++) {
        uBit.soundmotor.soundOn(392);
        fiber_sleep(125);
        uBit.soundmotor.soundOff();
        fiber_sleep(63);
    }
    uBit.soundmotor.soundOn(311);
    fiber_sleep(1500);
    uBit.soundmotor.soundOff();
    fiber_sleep(63);
    for (int i = 0; i < 3; i++) {
        uBit.soundmotor.soundOn(349);
        fiber_sleep(125);
        uBit.soundmotor.soundOff();
        fiber_sleep(63);
    }
    uBit.soundmotor.soundOn(294);
    fiber_sleep(1500);
    uBit.soundmotor.soundOff();
}

void startSound() {
    uBit.soundmotor.soundOn(262);
    fiber_sleep(125);
    uBit.soundmotor.soundOff();
    fiber_sleep(63);
    uBit.soundmotor.soundOn(784);
    fiber_sleep(500);
    uBit.soundmotor.soundOff();
}

void showImage(MicroBitImage img) {
	uBit.display.print(img);
}

void showMnet() {
	const uint8_t m_mnet[25] = {1, 0, 0, 0, 1,
	     						1, 1, 0, 1, 1,
	     						1, 0, 1, 0, 1,
	     						1, 0, 0, 0, 1,
	     						1, 0, 0, 0, 1

	};

	const uint8_t s_mnet[25] = {0, 1, 1, 1, 0,
						   	   1, 0, 0, 0, 0,
						   	   0, 1, 1, 0, 0,
						   	   0, 0, 0, 1, 0,
						   	   0, 1, 1, 1, 0,

	};

	const MicroBitImage M_Mnet(5, 5, m_mnet);
	const MicroBitImage S_Mnet(5, 5, s_mnet);

	showImage(M_Mnet);
	uBit.sleep(1100);
	showImage(S_Mnet);
}

void blinkImage(MicroBitImage img, int times, int delay) {
	for(int a = 0; a < times; a = a + 1) {
		showImage(img);
		uBit.sleep(delay);
		uBit.display.clear();
		uBit.sleep(delay);
	}
}

void mainGame() {
	showMnet();
	dadadaSound();
	startSound();
	showImage(Smiley);
	uBit.sleep(1500);
	uBit.display.clear();

	blinkImage(Tick, 3, 500);

	uBit.sleep(1000);
	uBit.display.scroll("READY? STEADY? GO!");
	startSound();

	// done with intro

	while(! uBit.buttonA.isPressed()) {
		showImage(ArrowLeft);
		//blinkImage(ArrowLeft, 1, 500);
	}

	leaveBeep();
	
	blinkImage(Tick, 4, 500);

	while(! uBit.buttonB.isPressed()) {
		showImage(ArrowRight);
	}

	leaveBeep();

	blinkImage(Tick, 4, 500);







}

int main() {
	mainGame();
}

#endif
