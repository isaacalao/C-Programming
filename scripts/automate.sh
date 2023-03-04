for dir in *; # ./src
do

  # check if a chosen directory contains a
  # .c file, output that directory name and then add all the corresponding .c files to an array
  [[ -z "$(ls $dir | grep ".c")" ]] && continue;

  #echo -e "\e[4;32m$dir\e[0m\n";
  cd $dir;

  # echo the name of the .c file, compile, execute, remove, sleep, and repeat
  for file in *.c;
  do
    echo "$file"
    echo -e "\e[1;32m${file}\e[0m:";
    cc $file && ./a.out < "input.txt" && rm $_;
    echo -e "\n"; sleep 0.25;
  done
  cd ..;
done
exit 0 # success
