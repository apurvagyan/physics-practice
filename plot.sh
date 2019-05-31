#!/bin/bash
bazel run :main > setpoints.csv
gnuplot -e "
  set datafile separator ',';
  set title 'Trapezoidal Motion Profile';
  set key outside;
  plot 'setpoints.csv' using 1:2 title 'position',
                    '' using 1:3 title 'velocity';
  pause mouse close
"
