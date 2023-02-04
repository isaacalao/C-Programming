for dir in *; # ./src
do
 
  # check if the first directory contains a 
  # .c file, echo that dir name and then add all the .c files to an array
  [[ -z "$(ls $dir | grep ".c")" ]] && continue;

  echo -e "\e[4;32m$dir\e[0m\n";
  cd $dir; dir=( *.c );
  
  # echo the name of the .c file, compile, execute, remove, sleep, and repeat
  for file in $dir;
  do
    echo -e "\e[1;32m${file}\e[0m:";
    cc $file && ./a.out && rm $_;
    echo -e "\n"; sleep 0.25;
  done

  cd ..;
done
exit 0 # exit successfully
