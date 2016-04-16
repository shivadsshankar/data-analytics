count=1
while read line
do
    if [ "$count" != "$line" ]
    then
        echo $count
        offset=$(echo $count $line | awk '{printf("%d",$2 - $1 - 1)}')
        while [ $offset -ne 0 ]
        do
            offset=$(($offset-1))
            count=$(($count+1))
            echo $count
        done
        count=$(($count+1))
    fi
    count=$(($count+1))
done < out2.txt

