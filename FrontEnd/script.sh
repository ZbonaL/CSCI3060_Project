touch out.out
touch tempTran.trn
for t in "LoginInput" "LogoutInputs" "AddCreditInputs" "BuyInput" "CreateInput" "DeleteInput" "RefundInput" "SellInput"
  do
		echo "Running tests for: $t"
		for i in ../Tests/TestInputs/$t/*.input
	  	do
				#echo "$i"
				# cat "$i"
				cat "$i" | ./output tempTran > out.out
				for j in "LoginOutput" "LogoutOutput" "AddCreditOutputs" "BuyOutput" "CreateOutput" "DeleteOutput" "RefundOutput" "SellOutput"
					do
						for h in ../Tests/Results/$j/*.output
							do
								diff out.out "${h%}"
								rm out.out
								rm tempTran.trn
								touch out.out
								touch tempTran.trn
						done
				done
		done    
done

rm out.out
rm tempTran.trn