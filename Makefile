
all:warn transfer

warn:
	$(info Compiling ergodox_ez_bepolite.hex.)

transfer: deps make_loader make_bepolite
	$(info ---------------------------------------------------------------)
	$(info Enter your sudo password. Next, press on reset button - with a needle )
	$(info You will have 5 seconds)
	sh util/install.sh

make_bepolite:
	cp -ruT bepolite qmk_firmware/keyboards/ergodox/ez/keymaps/bepolite && \
		cd qmk_firmware/ && make ergodox-ez-bepolite

deps:
	sh util/check_dependencies.sh

make_loader:
	cd teensy_loader_cli && make

