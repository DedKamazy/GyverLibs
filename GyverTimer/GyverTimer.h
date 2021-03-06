#ifndef GyverTimer_h
#define GyverTimer_h
#include <Arduino.h>
#define LIBRARY_VERSION	1.3

/*
	Текущая версия: 1.3 от 27.09.2018
	GTimer - компактная альтернатива конструкции таймера с millis() / micros()
	- Вся работа с таймером заменяется одной функцией
	- Миллисекундный и микросекундный таймер
	- Автоматический и ручной режим работы
*/

#define AUTO 0
#define MANUAL 1

class GTimer_ms
{
  public:
	GTimer_ms();								// объявление таймера (МИЛЛИСЕКУНДНЫЙ)
	GTimer_ms(uint32_t interval);				// объявление таймера с указанием интервала
	void setInterval(uint32_t interval);	// установка интервала работы таймера
	void setMode(boolean mode);				// установка типа работы: AUTO или MANUAL (MANUAL нужно вручную сбрасывать reset)
	boolean isReady();						// возвращает true, когда пришло время. Сбрасывается в false сам (AUTO) или вручную (MANUAL)
	void reset();							// ручной сброс таймера на установленный интервал
	
  private:
	uint32_t _timer = 0;
	uint32_t _interval = 0;
	boolean _mode = 0;
};

class GTimer_us
{
  public:
	GTimer_us();							// объявление таймера (МИКРОСЕКУНДНЫЙ)
	GTimer_us(uint32_t interval);			// объявление таймера с указанием интервала
	void setInterval(uint32_t interval);	// установка интервала работы таймера
	void setMode(boolean mode);				// установка типа работы: AUTO или MANUAL (MANUAL нужно вручную сбрасывать reset)
	boolean isReady();						// возвращает true, когда пришло время. Сбрасывается в false сам (AUTO) или вручную (MANUAL)
	void reset();							// ручной сброс таймера на установленный интервал
	
  private:
	uint32_t _timer = 0;
	uint32_t _interval = 0;
	boolean _mode = 0;
};

#endif