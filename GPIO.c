#include "GPIO.h"

void GPIO_PORT_INT(unsigned char PORTNAME)
{
  switch(PORTNAME)
  {
  case GPIO_PORTA:
    { SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTA);     //Clock Enable for port A
      while(READ_BIT(SYSCTL_PRGPIO_R, 0) == 0);  //allow time for clock to start
      GPIO_PORTA_LOCK_R = 0x4C4F434B;           //unlock PORTA register
      GPIO_PORTA_CR_R = 0xFF;                  //Allow changes in Port A
      GPIO_PORTA_DEN_R = 0xFF;	              //Enable digital for port A
    }	
    break;

  case GPIO_PORTB:
    { SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTB);     //Clock Enable for port B
      while(READ_BIT(SYSCTL_PRGPIO_R, 1) == 0);  //allow time for clock to start
      GPIO_PORTB_LOCK_R = 0x4C4F434B;           //unlock PORTB register
      GPIO_PORTB_CR_R = 0xFF; 		       //Allow changes in Port B
      GPIO_PORTB_DEN_R = 0xFF;		      //Enable digital for port B
    }	
    break;

  case GPIO_PORTC:
    { SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTC);     //Clock Enable for port C
      while(READ_BIT(SYSCTL_PRGPIO_R, 2) == 0);  //allow time for clock to start
      GPIO_PORTC_LOCK_R = 0x4C4F434B; 		//unlock PORT C register
      GPIO_PORTC_CR_R |= 0xF0;                 //Allow changes in Port C for pins4-7 only The others are used JTAG on the board
      GPIO_PORTC_DEN_R |= 0xF0;	 	      //Enable digital for port C
    }	
    break;

  case GPIO_PORTD:
    { SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTD);     //Clock Enable for port D
      while(READ_BIT(SYSCTL_PRGPIO_R, 3) == 0);  //allow time for clock to start
      GPIO_PORTD_LOCK_R = 0x4C4F434B; 		//unlock PORTD register
      GPIO_PORTD_CR_R = 0xFF; 		       //Allow changes in Port D
      GPIO_PORTD_DEN_R = 0xFF;	              //Enable digital for port D
    }	
    break;

  case GPIO_PORTE:
    { SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTE);     //Clock Enable for port E
      while(READ_BIT(SYSCTL_PRGPIO_R, 4) == 0);  //allow time for clock to start
      GPIO_PORTE_LOCK_R = 0x4C4F434B;           //unlock PORTE register
      GPIO_PORTE_CR_R = 0xFF;                  //Allow changes in Port E
      GPIO_PORTE_DEN_R = 0xFF;                //Enable digital for port E
    }	
    break;

  case GPIO_PORTF:
    { SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTF);     //Clock Enable for port F
      while(READ_BIT(SYSCTL_PRGPIO_R, 5) == 0);  //allow time for clock to start
      GPIO_PORTF_LOCK_R = 0x4C4F434B;           //unlock PORTF register
      GPIO_PORTF_CR_R = 0xFF;                  //Allow changes to Port F
      GPIO_PORTF_DEN_R = 0xFF;                //Enable digital for port F
    }		
    break;
  }
}

//**********************************************************************************************************************//

void SET_PIN_DIRECTION(unsigned char PORTNAME, unsigned char PINNUMBER, unsigned char DIRECTION)
{
  switch(PORTNAME)
  {
  case GPIO_PORTA:
    if(DIRECTION==1)
    {
      SET_BIT(GPIO_PORTA_DIR_R, PINNUMBER); //Make the PIN output by setting it high
    }
    else
    {
      CLR_BIT(GPIO_PORTA_DIR_R, PINNUMBER); //Make the PIN input by setting it low
    }
    break;

  case GPIO_PORTB:
    if(DIRECTION==1)
    {
      SET_BIT(GPIO_PORTB_DIR_R, PINNUMBER); //Make the PIN output by setting it
    }
    else
    {
      CLR_BIT(GPIO_PORTB_DIR_R, PINNUMBER); //Make the PIN input
    }
    break;

  case GPIO_PORTC:
    if(DIRECTION==1)
    {
      SET_BIT(GPIO_PORTC_DIR_R, PINNUMBER); //Make the PIN output by setting it
    }
    else
    {
      CLR_BIT(GPIO_PORTC_DIR_R, PINNUMBER); //Make the PIN input
    }
    break;

  case GPIO_PORTD:
    if(DIRECTION==1)
    {
      SET_BIT(GPIO_PORTD_DIR_R, PINNUMBER); //Make the PIN output by setting it
    }
    else
    {
      CLR_BIT(GPIO_PORTD_DIR_R, PINNUMBER); //Make the PIN input
    }
    break;

  case GPIO_PORTE:
    if(DIRECTION==1)
    {
      SET_BIT(GPIO_PORTE_DIR_R, PINNUMBER); //Make the PIN output by setting it
    }
    else
    {
      CLR_BIT(GPIO_PORTE_DIR_R, PINNUMBER); //Make the PIN input
    }
    break;

  case GPIO_PORTF:
    if(DIRECTION==1)
    {
      SET_BIT(GPIO_PORTF_DIR_R, PINNUMBER); //Make the PIN output by setting it
    }
    else
    {
      CLR_BIT(GPIO_PORTF_DIR_R, PINNUMBER); //Make the PIN input
    }
    break;
  }
}

