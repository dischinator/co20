#!/usr/bin/env gnuplot
reset
set datafile separator ";"
set timefmt '%d.%m.%Y %H:%M:%S'
set xdata time
set autoscale
set yr [440:1000]
set title 'Air quality ' . system("date +%d.%m.%Y")
set xlabel 'Sample time'
set ylabel 'Value'

#set term dumb
set term png size 1500,500 transparent
set output '~/www/air-' . system("date +%F") . '.png'
rgb(r,g,b) = 65536 * int(r) + 256 * int(g) + int(b)
color(y) = y >= 700 ? y >= 800 ? rgb(255, 0, 0) : rgb(255, 128, 0) : rgb(51, 102, 0) 
plot 'air.csv' using 1:2:(color($2)) title 'Wet-dog-factor' with lines linecolor rgb variable
