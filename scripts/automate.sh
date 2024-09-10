[[ -z "$(pwd | grep -q "src")" ]] && { echo -e "Wrong directory!\nExiting..."; exit; } # check if we are in src

for dir in *; # ./src
do

  # check if a chosen directory contains a
  # .c file, echo that directory name or if the directory doesn't contain a .c file then continue on to the next iteration
  [[ -z "$(ls $dir | grep ".c")" ]] && continue;

  printf "\e[4;32m%s\e[0m\n\n" "${dir}";
  cd "${dir}" || exit;

  # echo the name of the .c file, compile, execute, remove, sleep, and repeat
  for file in *.c;
  do
    printf "\e[1;32m%s\e[0m:\n" "${file}";
    # i added an input file so some programs that require input can read from it
    cc "${file}" && bash geninput 2> /dev/null | ./a.out && rm "${_}"; #cc $file && ./a.out < input && rm $_;
    printf "\n"; sleep 0.25;
  done
  (cd ..);
done
exit 0 # success
