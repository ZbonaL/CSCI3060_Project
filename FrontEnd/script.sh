touch out.out
touch tempTran.trn
for t in "LoginInput" "LogoutInputs" "AddCreditInputs" "BuyInput" "CreateInput" "DeleteInput" "RefundInput" "SellInput"
  do
	echo "Running tests for: $t"
	for i in ../Tests/TestInputs/$t/*.input
	  do
		# echo "${i%.input}"
		echo "$i"
		# cat "$i"
		./output < $i
    done    
done

