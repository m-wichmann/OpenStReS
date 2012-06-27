TARGET         = clicker
OBJ            = clicker.o rfm12.o
MCU_TARGET     = atmega16
OPTIMIZE       = -Os

DEFS           = -DF_CPU=3686400UL
LIBS           =

CC             = avr-gcc

CFLAGS        =  -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) $(DEFS)
LDFLAGS       = -Wl

AVRDUDE		= avrdude
DUDEFLAGS	= -v -p m16 -c stk500 -P /dev/ttyUSB0 -U $(TARGET).elf

all: $(TARGET).elf

$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

prog: all
	$(AVRDUDE) $(DUDEFLAGS)

clean:
	rm -rf *.o $(TARGET).elf *.lst *.map
