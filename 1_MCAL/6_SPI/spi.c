/******************************************************************************
 * File: spi.c
 * Description: This file contains the implementation of UART driver for ATmega32
 * Author: Nada Ehab
 ******************************************************************************/


/*******************************************
 *           Section : INCLUDES
 *******************************************/
#include "spi.h"

/*******************************************
 *       Section: global variables
 *******************************************/

/*Global flag for the SPI Busy State*/

static SPI_FunState SPIState= IDLE ;



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




SPI_State SPI_ uint8_tTranceive ( uint8_t CopyData ,  uint8_t * CopyData)

{
	
	SPI_State Local_u8ErrorState =OK ;
	
	 uint8_t Local_uint32TimeoutCounter = 0 ;
	  
	  if (SPI_FunState SPIState == IDLE)
	  	{
		  SPI_FunState SPIState = BUSY ;

	  		SPDR = CopyData;

	  		while (((GET_BIT(SPSR ,SPIF)) == 0) && (Local_uint32TimeoutCounter < SPI_uint32TIMEOUT))
	  		{
	  			Local_uint32TimeoutCounter++ ;
	  		}
	  		if (Local_uint32TimeoutCounter == SPI_uint32TIMEOUT)
	  		{
	  			Local_u8ErrorState = OK ;
	  		}
	  		else
	  		{
	  			* CopyData = SPDR ;
	  		}
	  		SPI_FunState SPIState = IDLE ;
	  	}
	  	else
	  	{
	  		Local_u8ErrorState = BUSY_STATE ;
	  	}

	  	return Local_u8ErrorState ;
	  }



}


SPI_State SPI_BufferTranceiverSynch (uint8_t* Copy_u8TData , uint8_t * Copy_u8RData , uint8_t Copy_u8BufferSize) 
{
	SPI_State Local_u8ErrorState = OK ;
	uint8_t Local_u8Counter = 0 ;
		if ((Copy_u8TData != NULL) && (Copy_u8RData != NULL))
		{
			while (Local_u8Counter < Copy_u8BufferSize)
			{
			    SPI_ uint8_tTranceive(Copy_u8TData[Local_u8Counter] , &Copy_u8RData[Local_u8Counter]) ;
				Local_u8Counter++ ;
			}
			
		}
			else
			{
				Local_u8ErrorState = NOT_OK;
			}
			return Local_u8ErrorState ;
}




