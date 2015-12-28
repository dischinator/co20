# Access function to read sensor values from the [co20](https://www.conrad.de/de/voltcraft-co-20-usb-luftqualitaetssensor-raumluftmessgeraet-usb-stick-zur-anzeige-der-luftqualitaet-auswerte-software-101316.html) air sensor

The co20 air sensor sold by conrad is produced by AppliedSensor.
It measures the general air quality.

## Requirements
To build you need to have [HID API](http://www.signal11.us/oss/hidapi/) installed.

### OSX
On OSX you can for example install it using homebrew by doing:

    brew install hidapi

### Windows
On Windows just download the current archive and extract it. For Windows you need to modify Makefile.mingw and set the path where you extracted HID API.
Also you need mingw to compile on Windows.

## Building
### OSX
Just run

    make

### Windows
Run
    mingw32-make

This will build the example application air_csv wich periodically reads the air value and writes it to air.csv

## Extra gimmick
I added a gnuplot file to create graphs based upon the created csv files. Just run air.p to generate them.
