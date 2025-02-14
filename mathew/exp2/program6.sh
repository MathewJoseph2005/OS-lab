echo "enter the range"
read n

fib=0
n1=1
n2=0
echo $per
echo $fib

for((i=2;i<=n;i++))
do
	fib=$(($n1+$n2))
	echo $fib
	n1=$n2
	n2=$fib
done

