awk '{printf("%s\n%s\n",$1,$2)}'  $1 > temp1.txt
sort -u -n temp1.txt > sort_vertices.txt
while read line; do 
    
vertex1=$(echo $line|awk '{printf("%s\n",$1)}')
vertex2=$(echo $line|awk '{printf("%s\n",$2)}')

#echo $vertex1 $vertex2..$line
first=$(awk '{if("'$vertex1'"== $0){printf("%d ",NR)}}' sort_vertices.txt)
second=$(awk '{if("'$vertex2'"== $0){printf("%d ",NR)}}' sort_vertices.txt)

echo $first $second
done < $1

