awk '{printf("%s\n%s\n",$1,$2)}'  $1 > new.txt
sort -n new.txt | uniq > sorted.txt
