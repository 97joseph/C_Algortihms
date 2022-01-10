import os
#displays menu
def display_menu():
    print("----- MENU -----\n"+\
          "1. Add Division\n"+\
          "2. Modify Division\n"+\
          "3. Delete Division\n"+\
          "4. Add Department\n"+\
          "5. Modify Department\n"+\
          "6. Delete Department\n"+\
          "7. Add Course\n"+\
          "8. Modify Course\n"+\
          "9. Delete Course\n"+\
          "10.Print Cuesta Dictionary\n"+\
          "11.Quit\n"
          )
#########Get functions
def get_menu_choice():
    menu_choice=input("Enter choice (1-11): ")
    return menu_choice


def get_division(option):
    Division=input("Enter the division: ")
    return Division

#gets department
def get_department(option):
    Department=input("Enter the department: ")
    return Department
    
def get_courses(courses,option):
    if option=="7":
        courses["Course_Number"]=input("Enter the new course number: ")
        courses["Course_Title"]=input("Enter the new course title: ")
        courses["Course_Units"]=input("Enter the new course units: ")

    #Assuming the option affects the course dictionary outputted
    elif option=="8":
        change_course_number=input("Do you want to change the course number? (Y/N)")
        if change_course_number=="Y":
            courses["Course_Number"]=input("Enter the new course number: ")
        change_course_title=input("Do you want to change the course title? (Y/N)")
        if change_course_title=="Y":
            courses["Course_Title"]=input("Enter the new course title: ")
        change_course_units=input("Do you want to change the course units? (Y/N)")
        if change_course_units=="Y":
            courses["Course_Units"]=input("Enter the new course units: ")

    return courses

    

def build_cuesta_dict():
    cuesta={}
    try:
        #if file exists then it will read from the cuesta file to build the dictionary
        with open("cuesta.txt","r") as cuesta_file:
            division_line=cuesta_file.readline().split(",")
            for division in division_line:
                #checks if division is an empty string
                if len(division)>0:
                    cuesta[division]={}
                    with open(division+".txt","r") as division_file:
                        department_line=division_file.readline().split(",")
                        for department in department_line:
                            if len(department)>0:
                                cuesta[division][department]=[]
                                with open(department+".txt","r") as department_file:
                                    for course_line in department_file:
                                        course_info=course_line.split(",")
                                        course={}
                                        course["Course_Number"]=course_info[0]
                                        course["Course_Title"]=course_info[1]
                                        course["Course_Units"]=course_info[2].rstrip("\n")
                                        cuesta[division][department].append(course)


    except FileNotFoundError:
        #creates a new file if no file exists and then tries to read file
        with open("cuesta.txt","w") as cuesta_file:
            pass
    
    return cuesta

    



######  Write
def write_cuesta_file(cuesta):
    with open("cuesta.txt","w") as cuesta_file:
        keys_list=list(cuesta.keys())
        for key in keys_list:
            if keys_list[-1]==key:
                cuesta_file.write(key)
            else:
                cuesta_file.write(key+",")
                        
            

def write_division_file(cuesta,division):
    with open(division+".txt","w") as division_file:
        departments=cuesta[division]
        item_number=1
        for sub_key in reversed(list((departments.keys()))):
            length=len(departments.keys())
        
            if (length==1)or (item_number==length and length!=1):
                 division_file.write(sub_key)
            else:
                division_file.write(sub_key+",")
            item_number+=1
        
def write_department_file(cuesta,division,department):
    with open(department+".txt","w") as department_file:
            
        courses=cuesta[division][department]
        
        for course in courses:
            department_file.write(course["Course_Number"]+","+course["Course_Title"]+","+course["Course_Units"]+"\n")


######Division
def add_division(cuesta,division):
    success=True
    if division in cuesta.keys():
        success=False
    else:
        cuesta[division]={}
        
    return cuesta,success

def modify_division(cuesta,old_division,new_division):
    try:
        cuesta[new_division] = cuesta.pop(old_division)
        os.rename(old_division+".txt",new_division+".txt")
        success=True
    except FileNotFoundError:
        success=False
        
    return cuesta,success

#deletes division and files
def delete_division(cuesta,division):
    try:
        files_to_delete=[division]
        for department in cuesta[division].keys():
            files_to_delete.append(department)

        for file in files_to_delete:
            #os module used to delete text files
            os.remove(file+".txt")
        del cuesta[division]
        success=True

    except (FileNotFoundError,KeyError):
        success=False
    
    return cuesta, success

##########Department
def add_department(cuesta,division,department):
    try:
        if type(cuesta[division][department])==type([]):
            success==False
    except KeyError:
        #KeyError if department doesn't exist and adds to the
        cuesta[division][department]=[]
        success=True
    return cuesta, success


    

def modify_department(cuesta,division,old_department,new_department):
    try:
        cuesta[division][new_department]= cuesta[division].pop(old_department)
        #os module used to rename text files
        os.rename(old_department+".txt",new_department+".txt")
        success=True
    except (KeyError,FileNotFoundError):
        success=False
        
    return cuesta,success

def delete_department(cuesta,division,department):
    success=True
    try:
        os.remove(department+".txt")
        del cuesta[division][department]
    except FileNotFoundError:
        success=False
    
    return cuesta, success


##############Courses
def add_course(cuesta,division,department,course):
    if course in (cuesta[division][department]):
        pass
    
    else:
        cuesta[division][department].append(course)
    
    return cuesta, True


