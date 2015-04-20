#!/bin/sh


echo "please input the grade"
read var1
if [ $var1 -lt 0 ]
then
	echo "the grade is invalid!"
	exit
else 
	if [ $var1 -gt 100 ]
	then
		echo "the grade is invalid"
		exit
	fi
fi

score=` expr $var1 / 10`
	case $score in
		10)
			echo "excellent"
				;;
		9)
			echo "fine"
				;;
		8)
			echo "good"
				;;
		7)
			echo "medium"
				;;
		6)
			echo "passing"
				;;
		*)
			echo "fail"
				;;
	esac




