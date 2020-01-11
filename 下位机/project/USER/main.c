//#include "stm32f10x.h"
//#include "Lcd_Driver.h"
//#include "GUI.h"
//#include "delay.h"
//#include "rc522.h"

//int main()
//{
//	SystemInit();
//	delay_init(72);
//	Lcd_Init();
//	LCD_LED_SET;//通过IO控制背光亮		
//	Lcd_Clear(GRAY0);
//	RC522_Init();
//	Gui_DrawFont_GBK16(16,10,BLUE,GRAY0,"RFID_TEST_FINAL");
//	delay_ms(1000);
//	while(1)
//	{
//		RC522_Handel();
////		Lcd_Clear(GRAY0);
////		Gui_DrawFont_GBK16(16,10,BLUE,GRAY0,"文字显示测试");

////		delay_ms(1000);
////		Lcd_Clear(GRAY0);
////		Gui_DrawFont_GBK16(16,30,YELLOW,GRAY0,"全动电子技术");
////		Gui_DrawFont_GBK16(16,50,BLUE,GRAY0,"专注液晶批发");
////		Gui_DrawFont_GBK16(16,70,RED,GRAY0, "全程技术支持");
////		Gui_DrawFont_GBK16(0,100,BLUE,GRAY0,"Tel:18639000975");
////		Gui_DrawFont_GBK16(0,130,RED,GRAY0, "QQ:2534656669");	
////		delay_ms(1800);	
//		//RC522_Handel();
//	}
//	
//	return 0;
//}

#include "stm32f10x.h"
//#include "oled.h"
#include "MAIN.h"
#include "mfrc522.h"
#include "string.h"
#include "Lcd_Driver.h"
#include "GUI.h"
#include "delay.h"
#include <stdio.h>

unsigned char card1[5] = {0x20,0x25,0x35,0x55,0x3F};  //卡序列号
//unsigned char card1[4] = {0xF0,0x1C,0x70,0x3B};  //卡序列号
unsigned char card2[4] = {0xDE,0x8A,0xDF,0x2B};  //卡序列号
unsigned char card3[4] = {0xD2,0xB2,0x73,0x5B};
unsigned char card4[4] = {0xB7,0x29,0xDF,0x2B};


unsigned char snr, buf[16]="liu-bridge",bufr[16], TagType[2], SelectedSnr[4], DefaultKey[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};  
unsigned char Read_Data[16],PassWd[6],WriteData[16],RevBuffer[30], MLastSelectedSnr[4],NewKey[16];		         
char cardID[4];
unsigned char kahao;
void findcard();

void GPIO_ini()
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	/* Enable the GPIO Clock */
	RCC_APB2PeriphClockCmd(MF522_RST_CLK, ENABLE);

	/* Configure the GPIO pin */
	GPIO_InitStructure.GPIO_Pin = MF522_RST_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(MF522_RST_PORT, &GPIO_InitStructure);

	/* Enable the GPIO Clock */
	RCC_APB2PeriphClockCmd(MF522_MISO_CLK, ENABLE);

	/* Configure the GPIO pin */
	GPIO_InitStructure.GPIO_Pin = MF522_MISO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(MF522_MISO_PORT, &GPIO_InitStructure);

	/* Enable the GPIO Clock */
	RCC_APB2PeriphClockCmd(MF522_MOSI_CLK, ENABLE);

	/* Configure the GPIO pin */
	GPIO_InitStructure.GPIO_Pin = MF522_MOSI_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(MF522_MOSI_PORT, &GPIO_InitStructure);

	/* Enable the GPIO Clock */
	RCC_APB2PeriphClockCmd(MF522_SCK_CLK, ENABLE);

	/* Configure the GPIO pin */
	GPIO_InitStructure.GPIO_Pin = MF522_SCK_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(MF522_SCK_PORT, &GPIO_InitStructure);

	/* Enable the GPIO Clock */
	RCC_APB2PeriphClockCmd(MF522_NSS_CLK, ENABLE);

	/* Configure the GPIO pin */
	GPIO_InitStructure.GPIO_Pin = MF522_NSS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(MF522_NSS_PORT, &GPIO_InitStructure);

	/* Enable the GPIO Clock */
	RCC_APB2PeriphClockCmd(LED_CLK, ENABLE);

	/* Configure the GPIO pin */
	GPIO_InitStructure.GPIO_Pin = LED_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(LED_PORT, &GPIO_InitStructure);
}

