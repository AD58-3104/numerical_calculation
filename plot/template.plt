# clear
set term wxt size 1280,960
set terminal wxt font "Arial,21"
set multiplot layout 2,1
set xrange[0:2]
set xlabel "x axis"
set ylabel "y axis"
set yrange[-0.1:0.1]
#set zlabel "z axis"
#set zrange[0:10]
plot "data1.dat" using 1:2 title "y value" with linespoints ps 1 pt 7
set xrange[0:5]
set yrange[-0.4:1.4]
plot "data2.dat" using 1:2 title "z value" with linespoints ps 1 pt 7
unset multiplot