//*******************************************************************************************************************************

void WRITE_PIN_VALUE(unsigned char PORTNAME, unsigned char PINNUMBER, unsigned char VALUE)
{
 switch(PORTNAME)
 {
  case GPIO_PORTA:   //Write Data to Pin in portA
   {
    if(VALUE==1)
    {
      SET_BIT(GPIO_PORTA_DATA_R, PINNUMBER);  
    }
    else if(VALUE==0)
    {
      CLR_BIT(GPIO_PORTA_DATA_R, PINNUMBER); 
    }
   }
   break;

  case GPIO_PORTB:   //Write Data to Pin in portB
   {
    if(VALUE==1)
    {
      SET_BIT(GPIO_PORTB_DATA_R, PINNUMBER); 
    }
    else if(VALUE==0)
    {
      CLR_BIT(GPIO_PORTB_DATA_R, PINNUMBER); 
    }
   }
   break;

  case GPIO_PORTC:   //Write Data to Pin in portC
   {
    if(VALUE==1)
    {
      SET_BIT(GPIO_PORTC_DATA_R, PINNUMBER); 
    } 
    else if(VALUE==0)
    {
      CLR_BIT(GPIO_PORTC_DATA_R, PINNUMBER); 
    }
   }
   break;

  case GPIO_PORTD:   //Write Data to Pin in portD
   {
    if(VALUE==1)
    {
      SET_BIT(GPIO_PORTD_DATA_R, PINNUMBER); 
    }
    else if(VALUE==0)
    {
      CLR_BIT(GPIO_PORTD_DATA_R, PINNUMBER); 
    }
   }
   break;

  case GPIO_PORTE:   //Write Data to Pin in portE
   {
    if(VALUE==1)
    {
      SET_BIT(GPIO_PORTE_DATA_R, PINNUMBER); 
    }
    else if(VALUE==0)
    {
      CLR_BIT(GPIO_PORTE_DATA_R, PINNUMBER); 
    }
   }
   break;

  case GPIO_PORTF:   //Write Data to Pin in portF
   {
    if(VALUE==1)
    {
      SET_BIT(GPIO_PORTF_DATA_R, PINNUMBER); 
    }
    else if(VALUE==0)
    {
      CLR_BIT(GPIO_PORTF_DATA_R, PINNUMBER); 
    }
   }
   break;
  }
}

//*******************************************************************************************************************************

unsigned char READ_PIN_VALUE(unsigned char PORTNAME, unsigned char PINNUMBER)
{
 unsigned char return_value; //Variable to store the return value of the function
  switch(PORTNAME)
  {
    case GPIO_PORTA:   //Read Data from Pin in portA
     {
       return_value = READ_BIT(GPIO_PORTA_DATA_R, PINNUMBER);
     }	
     break;

    case GPIO_PORTB:   //Read Data from Pin in portB
     {
       return_value = READ_BIT(GPIO_PORTB_DATA_R, PINNUMBER);
     }	
     break;

    case GPIO_PORTC:   //Read Data from Pin in portC
     {
       return_value = READ_BIT(GPIO_PORTC_DATA_R, PINNUMBER);
     }	
     break;

    case GPIO_PORTD:   //Read Data from Pin in portD
     {
       return_value = READ_BIT(GPIO_PORTD_DATA_R, PINNUMBER);
     }
     break;

    case GPIO_PORTE:   //Read Data from Pin in portE
     {
       return_value = READ_BIT(GPIO_PORTE_DATA_R, PINNUMBER);
     }
     break;

    case GPIO_PORTF:   //Read Data from Pin in portF
     {
       return_value = READ_BIT(GPIO_PORTF_DATA_R, PINNUMBER);
     }
     break;
  }
return return_value;
}

//*******************************************************************************************************************************

