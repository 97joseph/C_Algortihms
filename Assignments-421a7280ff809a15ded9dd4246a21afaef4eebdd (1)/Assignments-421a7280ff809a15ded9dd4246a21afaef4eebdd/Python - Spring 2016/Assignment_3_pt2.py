def fibonacci():
    while True:
        fib_input=input("Enter a number to calculate the fibonacci sequence of: ")
        #Checks if the input was a string that contains a number, then converts it from string to integer.
        if fib_input.isdigit():
            fib_input=int(fib_input)
            #Breaks the loop if the user inputs a valid input.
            break
        else:
            ("Please input a number")
    ######
    #fibonacci base cases
    fib_n_1=1
    fib_n_2=0
    ######
    new_fib=None
    for fib in range(fib_input+1):
        if fib==0 or fib==1:
            new_fib=fib
        elif fib>=2:
            new_fib=fib_n_1+fib_n_2
            fib_n_2=fib_n_1
            fib_n_1=new_fib
            
            
    print('fib({0}) = {1}'.format(str(fib_input),str(new_fib)))



        
def salary():
    days_of_work=int(input("Enter the number of days: "))
    STARTING_SALARY=0.01
    daily_salary=STARTING_SALARY
    total_salary=STARTING_SALARY

    #Hard-coded since this is the same for every case
    print("\nDay\tSalary"+"\n"+\
          "1\t$0.01")
    for days in range(2,days_of_work+1):

        #doubles or triples depending on the day being an odd or even number
        if days%2==0:
            daily_salary=daily_salary*2

        else:
            daily_salary=daily_salary*3

        total_salary=total_salary+daily_salary


        print(str(days)+"\t$"+'{0:.2f}'.format(daily_salary))
    print("\nTotal salary:\t$"+'{0:.2f}\n'.format(total_salary))
        








def main():
    choosing=True
    #Used a while loop so the program constantly displays the menu option after the execution of a function, until the user quits the program.
    while choosing:
        print("        ----- MENU -----"+"\n"+\
              "1. Calculate the fibonacci sequence of a number","\n"+\
              "2. Calculate a person's salary","\n"+\
              "3. Quit")
        choice=input("\nEnter your choice (1-3): ")
        if choice==("1") or choice==("2") or choice==("3"):
            choice=int(choice)
            if choice==1:
                fibonacci()
            elif choice==2:
                salary()
            elif choice==3:
                print("Quitting the program...")
                choosing=False
        else:
            print("\nError: invalid input (must be 1 - 3)")

#Executes the main function, which holds the call to the other functions
main()
