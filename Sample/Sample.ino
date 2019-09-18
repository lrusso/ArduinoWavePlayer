#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "SoundData.h"
#define SAMPLE_RATE 8000

// SET HERE THE LENGTH OF YOUR AUDIO WAVE
int SoundDataLength = 12000;

// DO NOT MODIFY
int speakerPin = 45;
volatile uint16_t sample;
byte lastSample;

void stopPlayback()
  {
  TIMSK1 &= ~_BV(OCIE5A);
  TCCR5B &= ~_BV(CS10);
  TCCR5B &= ~_BV(CS10);
  digitalWrite(speakerPin, LOW);
  }

ISR(TIMER1_COMPA_vect)
  {
  if (sample >= SoundDataLength)
    {
    if (sample == SoundDataLength + lastSample)
      {
      stopPlayback();
      }
      else
      {
      OCR5B = SoundDataLength + lastSample - sample;                
      }
    }
    else
    {
    OCR5B = pgm_read_byte(&SoundData[sample]);            
    }
  ++sample;
  }

void setup()
  {
  pinMode(speakerPin, OUTPUT);
  ASSR &= ~(_BV(EXCLK) | _BV(AS2));
  TCCR5B &= ~_BV(WGM52);
  TCCR5A = (TCCR5A | _BV(COM5B1)) & ~_BV(COM5B0);
  TCCR5A &= ~(_BV(COM5A1) | _BV(COM5A0));
  TCCR5B = (TCCR5B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);
  OCR5B = pgm_read_byte(&SoundData[0]);
  cli();
  TCCR1B = (TCCR1B & ~_BV(WGM13)) | _BV(WGM12);
  TCCR1A = TCCR1A & ~(_BV(WGM11) | _BV(WGM10));
  TCCR1B = (TCCR1B & ~(_BV(CS12) | _BV(CS11))) | _BV(CS10);
  OCR1A = F_CPU / SAMPLE_RATE;
  TIMSK1 |= _BV(OCIE1A);
  lastSample = pgm_read_byte(&SoundData[SoundDataLength-1]);
  sample = 0;
  sei();
  }

void loop()
  {
  while (true);
  }
