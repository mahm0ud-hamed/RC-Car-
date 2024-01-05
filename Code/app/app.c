/*
 * app.c
 *
 * 
 *  Author: Mahmoud Hamed
 */ 

 #include "app.h"
void app_init()
{
	
	// uart init 
	UART_Init(9600); 
	// init uart pin for bluetooth
	DIO_init_pin('d',0,0); 
	DIO_init_pin('d',1,1);
	
	//Motor Drivers PINS
	DIO_init_pin('a',0,1);
	DIO_init_pin('a',1,1);
	DIO_init_pin('a',2,1);
	DIO_init_pin('a',3,1);
	//Make sure all is zero
	DIO_write_pin('a',0,0);
	DIO_write_pin('a',1,0);
	DIO_write_pin('a',2,0);
	DIO_write_pin('a',3,0);
	//IR sensors input
	DIO_init_pin('c',0,0);
	DIO_init_pin('c',1,0);
	// led for uart 
	DIO_init_pin('b',0,1);
	
	// mode select button 
	DIO_init_pin('a',4,0);
	// set pin pullupu internal 
	DIO_write_pin('a',4,1); 
	
	
}




void app_start(void)
{
	 volatile uint8_t se0,se1;
	 uint8_t act;
	 uint8_t uart_rec=0 ; 
     volatile uint8_t mood_selc = 0; 

	 car_stop(); 
 	while (1)
 	{   
	
		 DIO_read_pin('a',4,&mood_selc); 
		 
		 if(mood_selc == HIGH)
		 {
			  se0=0;
			  se1=0;
			  DIO_read_pin('c',0,&se0);
			  DIO_read_pin('c',1,&se1);
			  
			  act=sens_comp(se0,se1);
			  
			  
			  switch (act)
			  {
				  
				  case 1:
				  car_right();
				  break;
				  case 2:
				  car_left();
				  break;
				  default:
				  car_forward();
				  break;
			  }
		  
		 }
		 
		 else if( mood_selc ==LOW)
		 {

		    uart_rec = UART_Receive();
		   
		   switch(uart_rec)
		   {
			  case 'F':
			  {
						 car_forward();
			  }    
			  break;
			  case 'L':
			  {
				  car_left();
			  }
						
			  break;
			  
			  case 'B':
			   {
				  car_back();
			   }         
			  break;
			  
			  case 'R':
			  {
				  car_right();
			  }
			            
			  break;
			  default: 
			  {
				  car_stop();
			  }
						
			 break;
			  
			  
		   }
		   
		 }
		 
	
	 }
}
	


uint8_t sens_comp(uint8_t s1,uint8_t s2)
{
	if(s1>s2)
	{
		return 1;
	}
	else if (s1<s2)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}