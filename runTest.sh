#! /bin/bash

# if an executable is not built, build.
if ! [[ -f "simplifyFunction" ]] ; then
	make 
	# wait for make
	sleep 0.5
fi

# declare two input test variables
two_input_test_one="f(x,y)=sum(0,3)"
two_input_test_two="f(x,y)=sum(1,2,3)"
two_input_test_three="f(x,y)=sum(0,1,2)"

# declare three input test variables
three_input_test_one="f(x,y,z)=sum(0,1,3,5,6,7)"
three_input_test_two="f(x,y,z)=sum(0,2,4,6)"
three_input_test_three="f(x,y,z)=sum(4,5,6,7)"

# declare four input test variables
four_input_test_one="f(x,y,z,w)=sum(1,5,9,13)"
four_input_test_two="f(x,y,z,w)=sum(4,5,6,7,12,13,14,15)"
four_input_test_three="f(x,y,z,w)=sum(0,2,8,10)"


echo "==================== START ===================="

echo "===== TEST ONE ====="
echo "Running function: $two_input_test_one  "
echo
./simplifyFunction $two_input_test_one

echo "===== TEST TWO ====="
echo "Running function: $two_input_test_two  "
echo
./simplifyFunction $two_input_test_two

echo "===== TEST THREE ====="
echo "Running function: $two_input_test_three  "
echo
./simplifyFunction $two_input_test_three

echo "===== TEST FOUR ====="
echo "Running function: $three_input_test_one  "
echo
./simplifyFunction $three_input_test_one

echo "===== TEST FIVE ====="
echo "Running function: $three_input_test_two  "
echo
./simplifyFunction $three_input_test_two

echo "===== TEST SIX ====="
echo "Running function: $three_input_test_three  "
echo
./simplifyFunction $three_input_test_three

echo "===== TEST SEVEN ====="
echo "Running function: $four_input_test_one  "
echo
./simplifyFunction $four_input_test_one

echo "===== TEST EIGHT ====="
echo "Running function: $four_input_test_two  "
echo
./simplifyFunction $four_input_test_two

echo "===== TEST NINE ====="
echo "Running function: $four_input_test_three  "
echo
./simplifyFunction $four_input_test_three

echo "==================== END ===================="

# return control
exit
