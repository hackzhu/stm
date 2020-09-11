TARGET=test
PWD=$(shell pwd)
WARE=$(patsubst %,-I $(PWD)/ware/%,$(shell ls $(PWD)/ware))

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
CPUFLAGS=-mthumb -mcpu=cortex-m3
LDFLAGS = -T $(PWD)/lib/stm32_flash.ld -Wl,-cref,-u,Reset_Handler -Wl,-Map=$(TARGET).map -Wl,--gc-sections -Wl,--defsym=malloc_getpagesize_P=0x80 -Wl,--start-group -lc -lm -Wl,--end-group
INCFLAGS=-I $(PWD)/lib -I $(PWD)/lib/inc -I $(PWD)/sys $(WARE)
CFLAGS=$(INCFLAGS) -D STM32F10X_HD -D USE_STDPERIPH_DRIVER -Wall -g -o

INTERFACE_CFG=/usr/share/openocd/scripts/interface/stlink.cfg
TARGET_CFG=/usr/share/openocd/scripts/target/stm32f1x.cfg

C_SRC=$(shell find . -name '*.c')
C_OBJ=$(C_SRC:%.c=%.o)

START_SRC=$(shell find . -name startup_stm32f10x_hd.s)
START_OBJ=$(START_SRC:%.s=%.o)

$(TARGET):$(START_OBJ) $(C_OBJ)
	$(CC) $^ $(CPUFLAGS) $(LDFLAGS) $(CFLAGS) $(TARGET).elf
	$(OBJCOPY) $(TARGET).elf -Oihex $(TARGET).hex
$(START_OBJ):$(START_SRC)
	$(CC) -c $^ $(CPUFLAGS) $(CFLAGS) $@
$(C_OBJ):%.o:%.c
	$(CC) -c $^ $(CPUFLAGS) $(CFLAGS) $@

.PHONY: hex bin clean download flash
hex:
	$(OBJCOPY) $(TARGET).elf -Oihex $(TARGET).hex
bin:
	$(OBJCOPY) $(TARGET).elf $(TARGET).bin
clean:
	rm -f $(shell find . -name '*.o') $(TARGET).*
download:
	openocd -f $(INTERFACE_CFG) -f $(TARGET_CFG) -c init -c halt -c "flash write_image erase $(PWD)/$(TARGET).hex" -c reset -c shutdown
flash:
	st-flash --format ihex write $(TARGET).hex
