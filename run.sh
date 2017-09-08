 #!/bin/bash
i=0
while [ $i -lt 20 ]; do
    ./bin/c.o &
    let i=i+1
done
wait // 等待执行完成 即可
exit 0