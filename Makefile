#this makefile works only for 1 source file w/ specified name here#
#NAME = Main#	file_name
NAME = VFDclock.ino.standard
CC = avr-gcc#	compiler
DD = avrdude#	...
OBC = avr-objcopy#..
MCA = m$(MCU)#	microcontroller id for avrdude
MCC = atmega$(MCU)#microcontroller id for compiler
BAUD = 19200#	baud rate
BAUDMS = 5 # to be used with -B option
PROG = usbasp#	programator id
LFUSE = 0xE2#	low fuse byte
HFUSE = 0xd9#	high fuse byte
EFUSE = 0xff# 	extra fuse byte
PORT = /dev/ttyACM0
AUXS = utils/sources/*.c# list of auxiliary source files
AUXH = utils/includes# path to auxiliary headers
DFS = -fdata-sections -ffunction-sections#-Wl,--gc-sections#data, function section 4 compiler
RUC = -Wl,--gc-sections#remove unused code
RLX = -Wl,--relax#linker relax
OPT = -Os#optimisation flags
all : hex upload
#only object/elf/hex, assume the rest are done
Oobject : 
	$(CC) $(OPT) $(DFS) -mmcu=$(MCC) -c $(SRC) $(AUXS) -I$(AUXH)
Oelf :
	$(CC)  -mmcu=$(MCC) -o $(NAME).elf *.o $(RUC) $(RLX)
Ohex : 
	$(OBC) -j .text -j .data -j .eeprom -O ihex $(NAME).elf $(NAME).hex

object	:	Oobject
elf		:	object Oelf
hex		:	elf Ohex clean

terminal :
	$(DD) -p $(MCA) -b $(BAUD) -c $(PROG) -P $(PORT) -t

#asume .hex exists
upload :
	$(DD) -p $(MCA) -b $(BAUD) -c $(PROG) -P $(PORT) \
	-U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m \
	-U efuse:w:$(EFUSE):m \
	-U flash:w:$(NAME).hex:i
check	:
	$(DD) -p $(MCA) -b $(BAUD) -c $(PROG) -P $(PORT)
clean	:
	@rm -rf *.o
	@rm -rf $(NAME).elf
fclean	: clean
	@rm -rf	$(NAME).hex
re		: fclean all
 
