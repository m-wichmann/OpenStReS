TARGET         = server
OBJ            = server.o uart.o rfm12.o
MCU_TARGET     = atmega16
OPTIMIZE       = -Os

DEFS           = -DF_CPU=3686400UL
LIBS           =

CC             = avr-gcc

CFLAGS         = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
LDFLAGS        = -Wl

OBJCOPY        = avr-objcopy
OBJCOPYFLAGS   = -O ihex $(TARGET).elf $(TARGET).ihex

AVRDUDE	       = avrdude
# TODO: create target to burn fuses
# -U lfuse:w:0x64:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m
DUDEFLAGS      = -v -p m16 -c stk500 -P /dev/ttyUSB0 -U $(TARGET).ihex

all: $(TARGET).elf

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

prog: all
	$(OBJCOPY) $(OBJCOPYFLAGS)
	$(AVRDUDE) $(DUDEFLAGS)

clean:
	rm -rf *.o $(TARGET).bin $(TARGET).elf $(TARGET).ihex *.lst *.map