void TOGGLE_PIN(unsigned char PORTNAME, unsigned char PINNUMBER)
{
switch(PORTNAME)
{
   case GPIO_PORTA: 
    {
      TOG_BIT(GPIO_PORTA_DATA_R, PINNUMBER); //To invert Pin in PortA
    }
    break;

   case GPIO_PORTB:
    {
      TOG_BIT(GPIO_PORTB_DATA_R, PINNUMBER); //To invert Pin in PortB
    }
    break;

   case GPIO_PORTC:
    {
      TOG_BIT(GPIO_PORTC_DATA_R, PINNUMBER); //To invert Pin in PortC
    }
    break;

   case GPIO_PORTD:
    {
      TOG_BIT(GPIO_PORTD_DATA_R, PINNUMBER); //To invert Pin in PortD
    }
    break;

   case GPIO_PORTE:
    {
      TOG_BIT(GPIO_PORTE_DATA_R, PINNUMBER); //To invert Pin in PortE
    }
    break;

   case GPIO_PORTF:
    {
      TOG_BIT(GPIO_PORTF_DATA_R, PINNUMBER); //To invert Pin in PortF
    }
    break;
  }
}

//*******************************************************************************************************************************

void SET_PORT_DIRECTION(unsigned char PORTNAME, unsigned char DIRECTION)
{
  switch(PORTNAME)
   {
    case GPIO_PORTA: 
     {
       GPIO_PORTA_DIR_R = DIRECTION; //Setting the direction of PortA
     }
     break;

    case GPIO_PORTB:
     {
       GPIO_PORTB_DIR_R = DIRECTION; //Setting the direction of PortB
     }
     break;

    case GPIO_PORTC:
     {
       GPIO_PORTC_DIR_R = DIRECTION; //Setting the direction of PortC
     }
     break;

    case GPIO_PORTD:
     {
       GPIO_PORTD_DIR_R = DIRECTION; //Setting the direction of PortD
     }
     break;

    case GPIO_PORTE:
     {
       GPIO_PORTE_DIR_R = DIRECTION; //Setting the direction of PortE
     }
     break;

    case GPIO_PORTF:
     {
       GPIO_PORTF_DIR_R = DIRECTION; //Setting the direction of PortF
     }
     break;
   }
}

//*******************************************************************************************************************************

void WRITE_PORT_VALUE(unsigned char PORTNAME, unsigned char VALUE)
{
  switch(PORTNAME)
   {
    case GPIO_PORTA:
     {
       GPIO_PORTA_DATA_R = VALUE; //Writing data on PortA
     }
     break;

    case GPIO_PORTB:
     {
       GPIO_PORTB_DATA_R = VALUE; //Writing data on PortB
     }
     break;

    case GPIO_PORTC:
     {
       GPIO_PORTC_DATA_R = VALUE; //Writing data on PortC
     }
     break;

    case GPIO_PORTD:
     {
       GPIO_PORTD_DATA_R = VALUE; //Writing data on PortD
     }
     break;

    case GPIO_PORTE:
     {
       GPIO_PORTE_DATA_R = VALUE; //Writing data on PortE
     }
     break;

    case GPIO_PORTF:
     {
       GPIO_PORTF_DATA_R = VALUE; //Writing data on PortF
     }
     break;
   }
}

//*******************************************************************************************************************************

unsigned char READ_PORT(unsigned char PORTNAME)
{
  unsigned char return_value;
  switch(PORTNAME)
  {
    case GPIO_PORTA:
     {
       return_value = GPIO_PORTA_DATA_R; //Read Data of portA
     }
     break;

    case GPIO_PORTB:
     {
       return_value = GPIO_PORTB_DATA_R; //Read Data of portB
     }
     break;

    case GPIO_PORTC:
     { 
       return_value = GPIO_PORTC_DATA_R; //Read Data of portC
     }
     break;

    case GPIO_PORTD:
     {
       return_value = GPIO_PORTD_DATA_R; //Read Data of portD
     }
     break;

    case GPIO_PORTE:
     {
       return_value = GPIO_PORTE_DATA_R; //Read Data of portE
     }
     break;

    case GPIO_PORTF:
     {
       return_value = GPIO_PORTF_DATA_R; //Read Data of portF
     }
     break;
  }

return return_value;
}

//*******************************************************************************************************************************

void ENABLE_PULLUP(unsigned char PORTNAME, unsigned char PINNUMBER)
{
  switch(PORTNAME)
  {
    case GPIO_PORTA:
     {
       SET_BIT(GPIO_PORTA_PUR_R, PINNUMBER); //Setting Pull Up Resistor of PortA
     }
     break;

    case GPIO_PORTB:
     {
       SET_BIT(GPIO_PORTB_PUR_R, PINNUMBER); //Setting Pull Up Resistor of PortB
     }
     break;

    case GPIO_PORTC:
     {
       SET_BIT(GPIO_PORTC_PUR_R, PINNUMBER); //Setting Pull Up Resistor of PortC
     }
     break;

    case GPIO_PORTD:
     {
       SET_BIT(GPIO_PORTD_PUR_R, PINNUMBER); //Setting Pull Up Resistor of PortD
     }
     break;

    case GPIO_PORTE:
     {
       SET_BIT(GPIO_PORTE_PUR_R, PINNUMBER); //Setting Pull Up Resistor of PortE
     }
     break;

    case GPIO_PORTF:
     {
       SET_BIT(GPIO_PORTF_PUR_R, PINNUMBER); //Setting Pull Up Resistor of PortF
     }
     break;
   }
}

