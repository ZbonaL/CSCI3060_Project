touch out.out
touch tempTran.trn
# this first loop goes throught all the test inpuput folders
for t in "AddCreditInputs" "BuyInput" "CreateInput" "DeleteInput" "LoginInput" "LogoutInputs" "RefundInput" "SellInput"
	do
		echo "Running tests for: $t"
		#this loop goes through the actual inputs and adds them,
		for i in ../Tests/TestInputs/$t/*.input
	  		do
				#echo "$i"
				# cat "$i"
				echo "${i%.input}" > tempTran.trn
				#input the data from the input files into the c++ program
				cat "$i" | ./output tempTran.trn > out.out
		done    
done
#loop through all the folders in the output dir
for j in "AddCreditOutputs" "BuyOutput" "CreateOutput" "DeleteOutput" "LoginOutput" "LogoutOutput" "RefundOutput" "SellOutput"
	do	
		echo "Checking tests for: $j"
		#loop through each of the test outputs 
		for h in ../Tests/Results/$j/*.output
			do	
				#echo "$out.out"
				#check if the out.out file is the same as the test outputs
				if diff out.out $h;
				then 
					echo "test $j good"
				else
					echo "test $j failed"
				fi
				rm out.out
				rm tempTran.trn
				touch out.out
				touch tempTran.trn
		done
done
rm out.out
rm tempTran.trn