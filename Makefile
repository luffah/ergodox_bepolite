
make_bepolite:
	cp -ruT bepolite qmk_firmware/keyboards/ergodox/ez/keymaps/bepolite && \
	 	cd qmk_firmware/ && make ergodox-ez-bepolite


transfer: make_bepolite
	sudo echo "Press on reset (4 seconds)" 
	sleep 4
	echo "Transfer begin"
	sudo teensy_loader_cli/teensy_loader_cli -w -r --mcu=atmega32u4 qmk_firmware/ergodox_ez_bepolite.hex
	exit 0
