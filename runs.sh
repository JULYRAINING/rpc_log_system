#!/bin/bash
i=0
while [ $i -lt 5 ]; do
    ./bin/c.o &
    let i=i+1
done
wait
exit 0
