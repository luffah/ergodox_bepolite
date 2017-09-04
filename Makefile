
all:warn transfer

warn:
	$(info Now, compiling ergodox_ez_bepolite.hex.)
	$(info Ensure you've run make in the root directory of this project.)
	$(info Too, you shall prepare a needle -for pressing on reset button- and your sudo password in order to transfer the firmware in your ergodox keyboard.)
	$(info ---------------------------------------------------------------)
	sleep 4

transfer: deps make_loader make_bepolite
	$(info ---------------------------------------------------------------)
	$(info The .hex file is made. Now the installation will start. )
	$(info Enter your sudo password. Next, press on reset button - with a needle )
	$(info You will have 4 seconds)
	sudo sleep 1
	@echo "...waiting... still 3 seconds"
	sleep 1
	@echo "...waiting... still 2 seconds"
	sleep 1
	@echo "...waiting... still 1 seconds"
	sleep 1
	@echo "Transfer begin"
	sudo teensy_loader_cli/teensy_loader_cli -w -r --mcu=atmega32u4 qmk_firmware/ergodox_ez_bepolite.hex || echo "It looks like the reset button had not been pressed"
	exit 0

make_bepolite:
	cp -ruT bepolite qmk_firmware/keyboards/ergodox/ez/keymaps/bepolite && \
		cd qmk_firmware/ && make ergodox-ez-bepolite

deps:
	sh util/check_dependencies.sh

make_loader:
	cd teensy_loader_cli && make

