def display_menu():
    print("----- MENU -----\n\n",\
          "1. Draw a Z pattern\n",\
          "2. Draw a M pattern\n",\
          "3. Quit")

def get_menu_choice():
    menu_choice=input("Enter your choice (1-3):")
    return menu_choice

def get_input():
    Validation_Check=True
    while Validation_Check:
        ROWS=input("Enter the number of rows (must be at least 3)")
        #Checking if the string is a number before changing it to an integer will avoid causing a value error
        if ROWS.isdigit():
            ROWS=int(ROWS)
            if ROWS>=3:
                Validation_Check=False
            else:
                print("Error: Invalid input")
        else:
            print("Error: Invalid input")
    return ROWS

"""
Using grid/graph notation the domain of a function is its length on the
x-axis, i.e the number of columns it should go across.
The number of columns that that it would need to go across is given by
the formula 2*rows-1, but the formula 2*rows-3 has been used since the
first and last asterisks are printed within the first for loop before
and after the second for loop iterates. This means 2 characters have been accounted
for and the inner for loop only needs to iterate through the space between them.

"""
def draw_m_pattern(no_of_rows):
    x_domain=(2*(no_of_rows)-3)
    for rows in range(no_of_rows):
        print("*",end="")
        for columns in range(x_domain):
            if columns==rows-1 and rows>0:
                print("*",end="")
            elif rows>0 and rows<no_of_rows-1 and (columns==(x_domain)-rows):
                print("*",end="")
            else:
                print(" ",end="")
        print("*")
        
    

def draw_z_pattern(no_of_rows):
    for rows in range(no_of_rows):
        for columns in range(no_of_rows-1):
            
            #Prints the top and bottom rows which make up the horizontal lines
            if rows==0 or rows==(no_of_rows-1):
                print("#",end="")
                if columns==(no_of_rows-2):
                    print("#")
                    break
            #Prints the diagonal line between the 2 horizontal lines of the Z
            if rows>0 and  not rows==no_of_rows-1:
                if columns==((no_of_rows-1)-rows):
                    print("#")
                    break
                print(" ",end="")

def main():
    while True:
        display_menu()
        #Choice variable holds the returned value of the get_menu_choice function
        choice=get_menu_choice()
        if (choice=="1") or ( choice=="2") or (choice=="3"):
            if choice=="1":
                draw_z_pattern(get_input())
            elif choice=="2":
                draw_m_pattern(get_input())
            elif choice=="3":
                print("Quitting the program...")
                break
        else:
            #Prints error message if choice is anything other than "1","2" or "3"
            print("Error: Invalid input (must be 1-3)")
            continue
            
main()