def modify_course(cuesta,division,department,course,course_number):
    success=True
    courses=cuesta[division][department]
    if len(courses)==0:
        success=False
    else:
        for course_item in courses:
            if course_item["Course_Number"]==course_number:
                for key in course.keys():
                    course_item[key]=course[key]

    return cuesta,success

def delete_course(cuesta,division,department,course_number):
    courses=cuesta[division][department]

    #if list isn't empty the else statement will execute
    if len(courses)==0:
        success=False
        return cuesta, success
    else:
        for course in courses:
            if course["Course_Number"]==course_number:
                del cuesta[division][department][cuesta[division][department].index(course)]
                success=True
        return cuesta,success


###########Final
def display_output(success,option,division,department,course_number):
    #displays output if functions were successful
    if success==True:
        if option=="1":
            print("\nThe division",division,"has been added")

        elif option=="2":
            print("\nThe new division name is",division)

        elif option=="3":
            print("\nThe division",division,"has been deleted")

    
        elif option=="4":
            print("\nThe department",department,"has been added within the division",division)

        elif option=="5":
            print("\nThe new department name is",department,"within the division",division)

        elif option=="6":
            print("\nThe department",department,"has been deleted from the division",division)

        elif option=="7":
            print("\nThe course with course number",course_number,"has been added within the department",department)

        elif option=="8":
            print("\nThe course with course number",course_number,"has been modified within the department",department)

        elif option=="9":
            print("\nThe course",course_number,"has been deleted from the department",department)

    #prints error message if not successful, (since no error message was said to be displayed if functions were unseccessful in the sample test runs 
    else:
        print("Error: action could not be completed, please input valid/existing data")


#Prints a formated version of the cuesta dictionary
def print_cuesta_dict(cuesta):
    print("----- Cuesta Dictionary -----\n")
    for division in cuesta.keys():
        print("\tDivision: "+division)
        for department in cuesta[division].keys():
            print("\t\tDepartment: "+department)
            for courses in cuesta[division][department]:
                print("\t\t\tCourse Number: "+courses["Course_Number"]+"\n"+\
                      "\t\t\t\tCourse Title: "+courses["Course_Title"]+"\n"+\
                      "\t\t\t\tCourse Units: "+courses["Course_Units"])
def main():
    
    cuesta=build_cuesta_dict()
    while True:
        display_menu()
        menu_choice=get_menu_choice()
        
        if menu_choice=="1":
            division=get_division(menu_choice)
            cuesta,success=add_division(cuesta,division)
            write_cuesta_file(cuesta)
            write_division_file(cuesta,division)
            display_output(success,menu_choice,division,None,None)

        elif menu_choice=="2":
            #since get_division doesn't return old and new divisions
            old_division=input("Enter the old division: ")
            new_division=input("Enter the new division: ")
            cuesta,success=modify_division(cuesta,old_division,new_division)
            write_cuesta_file(cuesta)
            display_output(success,menu_choice,new_division,None,None)
        
        elif menu_choice=="3":
            division=get_division(menu_choice)
            cuesta,success=delete_division(cuesta,division)
            write_cuesta_file(cuesta)
            display_output(success,menu_choice,division,None,None)
        
        elif menu_choice=="4":
            division=get_division(menu_choice)
            department=get_department(menu_choice)
            cuesta,success=add_department(cuesta,division,department)
            write_division_file(cuesta,division)
            write_department_file(cuesta,division,department)
            display_output(success,menu_choice,division,department,None)

        elif menu_choice=="5":
            division=get_division(menu_choice)
            old_department=input("Enter the old department: ")
            new_department=input("Enter the new department: ")
            cuesta,success=modify_department(cuesta,division,old_department,new_department)
            write_division_file(cuesta,division)
            display_output(success,menu_choice,division,new_department,None)
            
        elif menu_choice=="6":
            division=get_division(menu_choice)
            department=get_department(menu_choice)
            cuesta,success=delete_department(cuesta,division,department)
            write_cuesta_file(cuesta)
            write_division_file(cuesta,division)
            display_output(success,menu_choice,division,department,None)
        
        elif menu_choice=="7":
            division=get_division(menu_choice)
            department=get_department(menu_choice)
            courses={}
            course=get_courses(courses,menu_choice)
            cuesta,success=add_course(cuesta,division,department,course)
            write_department_file(cuesta,division,department)
            display_output(success,menu_choice,division,department,course["Course_Number"])

        elif menu_choice=="8":
            division=get_division(menu_choice)
            department=get_department(menu_choice)
            course_number=input("Enter the course number of the course that you want to modify: ")
            
            #set to global because it couldn't be found in the function below, variable name is unique for the global variable
            courses_to_modify={}
            cuesta,success=modify_course(cuesta,division,department,get_courses(courses_to_modify,menu_choice),course_number)
            write_department_file(cuesta,division,department)
            display_output(success,menu_choice,division,department,course_number)
                    

        elif menu_choice=="9":
            division=get_division(menu_choice)
            department=get_department(menu_choice)
            course_number=input("Enter the course number of the course that you want to delete: ")
            cuesta,success=delete_course(cuesta,division,department,course_number)
            write_department_file(cuesta,division,department)
            display_output(success,menu_choice,division,department,course_number)
            
        elif menu_choice=="10":
            print_cuesta_dict(cuesta)
            
            
        elif menu_choice=="11":
            print("Quitting the program...")
            break

        else:
            print("ERROR: invalid input (must be 1-11)")
        

main()
