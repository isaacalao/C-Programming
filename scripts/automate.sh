[[ -z "$(pwd | grep "src")" ]] && (echo -e "Wrong directory!\nExiting..."; exit) # check if we are in src

for dir in *; # ./src
do

  # check if a chosen directory contains a
  # .c file, echo that directory name or if the directory doesn't contain a .c file then continue on to the next iteration
  [[ -z "$(ls $dir | grep ".c")" ]] && continue;

  echo -e "\e[4;32m$dir\e[0m\n";
  cd $dir;

  # echo the name of the .c file, compile, execute, remove, sleep, and repeat
  for file in *.c;
  do
    echo -e "\e[1;32m${file}\e[0m:";
    # i added an input file so some programs that require input can read from it
    cc $file && bash geninput 2> dev/null | ./a.out && rm $_; #cc $file && ./a.out < input && rm $_;
    echo -e "\n"; sleep 0.25;
  done
  cd ..;
done
exit 0 # success
