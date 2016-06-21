/*
	ACS712.h
*/
#ifndef	ACS712_H
#define	ACS712_H

#include <Arduino.h>
#include <math.h>

class ACS712
{
	public:
		ACS712(void);
		uint16_t Set_ADC(byte bit);
		double Get_current(uint8_t port,int version);
		long Get_vcc_analog(void);
		long Get_1100_digi(void);
		float Get_adc_analog(void);
		long Get_adc_digi(void);
		
	private:
		double m_current ; //
		int m_v_analog;
		double m_v_digi;
		uint16_t m_bit; 
		uint8_t m_port;
		long m_vcc;
		long m_1100_digi;
		double m_half;
				
		//float m_read_vcc(void);
		
};
#endif
// Ende