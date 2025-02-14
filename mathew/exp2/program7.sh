echo "enter 1.add 2.substract 3.divide 4.multiply"
read choice

echo "enter the first number"
read one

echo "Enter the second number"
read two


case $choice in
	1)o=$(($one+$two))
	echo "the sum of these two numbers is $o";;
	2)o=$(($one-$two))
	echo "the diffrence of these two numbers is $o";;
	3)o=$(($one/$two))
	echo "the quacient of these two numbers is $o";;
	4)o=$(($one*$two))
	echo "the product of these two numbers is $o";;
	*)echo "wrong choice"
esac

	
