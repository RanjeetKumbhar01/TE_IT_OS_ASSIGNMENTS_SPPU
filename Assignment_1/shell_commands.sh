

# 1) Print
echo "Students"

# 2) Remove spaces
echo -e "PES \bModern \bCollege \bOf \bEngineering"

# 3) Remove word behind \c
echo -e "Operating \cSystem"

# 4) Add new line
echo -e "Final \nSubmission"

# 5) Add tabs
echo -e "Operating \tSystem \tLab"

## ls

# 1) Long listing of files
ls -l

## read

# 1) Read value to variable and print
read name
echo "Hello $name!"

## cat

# 1) Show content of file
cat ./myaddressbook.txt

# 2) Copy the content of file source > destination
cat ./myaddressbook.txt > ../temp.txt

## touch

# 1) Creat file
touch tempfile.txt

## test

# 1) Return 0 if name == Ramesh else return 1 (used to check the previous command is succcessfully executed or not)
read name
test $name = Ramesh
echo $?

## Loops

# 1) For loop
for i in 1 2 3 4 5
do
    echo "Value of i $i"
done

# 2) While loop
num=0
while [ "$num" -lt 5 ]
do
    echo "Value of num $num"
    num=`expr $num + 1`
done

## Conditionals

# 1) If else block
read num
if [ `expr $num % 2` -eq 0 ]
then
    echo "$num is even"
else 
    echo "$num is odd"
fi


## grep

# 1) Return the line containing matching string (case insensitive)
grep -i 'ranjeet' ./myaddressbook.txt

# 2) Return the count/ occurance of given string
grep -c '20' ./myaddressbook.txt

# 3) Return the lines contains given string also adds line number at begining
grep -n '20' ./myaddressbook.txt


## sed 

# 1) Replace 20 with 30
sed 's/20/30/' ./myaddressbook.txt
