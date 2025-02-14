echo "Enter the first number"
read one
echo "Enter the second number"
read two
if((one > two))
then
	echo $one" is greater than "$two
else
	echo $two" is greater than "$one
fi
