#Not sure what to do with this
NUM_OF_FIELDS=4


def display_menu():
    #Displays menu to the user
    print("1. Add records\n"+\
          "2. Search records\n"+\
          "3. Modify records\n"+\
          "4. Delete records\n"+\
          "5. Count records\n"+\
          "6. Reverse records\n"+\
          "7. Remove duplicate records\n"+\
          "8. Quit\n")


def get_menu_choice():
    
    menu_choice=input("Enter choice (1-8): ")
    return menu_choice

def get_filename():
    filename=input("Enter a filename(without the extension '.txt'): ")
    return filename


def get_num_of_records(option):
    num_of_records=int(input("Enter the number of records to "+option+": "))
    return num_of_records

def add_record(filename):
    #appends a record to the text file
    with open(filename+".txt","a") as record_file:
        idnumber=input("Enter the ID number: ")
        record_file.write(idnumber+","+\
               input("Enter the name: ")+","+\
               input("Enter the age: ")+","+\
               input("Enter the college major: ")+"\n")


    return idnumber
    

def search_record(filename):
    idnumber=input("Enter the ID number you want to search for: ")

    """Goes through the text file and finds the ID number/key
       that matches idnumber variable. The split function
       puts the "record" in a list, with the values from each field."""
    with open(filename+".txt","r") as records:
        for line in records:
            #record becomes a list and the first item in it in every iteration is the key
            record=line.strip().split(",")
            if record[0]==idnumber:
                record_DNE=False
                break
            
            else:
                record_DNE=True
        if record_DNE==True:
            return False,idnumber
        else:
            return True,idnumber

def modify_record(filename):
    record_exists=False
    """Sort of like a temp file, the code below shows logic for a temporary memory store
    allRecords stores every record in list form, in the ram, like a temp file, then the list is used to re-write the file
    This is used for every function that would need a temp file."""
    idnumber=input("Enter the ID number that you want to modify the record for: ")
    
    with open(filename+".txt","r") as records:
        allRecords=records.readlines()

       
    with open(filename+".txt","w") as records:
        for line in allRecords:
            #turns the comma seperated values into items in a list so every item can be evaluated
            record=line.strip().split(",")

            #Once the key value is found for a particular record, which is in list form, the items in the list can be changed and then written back into the file
            if record[0]==idnumber:
                record_exists=True
                change_name=input("Do you want to change the name field? y/n: ")
                if change_name.lower()=="y":
                    record[1]=input("Enter the new name:")
                change_age=input("Do you want to change the age field? y/n: ")
                if change_age.lower()=="y":
                    record[2]=input("Enter the new age: ")
                    
                change_major=input("Do you want to change the major field? y/n: ")
                if change_major.lower()=="y":
                    record[3]=input("Enter the new college major: ")
                
                records.write(record[0]+","+record[1]+","+record[2]+","+record[3]+"\n")
            
            else:
                #writes every line, besides the one the user specified which is modified above
                records.write(line)
                
    return idnumber,record_exists#record_exists returns true or false if the record was found or not

def delete_record(filename):
    record_found=False
    idnumber=input("Enter the ID number that you want to delete the record for: ")
    with open(filename+".txt","r") as records:
        allRecords=records.readlines()

       
    with open(filename+".txt","w") as records:
        for line in allRecords:
            #turns the comma seperated values into items in a list so every item can be evaluated
            record=line.strip().split(",")
        
            if record[0]==idnumber:
                record_found=True
            
            else:
                records.write(line)
                
    return idnumber,record_found



def count_records(filename):
    with open(filename+".txt","r") as records:
        num_of_records=0
        for lines in records:
            num_of_records+=1
    return num_of_records

def reverse_records(filename):
    with open(filename+".txt","r") as records:
        allRecords=records.readlines()

    with open(filename+".txt","w") as records:
        #Could've used for line in allRecords[::-1], but might've been considered trivial
        for line in range(len(allRecords)-1,-1,-1):
            records.write(allRecords[line])


def remove_duplicate_records(filename):
    num_of_duplicate_records=0
    duplicates_removed=False
    with open(filename+".txt","r") as records:
        allRecords=records.readlines()

    with open(filename+".txt","w") as records:
        temp_allRecords=[]
        keys=[]
        
        for a_record in allRecords:
            a_record=a_record.strip().split(",")
            if a_record[0] not in keys:
                temp_allRecords.append(a_record[0]+","+a_record[1]+","+a_record[2]+","+a_record[3]+"\n")
                keys.append(a_record[0])     
                
            else:
                num_of_duplicate_records+=1
                duplicates_removed=True
        for i in temp_allRecords:
            records.write(i)
    return num_of_duplicate_records,duplicates_removed

                    

def display_output(menu_choice,success,idnumber,filename,num_of_records):
    #Prints a statement according to menu choice and if the function was successful or not.
    if menu_choice=="1":
        print("\nThe record with ID",idnumber,"has been added to the file",filename+".txt")
    elif menu_choice=="2":
        if success==True:
            print("\nThe record with ID",idnumber,"has been located in the file",filename+".txt")
        else:
            print("\nThe record with ID",idnumber,"does NOT occur in the file",filename+".txt")
    elif menu_choice=="3":
        if success==True:
            print("\nThe record with ID",idnumber,"has been modified in the file",filename+".txt")
        else:
            print("\nERROR: The record with ID",idnumber,"does NOT occur in the file",filename+".txt")
    elif menu_choice=="4":
        if success==True:
            print("\nThe record with ID",idnumber,"has been deleted from the file",filename+".txt")
        else:
            print("\nERROR: The record with ID",idnumber,"does NOT occur in the file",filename+".txt")
    elif menu_choice=="5":
        print("There are",num_of_records," records in the file",filename+".txt")
    elif menu_choice=="6":
        print("\nThe records have been reversed in the file",filename+".txt")
    elif menu_choice=="7":
        if success==True:
            print("\n"+str(num_of_records),"duplicate records have been removed from the file",filename+".txt")
        else:
            print("\nThere are no duplicate records to remove")

def main():
    while True:
        display_menu()
        menu_choice=get_menu_choice()
        if menu_choice=="1":
            filename=get_filename()
            for times in range(get_num_of_records("add")):
                display_output(menu_choice,True,add_record(filename),filename,None)
                
        elif menu_choice=="2":
            filename=get_filename()
            for times in range(get_num_of_records("search")):
                success,idnumber=search_record(filename)
                display_output(menu_choice,success,idnumber,filename,None)
                
        elif menu_choice=="3":
            filename=get_filename()
            for times in range(get_num_of_records("modify")):
                idnumber,success=modify_record(filename)
                display_output(menu_choice,success,idnumber,filename,None)
        elif menu_choice=="4":
            filename=get_filename()
            for times in range(get_num_of_records("delete")):
                idnumber,success=delete_record(filename)
                display_output(menu_choice,success,idnumber,filename,None)
        elif menu_choice=="5":
            filename=get_filename()
            display_output(menu_choice,True,None,filename,count_records(filename))
        
        elif menu_choice=="6":
            filename=get_filename()
            reverse_records(filename)
            display_output(menu_choice,True,None,filename,None)
            
        elif menu_choice=="7":
            filename=get_filename()
            num_of_duplicate_records,success=remove_duplicate_records(filename)
            display_output(menu_choice,success,None,filename,num_of_duplicate_records)
            
        elif menu_choice=="8":
            print("Quitting the program...")
            break
        else:
            #if the user inputs anything but numbers 1-8 then the error message below will print
            print("\nError: Invalid input")
            
main()
