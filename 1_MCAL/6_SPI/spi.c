/******************************************************************************
 * File: spi.c
 * Description: This file contains the implementation of UART driver for ATmega32
 * Author: Nada Ehab
 ******************************************************************************/


/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "spi.h"




void SPI_VoidInit(SPI_Enable spi_enable ,SPI_Mode MasterSlaveMode ,SPI_DataOrder dataOrder, SPI_InterruptEnable spi_interruptEnable)

{
	/**
      * @brief spi enable.
	 */   
	
	if (  spi_enable == SPI_ENABLE )
			SET_BIT(SPCR, SPE);
	else if( spi_enable ==  SPI_DISABLE)
			CLEAR_BIT(SPCR, SPE);
	
	/**
	  * @brief Selcting master or slave mode.
	 */   
	if (  MasterSlaveMode == SPI_MASTER )
		SET_BIT(SPCR,MSTR);
	else if( MasterSlaveMode == SPI_SLAVE)
		CLEAR_BIT(SPCR,MSTR);
	
	/**
	  * @brief Selcting Data order.
     */  
	
	if (  dataOrder == SPI_DATA_LSP_FIRST )
			SET_BIT(SPCR,DORD);
	else if( dataOrder == SPI_DATA_MSB_FIRST)
			CLEAR_BIT(SPCR,DORD);
	
	/** 
      * @brief spi interrupt_enable.
     */   
		
		if (  spi_interruptEnable == SPI_INTERRUPT_ENABLE )
				SET_BIT(SPCR, SPIE	);
		else if( spi_enable ==  SPI_INTERRUPT_DISABLE)
				CLEAR_BIT(SPCR, SPIE);
}




void SPI_CLK_VoidInit (SPI_ClockPolarity clkPriority, SPI_ClockPhase ClkPhase, SPI_ClockRate ClkRate)
{
	
	/** 
      * @brief SET ClockPriority.
	 */   
			
	     if (  clkPriority == SPI_RISING_LEADING_FALLING_TRAILING )
					SET_BIT(SPCR, CPOL	);
		 else if( clkPriority ==   SPI_FALLING_LEADING_RISING_TRAILING)
					CLEAR_BIT(SPCR, CPOL);
	     
    /** 
	  * @brief SET ClockPhase
	 */   

	     if (  ClkPhase ==  SPI_SAMPLE_LEADING_SETUP_TRAILING)
	     					SET_BIT(SPCR, CPHA	);
	      else if( ClkPhase ==   SPI_SETUP_LEADING_SAMPLE_TRAILING)
	     					CLEAR_BIT(SPCR, CPHA); 
	     
	 /** 
       * @brief SET ClockRate
   	 */      

	   
	   switch (ClkRate)
	 
  {
	   case SPI_FREQ_DIVIDED_BY_2
	   CLEAR_BIT(SPCR , SPR0) ;
	   CLEAR_BIT(SPCR , SPR1) ;
	   SET_BIT(SPSR , SPI2X) ;
	   break;
	   
	   case SPI_FREQ_DIVIDED_BY_4
	   CLEAR_BIT(SPCR , SPR0) ;
	   CLEAR_BIT(SPCR , SPR1) ;
	   CLEAR_BIT(SPSR , SPI2X) ;
	   break;
	   
	   case SPI_FREQ_DIVIDED_BY_8   
	   SET_BIT(SPCR , SPR0) ;
	   CLEAR_BIT(SPCR, SPR1) ;
	   SET_BIT(SPSR , SPI2X) ;
	   break;
	   
	   case SPI_FREQ_DIVIDED_BY_16
	   SET_BIT(SPCR , SPR0) ;
	   CLEAR_BIT(SPCR ,SPR1) ;
	   CLEAR_BIT(SPSR ,SPI2X) ;
	   break;
	   
	   case SPI_FREQ_DIVIDED_BY_32
	   CLEAR_BIT(SPCR , SPR0) ;
	   SET_BIT(SPCR , SPR1) ;
	   SET_BIT(SPSR , SPI2X) ;
	   break;
	   
	   case SPI_FREQ_DIVIDED_BY_64
	   CLEAR_BIT(SPCR , SPR0) ;
	   SET_BIT(SPCR ,   SPR1) ;
	   CLEAR_BIT(SPSR , SPI2X) ;
	   break;
	   
	   case SPI_FREQ_DIVIDED_BY_128
	   SET_BIT(SPCR , SPR0) ;
	   SET_BIT(SPCR , SPR1) ;
	   CLEAR_BIT(SPSR ,SPI2X) ;
	   break;    
	   
	   
	   }
	     		     
	     


}