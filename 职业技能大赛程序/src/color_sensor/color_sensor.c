#include "color_sensor.h"


/*******************************************
* 文件名： TCS3200颜色测试
* 型号：   GY-31
* 功能：   读取RGB值
* 单片机： STC15w408as
* 晶振：   11.0592m 
* 时间：   2016-3-28
* LCD1602显示R,G,B值
/********************************************/

//接线说明：
//模块S2-----单片机P1.1
//模块S3-----单片机P1.0
//模块OUT----单片机P3.5(计数器1输入)
//模块VCC----单片机VCC
//模块GND----单片机GND
//**********************************************


 //变量、常量定义

uint red_dat,green_dat,blue_dat;
uchar count=0;          //颜色标志位（0:红 1:绿 2:蓝）

/*******************************************
* 函数名称: t0_init()
* 函数功能: 定时器0初始化 10ms	 定时器1计数模式   P3.5
* 入口参数: 无
* 出口参数: 无
/********************************************/
void t0_init()
{		
                      //10毫秒@11.0592MHz
	AUXR &=0x3F;		//定时器时钟12T模式  
	TMOD  =0x50;    //T1计数 T0定时 工作方式1
	TL0 = 0x00;		//设置定时初值
	TH0 = 0xDC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	
     TH1=0x00;        //计数初值
     TL1=0x00;
     ET0=1;
		EA=1;	
	
}
 /*******************************************
* 函数名称: c10ms_out() 
* 函数功能: 定时中断0服务程序
            修改颜色标志disp_tc（0:红 1:绿 2:蓝）
            设置S0 S1 S2 选择滤波器
            计算脉冲，读取色值
* 入口参数: 无
* 出口参数: 无
/********************************************/
void c10ms_out() interrupt 1
{      
  float rp=0.79,gp=2,bp=1.75; //定义比例因子，具体环境可以修改 
	    uint temp;
        TR0=0;              //关闭定时
        TR1=0;              //关闭计数    
        if(count==0)
        {
        count++;    
        s2=1;s3=1;             //选择滤波器为绿色     
				temp=(uint)((TH1<<8)+TL1)*rp;    //计算这段时间内 TCS230 的输出脉冲数	
				red_dat=temp;
        } 
        else if(count==1)
        {            
        count++;
        s2=0;s3=1;            //选择滤波器为蓝色
				temp=(uint)((TH1<<8)+TL1)*gp;    //计算这段时间内 TCS230 的输出脉冲数		
       	green_dat=temp;	
        }

        else if(count==2)
        {            
        count=0;
        s2=0;s3=0;            //选择滤波器为红色
		    temp=(uint)((TH1<<8)+TL1)*bp;    //计算这段时间内 TCS230 的输出脉冲数	
  	    blue_dat=temp;
        }
     TL1=0x00;//计数器清零
     TH1=0x00;//计数器清零
     TR0=1;   //打开定时器
     TR1=1;   //打开计数器
}