void InitializeSystem()
{
	LED_OFF;
	delay_10ms(10);
	PcdReset();
	PcdAntennaOff(); 
	PcdAntennaOn();  
	M500PcdConfigISOType( 'A' );
	LED_ON;
	delay_10ms(10);	
	LED_OFF;
	delay_10ms(10);
	LED_ON;
	delay_10ms(10);	
	LED_OFF;
}

void initL()
{
	SystemInit();
	delay_init(72);
	Lcd_Init();
	LCD_LED_SET;//通过IO控制背光亮		
	Lcd_Clear(GRAY0);
	Gui_DrawFont_GBK16(16,10,BLUE,GRAY0,"RFID_TEST_FINAL");
	delay_ms(1000);
	Gui_DrawFont_GBK16(16,10,BLUE,GRAY0,"RFID_TEST_FINAL");
}

int i,j;
int main(void)
{	
	u8 buf1[20];
	char status;
	unsigned char rfidflag;
	unsigned char discnt;
	kahao=0;
	initL();
	GPIO_ini();  
  InitializeSystem();
  //uart_init(9600);
	//OLED_Init();
	//Draw_Logo();
	//for(i=0;i<2000;i++)
	//	for(j=0;j<2000;j++);
	//OLED_Fill(0x00);
  //OLED_ShowString1(0,0," RFID EPC SYS");
	//OLED_ShowString1(0,3," Status:  OK");
	//printf("\r\n This is a RFID System \r\n");

	while(1)
	{
		// printf("STM32F103C8Z USART OK\r\n");
		status= PcdRequest(REQ_ALL,TagType);
		if(!status)
		{
			status = PcdAnticoll(SelectedSnr);
			if(!status)
			{
				status=PcdSelect(SelectedSnr);
				if(!status)
				{
					snr = 1;  //扇区号1
					status = PcdAuthState(KEYA, (snr*4+3), DefaultKey, SelectedSnr);// 校验1扇区密码，密码位于每一扇区第3块
					{
						if(!status)
						{
							//status = PcdRead((snr*4+0), buf);  // 读卡，读取1扇区0块数据到buf[0]-buf[16]
							//buf[0]=2;buf[1]=2;buf[2]=3;buf[3]=4;buf[4]=5;buf[6]=1;;buf[7]=1;buf[8]=1;buf[9]=9;
							//status = PcdWrite((snr*4+0), buf);  // 写卡，将buf[0]-buf[16]写入1扇区0块
							if(!status)
							{
								//读写成功，点亮LED
								LED_ON;
								//printf("STM32F103C8Z USART OK\r\n");
								PcdAuthState(KEYA, (snr*4+3), DefaultKey, SelectedSnr);
								status = PcdRead((snr*4+0), bufr);
								findcard();
								//printf(" %s %s",bufr,SelectedSnr);
								//sprintf(buf1, " id:%s ",SelectedSnr);
								//Gui_DrawFont_GBK16(0,100,BLUE,GRAY0,"成功");
								//Gui_DrawFont_GBK16(0,100,BLUE,GRAY0,"RFID_TEST_FINAL");
								WaitCardOff();
							}
						}
					}
				}
			}
		}
		LED_OFF;
	}
	
	return 0;
}

void findcard()
{
	unsigned char ii;
	for (ii=0;ii<5;ii++)	  //比较卡序列号
  {
		if (SelectedSnr[ii] == card1[ii])
    {
			kahao=0; 
			LED_OFF;
	    break;
	  }
	  else
	  {
			if (ii==3)
	    { kahao=1; 
	      goto A;
	      break; 
		  }
	  }
  }
  for (ii=0;ii<4;ii++)
  {
		if (SelectedSnr[ii] != card2[ii])
     {
			 kahao=0; 
	     break;
	   }
	   else
	   { if (ii==3)
	     { kahao=2; 
				 goto A;
	 	     break; 
		   }
	   }
  }
	for (ii=0;ii<4;ii++)
  {
		if (SelectedSnr[ii] != card3[ii])
     { kahao=0; 
	     break;
	   }
	   else
	   { if (ii==3)
	     { kahao=3; 
				 goto A;
	 	     break; 
		   }
	   }
  }
	for (ii=0;ii<4;ii++)
  { if (SelectedSnr[ii] != card4[ii])
     { kahao=0; 
	     break;
	   }
	   else
	   { if (ii==3)
	     { kahao=4; 
				 goto A;
	 	     break; 
		   }
	   }
  }
	
A:if(kahao==1)
  {
   kahao=1; 
	}
	if(kahao==2)
	{
	  kahao=2;
	}
	if(kahao==3)
	{
	  kahao=3;
	}
	if(kahao==4)
	{
	  kahao=4;
	}
}
