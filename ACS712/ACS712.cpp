#include <Arduino.h>
#include "ACS712.h"
#include <math.h>

// Konstruktor
ACS712::ACS712(void)
{
	m_bit = 512; 	// 10 bit
	m_port = A0;	// A0
	m_v_digi = 37,888; // version
	m_1100_digi = 0;
	m_vcc = 0;
	m_half = 0;
}

long ACS712::Get_adc_digi(){
	long adc_in = analogRead(m_port);
	return adc_in;
}
float ACS712::Get_adc_analog(){
	long adc_in = analogRead(m_port);
	float x = adc_in * m_vcc / 1024;
	return x;
}

	double ACS712::Get_current( uint8_t port,int version){
		long test = 0;
		m_port = port;
		
		if (version == 5){ 	m_v_digi = 37,888; }
		if (version == 20){ m_v_digi = 20.46; }
		if (version == 30){ m_v_digi = 13.5036;	}

		long adc_dig = analogRead(m_port);			
		// nur digi		
		long m_current = (adc_dig & (m_bit-1));
		
		if (adc_dig < m_bit){
			m_current = m_current - m_bit ;
			test = m_current;
		}
		double x = m_current /  m_v_digi;
		
		String txt = (String) x;
		return x;
	}


	uint16_t ACS712::Set_ADC(byte bit){
		if (bit >= 8){
			m_bit = pow (2,(bit-1)) + 1; // +1 ???? sonst 511
		}
		return m_bit;
	}

	
	// Spannungsgram *******************************
	long ACS712::Get_1100_digi() {

		ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
	  delay(2); // Wait for Vref to settle
	  ADCSRA |= _BV(ADSC); // Start conversion
	  while (bit_is_set(ADCSRA,ADSC)); // measuring
	 
	  uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
	  uint8_t high = ADCH; // unlocks both
	 
	  long result = (high<<8) | low;
	  m_1100_digi = result; // global ***********

	  return result; // Vcc in millivolts
	}

	long ACS712::Get_vcc_analog() {

		long result = Get_1100_digi();
		long x = ( 1100 / result ) * 1023 ;
		m_vcc = x; 		// global *************
		return x; // Vcc in millivolts
	}



