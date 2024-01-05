/*
 * car.c
 *
 * 
 *  Author: Mahmoud Hamed 
 */ 

#include "car.h"

 void car_forward(void)
 {
	 DIO_write_pin('a',0,1);
	 DIO_write_pin('a',1,0);
	 DIO_write_pin('a',2,1);
	 DIO_write_pin('a',3,0);
 }
 void car_right(void)
 {
	 DIO_write_pin('a',0,1);
	 DIO_write_pin('a',1,0);
	 DIO_write_pin('a',2,0);
	 DIO_write_pin('a',3,1);
	 
	 
 }
 void car_left(void)
 {
	 DIO_write_pin('a',0,0);
	 DIO_write_pin('a',1,1);
	 DIO_write_pin('a',2,1);
	 DIO_write_pin('a',3,0);
	 
 }
 
  void car_back(void)
  {
	   DIO_write_pin('a',0,0);
	   DIO_write_pin('a',1,1);
	   DIO_write_pin('a',2,0);
	   DIO_write_pin('a',3,1);
  
  }
  
 void car_stop()
  {
		 DIO_write_pin('a',0,0);
		 DIO_write_pin('a',1,0);
		 DIO_write_pin('a',2,0);
		 DIO_write_pin('a',3,0);
  }