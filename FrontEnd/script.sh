touch out.out
touch tempTran.trn
for t in "AddCreditInputs" "BuyInput" "CreateInput" "DeleteInput" "LoginInput" "LogoutInputs" "RefundInput" "SellInput"
    do
        echo "Running tests for: $t"
        for i in ../Tests/TestInputs/$t/*.input
              do
                #echo "$i"
                # cat "$i"
                echo "${i%.input}" 
                cat "$i" | ./output > out.out
        done    
done
#this loops through the output test folders
for j in "AddCreditOutputs" "BuyOutput" "CreateOutput" "DeleteOutput" "LoginOutput" "LogoutOutput" "RefundOutput" "SellOutput"
    do    
        echo "Checking tests for: $j"
        # loops for every file in the test folder
        for h in ../Tests/Results/$j/*.output
            do  

                if diff out.out $h
                then
                    echo "test $h failed"
                else
                    echo "test $h worked"
                fi
            
                rm out.out
                rm tempTran.trn
                touch out.out
                touch tempTran.trn
        done
done
rm out.out
rm tempTran.trn