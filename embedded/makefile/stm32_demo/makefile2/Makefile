# general Makefile

include Makefile.common

LDFLAGS=$(COMMONFLAGS) -fno-exceptions -ffunction-sections \
			-fdata-sections -L$(LIBDIR) \
			-nostartfiles -Wl,--gc-sections,-Tldscripts/linker.ld


# LDLIBS+=-lm
LDLIBS+=-lstm32

STARTUP=startup.c

all: libs src
	$(CC) -o Output/$(PROGRAM).elf $(LDFLAGS) \
		-Wl,--whole-archive \
			src/app.a \
		-Wl,--no-whole-archive \
			$(LDLIBS)
	$(OBJCOPY) -O ihex Output/$(PROGRAM).elf Output/$(PROGRAM).hex
	$(OBJCOPY) -O binary Output/$(PROGRAM).elf Output/$(PROGRAM).bin



#Extract info contained in ELF to readable text-files:
	arm-none-eabi-readelf -a Output/$(PROGRAM).elf > Output/$(PROGRAM).info_elf
	arm-none-eabi-size -d -B -t Output/$(PROGRAM).elf > Output/$(PROGRAM).info_size
	arm-none-eabi-objdump -S Output/$(PROGRAM).elf > Output/$(PROGRAM).info_code
	arm-none-eabi-nm -t x -S --numeric-sort -s Output/$(PROGRAM).elf > Output/$(PROGRAM).info_symbol


.PHONY: libs src clean tshow

libs:
	$(MAKE) -C libs $@
src:
	$(MAKE) -C src $@
clean:
	$(MAKE) -C src $@
	$(MAKE) -C libs $@
	rm -f Output/$(PROGRAM).elf Output/$(PROGRAM).hex \
		Output/$(PROGRAM).bin Output/$(PROGRAM).info_elf \
			Output/$(PROGRAM).info_size Output/$(PROGRAM).info_code \
				Output/$(PROGRAM).info_symbol
	
tshow:
	@echo "######################################################################################################"
	@echo "######## optimize settings: $(InfoTextLib), $(InfoTextSrc)"
	@echo "######################################################################################################"
