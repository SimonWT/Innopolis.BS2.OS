echo 68 > ex2_file #Critical region

if ln ex2_file ex2_file.lock
  then
  for i in `seq 1 66`;
  do
    NUM=`tail -1 ex2_file`
    NUM=$((NUM+1))
    echo $NUM >> ex2_file #Critical region
  done
  rm ex2_file.lock
fi

