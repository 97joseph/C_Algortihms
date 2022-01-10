def display_menu():
    print("\n----- File Operations Menu -----\n\n" + \
      "1. Set key\n" + \
      "2. Modify key\n" + \
      "3. Add student answers\n" + \
      "4. Delete student answers\n" + \
      "5. Modify student answers\n" + \
      "6. Print key\n" + \
      "7. Print student answers\n" + \
      "8. Print student scores\n" + \
      "9. Quit\n")


def get_menu_choice():
    menu_choice=input("Enter choice (1-9): ")
    return menu_choice


def get_filename():
    key_filename = input("Enter the filename for the key: ")
    answers_filename = input("Enter the filename for the student answers: ")
    scores_filename = input("Enter the filename for the student scores: ")
    
    return key_filename, answers_filename, scores_filename



def get_num_of_students():
    num_of_students=int(input("Enter the number of students: "))
    return num_of_students


def get_num_of_questions():
    num_of_questions=int(input("Enter the number of questions: "))
    return num_of_questions


#Writes the key list to the key.txt file
def write_key_file(filename,key):
    with open(filename+".txt","w") as key_file:
        for i in range(len(key)):
            if i==(len(key)-1):
                key_file.write(key[i])
            else:
                key_file.write(key[i]+",")


def write_answers_file(filename,answers):
    with open(filename+".txt","w") as answers_file:
        answers_list=answers
        
        for student in answers_list:
            LengthOfEach_AnswerList=len(student)
            position_in_list=0
            for answer in student:

                #Some functions use an "index accumulator" variable to find the index on every iteration since the control variable holds the value for the item in a certain index and not the index itself.
                if position_in_list==(LengthOfEach_AnswerList-1):
                    answers_file.write(answer+"\n")
                else:
                    answers_file.write(answer+",")
                position_in_list+=1
                
                
def write_scores_file(filename,scores):
    with open(filename+".txt","w") as scores_file:
        for student in scores:
            scores_file.write(str(student[0])+","+student[1]+"\n")

#The build functions create the lists in RAM from their respective files
def build_key_list(filename):
    with open(filename+".txt","r") as key_file:
        key=key_file.readline().split(",")
        
    return key
        

def build_answers_list(filename):
    with open(filename+".txt","r") as answers_file:
        answers=[]
        answers_file_list=answers_file.readlines()
        for item in answers_file_list:
            answers.append(item.rstrip().split(","))

    return answers

def build_scores_list(filename):
    with open(filename+".txt","r") as scores_file:
        scores=[]
        scores_file_list=scores_file.readlines()
        for item in scores_file_list:
            scores.append(item.rstrip().split(","))

    return scores

def set_key(num_of_questions):
    key=[]
    for question in range(num_of_questions):
        key.append(input("Enter the correct answer (A-E) for questions "+str(question+1)+": "))
    return key    


def modify_key(key,num_of_questions):
    print("\n")
    for i in range(num_of_questions):
        key_answer_index=int(input("\nEnter the index number (0 - "+str((len(key)-1))+") of the question that you want to change the correct answer for: "))
        key[key_answer_index]=input("Enter the student's new answer for "+str(key_answer_index+1)+" question: ")
        
    return key
    

def add_student_answers(answers,num_of_students,key_length):
    number_of_students_before_add=len(answers)
    for i in range(num_of_students):
        temp_answers=[]
        for j in range(key_length):
            
            temp_answers.append(input("Enter the student "+str(i+1+number_of_students_before_add)+"'s answer to question "+str(j+1)+" (A-E) :"))
        answers.append(temp_answers)
        print("\n")

    return answers
                

                

def modify_student_answers(answers, num_of_students, key_length):
    for i in range(num_of_students):
        new_index=int(input("\nEnter the index number (0 -"+str(len(answers)-1)+") of the student that you want to change the answers for: "))
        num_of_questions_to_mod=int(input("\nEnter the number of questions: "))
        current_students_answers_to_mod=answers[new_index]
        for j in range(num_of_questions_to_mod):
            answer_index=int(input("Enter the index number (0 -"+str((key_length-1))+") of the question that you want to change the answer for: "))
            current_students_answers_to_mod[answer_index]=input("Enter the student's new answer for the question: ")
        print("\n")

    return answers



