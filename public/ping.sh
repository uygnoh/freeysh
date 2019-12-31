#!/bin/bash
# 测试IP段 192.168.0.108~192.168.0.110 间的连通性 

PREFIX=192.168.0.
for i in `seq 108 110`
do
	echo -n "${PREFIX}$i "
	ping -c3 ${PREFIX}${i} &> /dev/null 
	if [ "$?" -eq 0 ];then
		echo "OK"
	else
		echo "Failed"
	fi
done

