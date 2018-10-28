touch -A -000001 -a bomb.txt
stat -s bomb.txt | cut -d " " -f 9 | cut -c 10-
exec sh
