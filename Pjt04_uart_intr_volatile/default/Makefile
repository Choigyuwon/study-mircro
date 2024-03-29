###############################################################################
# Makefile for the project Pjt04_uart_intr_volatile
###############################################################################

## General Flags
PROJECT = Pjt04_uart_intr_volatile
MCU = atmega2560
TARGET = Pjt04_uart_intr_volatile.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -DF_CPU=7372800UL -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=Pjt04_uart_intr_volatile.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = app.o led.o main.o uart2.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) Pjt04_uart_intr_volatile.hex Pjt04_uart_intr_volatile.eep Pjt04_uart_intr_volatile.lss size

## Compile
app.o: ../../Pjt03_uart_stdout/app.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

led.o: ../../Pjt03_uart_stdout/led.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

main.o: ../../Pjt03_uart_stdout/main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

uart2.o: ../../Pjt03_uart_stdout/uart2.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) Pjt04_uart_intr_volatile.elf dep/* Pjt04_uart_intr_volatile.hex Pjt04_uart_intr_volatile.eep Pjt04_uart_intr_volatile.lss Pjt04_uart_intr_volatile.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

