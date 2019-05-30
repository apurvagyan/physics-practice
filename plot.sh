#!/bin/bash
bazel run :main > setpoints.csv
gnuplot -e "
  set datafile separator \",\";
  set title \"Trapezoidal Motion Profile\";
  plot \"setpoints.csv\" using 1:2;
  pause mouse close
"