#Deletes a student answers list from the main answers list
def delete_student_answers(answers, num_of_students):
    students_answers_to_remove_by_id=[]
    identifiers=[]

    idNum=0
    #ID numbers also start at 0 so the original index values can be stored while the lists and their indices are changing
    for student in answers:
        identifiers.append(idNum)
        idNum+=1

        
    for i in range(num_of_students):
        #students_answers_to_remove_by_id.append(identifier[int(input("Enter the student you want to delete the answers for : "))])
        students_answers_to_remove_by_id.append(int(input("Enter the student you want to delete the answers for : ")))


    for answers_and_IDs_to_remove in students_answers_to_remove_by_id:
        index_to_remove=identifiers.index(answers_and_IDs_to_remove)

        del identifiers[index_to_remove]
        del answers[index_to_remove]

    return answers
        


    
#Calculates scores based on the key and answers list and after everytime a change is made.
def calculate_scores(key,answers):
    scores=[]
    points_per_question=100/len(key)
    answers_list=answers
    for student in answers_list:
        point_accumulator=0
        index_accumulator=0
        for answer in student:
            
            if answer.lower()==key[index_accumulator].lower():
                point_accumulator+=points_per_question
            index_accumulator+=1

        #If else chain for deciding grades.
        if point_accumulator>=90:
            scores.append([point_accumulator,"A"])
            
        elif point_accumulator<90 and point_accumulator>=80:
            scores.append([point_accumulator,"B"])

        elif point_accumulator<80 and point_accumulator>=70:
            scores.append([point_accumulator,"C"])

        elif point_accumulator<70 and point_accumulator>=60:
            scores.append([point_accumulator,"D"])

        elif point_accumulator<60:
            scores.append([point_accumulator,"F"])
    return scores

#Print functions below
def print_key(key):
    i=0
    print("\n")
    for mp in key:
        i+=1
        print("The correct answer for question",i,"is: "+mp)

def print_answers(answers):
    i=0
    print("\n")
    for student in answers:
        i+=1
        j=0
        for answer in student:
            j+=1
            print("Student "+str(i)+"'s answer to question "+str(j)+" is: "+answer)
        print("\n")
            
    
def print_scores(scores):
    i=0 
    print("\n")
    for student in scores:
        i+=1
        print("Student "+str(i)+"'s test score: "+student[0])
        print("Student "+str(i)+"'s letter grade: "+student[1]+"\n")
        

def main():
    #This function runs once and before the main program is initalized so the correct files are used
    key_file,answers_file,scores_file=get_filename()
    while True:

        
        """The group of functions below initialize on every iteration and "refresh" the lists and text files.
           This means updates will take place everytime a task 1-9 is completed and on start up."""
        key=build_key_list(key_file)
        key_length=len(key)
        answers=build_answers_list(answers_file)
        write_scores_file(scores_file,calculate_scores(key,answers))
        scores=build_scores_list(scores_file)

        
        #Displays menu and gets the user's input in every iteration
        display_menu()
        menu_choice=get_menu_choice()
        
        if menu_choice=="1":
            write_key_file(key_file, set_key(get_num_of_questions()))
            
                
        elif menu_choice=="2":
            write_key_file(key_file, modify_key(key,get_num_of_questions()))

        elif menu_choice=="3":
            write_answers_file(answers_file ,add_student_answers(answers,get_num_of_students(),len(key)))
       
        elif menu_choice=="4":
            write_answers_file(answers_file,delete_student_answers(answers, get_num_of_students()))
        
        elif menu_choice=="5":

            write_answers_file(answers_file ,modify_student_answers(answers,get_num_of_students(),len(key)))
        
        elif menu_choice=="6":
            print_key(key)
            
        elif menu_choice=="7":
            print_answers(answers)

        elif menu_choice=="8":
            print_scores(scores)

        #If the user types "9", the program stops running
        elif menu_choice=="9":
            print("Quitting the program...")
            break
        else:
            #if the user inputs anything but numbers 1-9 then the error message below will print
            print("\nError: Invalid input  (must be 1-9)")
main()
