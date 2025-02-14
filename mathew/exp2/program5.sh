echo "Enter the number"
read num
f=1
for((i=1;i<=num;i++))
do
	f=$(($f*$i))
done
echo "factorial of $num is $f"
