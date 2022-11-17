#!/bin/bash

clear

choice=0

address_book='addressbook'

while test $choice != 7
  do
    echo -e "\n------------------------------"
    echo "1 --> Create"
    echo "2 --> View"
    echo "3 --> Insert"
    echo "4 --> Delete"
    echo "5 --> Modify"
    echo "6 --> Search"
    echo -e "7 --> Exit\n"
    read -p "Enter your choice: " choice
    
    case "$choice" in 
      "1")
      	echo ""
        read -p "Enter address book name: " address_book
        
        touch D:/Ubuntu18/osl/practical1/$address_book.txt
        
        if [ $? -eq 0 ]
          then
            echo -e "\n$address_book.txt created."
        else
          echo "Could not create $address_book.txt"
        fi
        ;;
      
      "2")
        echo -e "\n---- Record of address book ---- \n"
        cat D:/Ubuntu18/osl/practical1/$address_book.txt
        echo ""
        
        if [ $? -ne 0 ]
          then
            echo "Could not read $address_book.txt"
        fi
        ;;
        
      "3")      
       	# Name validation
        read -p "Enter name: " name
        name_pattern="^[A-Za-z]"
        while [[ ! "$name" =~ $name_pattern ]]
          do
            read -p "Please enter valid name: " name
          done
          
        # Email validation
        read -p "Enter email : " email
        email_pattern="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
        while [[ ! $email =~ $email_pattern ]]
      	  do
      	    read -p "Please enter valid email: " email
      	  done
	  
      	# Phone number validation
        read -p "Enter phone number : " phno
        phno_pattern="^[0-9]{10,12}$"
        while [[ ! $phno =~ $phno_pattern ]]
      	  do
      	    read -p "Please enter valid phone number: " phno
      	  done
	  
      	# Age validation
        read -p "Enter age : " age
        age_pattern="[0-9]"
        while [[ ! $age =~ $age_pattern ]]
      	  do
      	    read -p "Please enter valid age: " age
      	  done
      	  
      	# Address validation
        read -p "Enter address : " address
        address_pattern="^[A-Za-z0-9]"
        while [[ ! $address =~ $address_pattern ]]
      	  do
      	    read -p "Please enter valid address: " address
      	  done
        
        echo $name $email $phno $age $address >> D:/Ubuntu18/osl/practical1/$address_book.txt
        
        if [ $? -eq 0 ]
          then
            echo -e "\nData inserted to $address_book.txt."
        else
          echo "Could not insert data to $address_book.txt"
        fi
        ;;
        
      "4")  
      	echo -e "\n---- Record of address book ---- \n"
        cat D:/Ubuntu18/osl/practical1/$address_book.txt
        
        echo ""
        read -p "Enter user name to delete record: " delete_name
        
        sed -i "/$delete_name/d" D:/Ubuntu18/osl/practical1/$address_book.txt
        
        if [ $? -ne 0 ]
          then 
            echo "Could not delete data in $address_book.txt"
        else
          echo -e "\n---- Record of address book ---- \n"
          cat D:/Ubuntu18/osl/practical1/$address_book.txt
        fi
        
        ;;
        
      "5")   
        echo -e "\n---- Record of address book ---- \n"
        cat D:/Ubuntu18/osl/practical1/$address_book.txt
        
        echo -e "\nEnter number to modify: "
        read search_string
        
        echo "Enter new number to modify: "
        read modify_string
        
        sed -i "s/$search_string/$modify_string/" D:/Ubuntu18/osl/practical1/$address_book.txt
        
        if [ $? -ne 0 ]
          then 
            echo "Could not modify $address_book.txt"
        else
          echo -e "\n---- Record of address book ---- \n"
          cat D:/Ubuntu18/osl/practical1/$address_book.txt
        fi
        ;;
        
      "6")    
      	echo ""
        read -p "Enter name to search: " search_string
        
        echo -e "\n---- Search result ---- \n"
        grep -i $search_string D:/Ubuntu18/osl/practical1/$address_book.txt
        
        if [ $? -ne 0 ]
          then
            echo "Could not search data in $address_book.txt"
        fi
        ;;


      "7")
        echo "Exit."
        exit
        ;;
    esac
  done
exit
        
       
: '
OUTPUT
' 
