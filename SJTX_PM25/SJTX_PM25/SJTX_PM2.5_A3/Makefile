# MPLAB IDE generated this makefile for use with GNU make.
# Project: usart.mcp
# Date: Tue Jan 16 14:06:15 2018

AS = MPASMWIN.exe
CC = mcc18.exe
LD = mplink.exe
AR = mplib.exe
RM = rm

usart.cof : usart.o CAN.o time.o main.o
	$(LD) /p18F25K80 /l"C:\Program Files (x86)\Microchip\mplabc18\v3.47\lib" "usart.o" "CAN.o" "time.o" "main.o" /u_CRUNTIME /z__MPLAB_BUILD=1 /o"usart.cof" /M"usart.map" /W

usart.o : usart.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f25k80.h
	$(CC) -p=18F25K80 "usart.c" -fo="usart.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

CAN.o : CAN.c CAN.h CAN.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f25k80.h
	$(CC) -p=18F25K80 "CAN.c" -fo="CAN.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

time.o : time.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/timers.h time.c time.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f25k80.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/pconfig.h
	$(CC) -p=18F25K80 "time.c" -fo="time.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

main.o : main.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/delays.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/timers.h CAN.h main.c C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18cxxx.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/p18f25k80.h C:/Program\ Files\ (x86)/Microchip/mplabc18/v3.47/h/pconfig.h time.h usart.h
	$(CC) -p=18F25K80 "main.c" -fo="main.o" -Ou- -Ot- -Ob- -Op- -Or- -Od- -Opa-

clean : 
	$(RM) "usart.o" "CAN.o" "time.o" "main.o" "usart.cof" "usart.hex"

