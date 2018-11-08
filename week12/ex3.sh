dd if=/dev/random of=bigfile bs=1024k count=100000
gcc copy.c -o copy -D BUF_SIZE=1024 && (time ./copy bigfile fileB.txt)&>>ex3.txt
gcc copy.c -o copy -D SYNC=1 -D BUF_SIZE=1024 && (time ./copy bigfile fileB.txt)&>>ex3.txt
gcc copy.c -o copy -D BUF_SIZE=3072 && (time ./copy bigfile fileB.txt)&>>ex3.txt
gcc copy.c -o copy -D SYNC=1 -D BUF_SIZE=3072 && (time ./copy bigfile fileB.txt)&>>ex3.txt
