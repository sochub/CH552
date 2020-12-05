
/********************************** (C) COPYRIGHT *******************************
* File Name          : Main.C
* Author             : WCH
* Version            : V1.0
* Date               : 2017/01/20
* Description        : GPIO ������ʹ�ú�GPIO�ж�ʹ��ʾ��   
*******************************************************************************/
#include "..\Public\CH554.H"                                                   
#include "..\Public\Debug.H"
#include "GPIO.H"
#include "stdio.h"
#include <string.h>

#pragma  NOAREGS

void main( ) 
{
    UINT16 j = 0;
    CfgFsys( );                                                                //CH554ʱ��ѡ������   
    mDelaymS(20);
    mInitSTDIO( );                                                             //����0��ʼ��
    printf("start ...\n"); 

#if GPIO_INTERRUPT
    GPIOInterruptCfg();                                                        //GPIO�ж����ú���	
    EA = 1;
    printf("Run"); 
    while(1){
      printf("."); 
      mDelaymS(50);			
    }
#endif	
    Port1Cfg(3,4);                                                             //P14���ó���51˫��ģʽ         
    while(1){
      SCS = ~SCS;
      mDelaymS(50);			
    }
}