//*******************************************************************************************************************************

void WRITE_HIGH_NIPPLE(unsigned char PORTNAME, unsigned char VALUE)
{
  VALUE <<= 4; //Shifting left the data value by 4 

  switch(PORTNAME)
  {
    case GPIO_PORTA: //Writing on the most significant 4 bits of PortA
     {
       GPIO_PORTA_DATA_R &= 0X0F;    //ANDing with a mask of zeros from bits 4 to 7
       GPIO_PORTA_DATA_R |= VALUE;  //ORing with the data value after shifting
     }
     break;

   case GPIO_PORTB: //Writing on the most significant 4 bits of PortB
    {
      GPIO_PORTB_DATA_R &= 0X0F;    //ANDing with a mask of zeros from bits 4 to 7
      GPIO_PORTB_DATA_R |= VALUE;  //ORing with the data value after shifting
    }
    break;

   case GPIO_PORTC: //Writing on the most significant 4 bits of PortC
    {
      GPIO_PORTC_DATA_R &= 0X0F;    //ANDing with a mask of zeros from bits 4 to 7
      GPIO_PORTC_DATA_R |= VALUE;  //ORing with the data value after shifting
    }
    break;

   case GPIO_PORTD: //Writing on the most significant 4 bits of PortD
    {
      GPIO_PORTD_DATA_R &= 0X0F;    //ANDing with a mask of zeros from bits 4 to 7
      GPIO_PORTD_DATA_R |= VALUE;  //ORing with the data value after shifting
    }
    break;

   case GPIO_PORTE: //Writing on the most significant 4 bits of PortE
    {
      GPIO_PORTE_DATA_R &= 0X0F;    //ANDing with a mask of zeros from bits 4 to 7
      GPIO_PORTE_DATA_R |= VALUE;  //ORing with the data value after shifting
    }
    break;

   case GPIO_PORTF //Writing on the most significant 4 bits of PortF
    {
      GPIO_PORTF_DATA_R &= 0X0F;    //ANDing with a mask of zeros from bits 4 to 7
      GPIO_PORTF_DATA_R |= VALUE;  //ORing with the data value after shifting
    }
    break;
  }
}

//*******************************************************************************************************************************

void WRITE_LOW_NIPPLE(unsigned char PORTNAME, unsigned char VALUE)
{
  switch(PORTNAME)
  {
   case GPIO_PORTA: //Writing on the least significant 4 bits of PortA
    {
      GPIO_PORTA_DATA_R &= 0XF0;    //ANDing with a mask of zeros from bits 0 to 3
      GPIO_PORTA_DATA_R |= VALUE;  //ORing with the data value 
    }
    break;

   case GPIO_PORTB: //Writing on the least significant 4 bits of PortB
    {
      GPIO_PORTB_DATA_R &= 0XF0;    //ANDing with a mask of zeros from bits 0 to 3
      GPIO_PORTB_DATA_R |= VALUE;  //ORing with the data value 
    }
    break;

   case GPIO_PORTC: //Writing on the least significant 4 bits of PortC
    {
      GPIO_PORTC_DATA_R &= 0XF0;    //ANDing with a mask of zeros from bits 0 to 3
      GPIO_PORTC_DATA_R |= VALUE;  //ORing with the data value 
    }
    break;

   case GPIO_PORTD: //Writing on the least significant 4 bits of PortD
    {
      GPIO_PORTD_DATA_R &= 0XF0;    //ANDing with a mask of zeros from bits 0 to 3
      GPIO_PORTD_DATA_R |= VALUE;  //ORing with the data value 
    }
    break;
		
   case GPIO_PORTE: //Writing on the least significant 4 bits of PortE
    {
      GPIO_PORTE_DATA_R &= 0XF0;    //ANDing with a mask of zeros from bits 0 to 3
      GPIO_PORTE_DATA_R |= VALUE;  //ORing with the data value 
    }
    break;

   case GPIO_PORTF: //Writing on the least significant 4 bits of PortF
    {
      GPIO_PORTF_DATA_R &= 0XF0;    //ANDing with a mask of zeros from bits 0 to 3
      GPIO_PORTF_DATA_R |= VALUE;  //ORing with the data value 
    }
    break;
   }
}
