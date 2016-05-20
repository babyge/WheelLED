/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f0_system.h"
#include "stm32f0_spi.h"
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : SPI_RW8
**功能 : Send and Receive Data
**輸入 : SPIx, writeByte
**輸出 : None
**使用 : read = SPI_RW8(SPI1, 0xFF);
**=====================================================================================================*/
/*=====================================================================================================*/
uint8_t SPI_RW8( SPI_TypeDef *SPIx, uint8_t writeByte )
{
  while((SPIx->SR & SPI_I2S_FLAG_TXE) == (uint16_t)RESET);
  *(__IO uint8_t *)(&SPIx->DR) = writeByte;
  while((SPIx->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);

  return (*(__IO uint8_t *)(&SPIx->DR));
}
/*=====================================================================================================*/
/*=====================================================================================================*
**函數 : SPI_RW
**功能 : Receive Data
**輸入 : SPIx
**輸出 : None
**使用 : Read = SPI_RW(SPI1, 0xFFFF);
**=====================================================================================================*/
/*=====================================================================================================*/
uint16_t SPI_RW( SPI_TypeDef *SPIx, uint16_t writeByte )
{
  while((SPIx->SR & SPI_I2S_FLAG_TXE) == (uint16_t)RESET);
  SPIx->DR = writeByte;
  while((SPIx->SR & SPI_I2S_FLAG_RXNE) == (uint16_t)RESET);

  return SPIx->DR;
}
/*=====================================================================================================*/
/*=====================================================================================================*/
