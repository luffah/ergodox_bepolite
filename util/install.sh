#!/bin/sh
set +x


zenity --info --title='Ready to install !' --text \
  'The .hex file is made..\nTo continue, enter your sudo password,\nand be ready to press on the reset button.\nEntering no or wrong password will abort.' 2> /dev/null 

t_pass="`zenity --password --title=Authentication 2> /dev/null`"
[ -z "${t_pass}" ] && exit 1

zenity --timeout 5 --info --text \
  "Now, you have 5 seconds to press on the reset button. (Press enter to go faster)" 2> /dev/null

echo "${t_pass}" | sudo -S teensy_loader_cli/teensy_loader_cli -w -r --mcu=atmega32u4 qmk_firmware/${1}.hex
if [ "$?" -eq "0" ]
then 
  zenity --timeout=3 --info --text "Transfer done" 2> /dev/null 
else
  zenity --timeout=5 --warning --text "It looks like the reset button had not been pressed" 2> /dev/null 
fi
