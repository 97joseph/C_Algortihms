#Global boolean variable used in validation of inputs. Inside While loops this will not be set to True to break the loop.
#That would require the set it back to False outside the loop. The break keyword is used instead.
ValidationCheck=False
try:
    num_of_runs=int(input("Enter the number of inputs: "))
except ValueError:
    while ValidationCheck==False:
        print("\nPlease enter a valid input, i.e any real number")
        num_of_runs=input("Enter the number of inputs: ")
        if num_of_runs.isdigit():
            num_of_runs=int(num_of_runs)
            print("\n")
            break
        
for runs in range(num_of_runs):
    pattern_choice=None
    pattern_validation=False
    pattern_validation=None
    while ValidationCheck==False:
        pattern_choice=input("Enter the pattern you want to draw(X OR <): ")
        pattern_choice=pattern_choice.lower()
        if pattern_choice=="x" or pattern_choice== "<":
            pattern_validation=True
        else:
            print("Please input either the X or < pattern\n")
            continue
        """pattern_choice can be something else other than None, could still be incorrect, and would pass this elif statement and keep looping until
           the user inputs a valid pattern.
           If pattern_validation does not evaluate to True, then the loop would keep looping, this means until the user types in a
           valid input the code below will not be executed."""        
        if pattern_validation==True:
            try:
                row_choice=int(input("Enter the number of rows (must be an odd number): "))
                if (row_choice%2)!=0:
                    break
                else:
                    #Causes a value error and executes the bottom "except" condition.
                    #Used this so I didn't have to write 2 while loops in both try and except statements.
                    int("k")
            except ValueError:
                while ValidationCheck==False:
                    print("Please enter a valid input, i.e any real odd number\n")
                    row_choice=input("Enter the number of rows (must be an odd number): ")
                    if row_choice.isdigit():
                        row_choice=int(row_choice)
                        if (row_choice%2)!=0:
                            break
        print("\n")
        break
    num_of_rows=row_choice
    y_range=int((num_of_rows-1)/2)
    x_domain=num_of_rows
    x_midpoint=int((x_domain-1)/2)
    """
    The "rows" control variable is used to iterate through the
    range(y-axis values) of either top or bottom portion of the X
    and the "columns" control variable is used to iterate through
    the x-axis.

    To get the top portion as the loop iterates through the columns
    in each row, the left part is found by the use of the formula y=x
    This means that every time the value for the row and column are the
    same (e.g (1,1) ) the "#" character is printed out. The right part
    of the top portion is found by subtracting 2 from the domain. 2 is
    the number of characters on each row and taking it away from the
    domain shows the number of spaces on each row. Since the
    position of the second "#" character moves back each row, subtracting
    the row from the number of spaces shows the x-position of the second
    "#" character. The loop breaks after the second character on each
    line because it would add unnecessary spaces (and might add characters
    on the next loop iteration to the same line).

    The middle character is printed just by adding enough spaces to
    get to the midpoint of the domain.


    To get the bottom portion the rows control variable still iterates
    through the y-axis range for the number of rows and the columns control variable
    for the (x-axis) domain. To get the first "#" character on each line 1 is subtracted
    from the midpoint. This is because row 0 of the bottom portion, its first row, prints
    out the "#" one column/x-value behind the midpoint. And for every row, it moves back another
    column so the rows control variable is subtracted from the position behind the midpoint (i.e
    row 0's first character position). The second "#" character on each line is printed after the
    midpoint, the row it's on determines how much further away from the midpoint it will print out
    the "#".
    """
    if pattern_choice=="x":
        #Top portion
        for rows in range(y_range):
            for columns in range(x_domain):
                
              if rows==columns:
                print("#",end="")
              elif columns==((x_domain-2)-rows):
                print("#")
                break
              print(" ",end="")
        #Middle character
        for middle_character in range(x_midpoint):
            print(" ",end="")
        print("#")
        #Bottom portion
        for rows in range(y_range):
            for columns in range(x_domain):
              if columns==((x_midpoint-1)-rows):
                print("#",end="")
              elif columns==(x_midpoint+rows):
                print("#")
                break
              print(" ",end="")
    else:

        #Less than sign    
        #Iterates the columns backwards starting from the furthest point.
        for rows in range(y_range,0,-1):
            for columns in range(rows):
                print(" ",end="")
            print("*")
        #Prints middle character
        print("*")
        #Does the opposite of top portion of the less than sign
        for rows in range(1,y_range+1):
            for columns in range(rows):     
                print(" ",end="")
            print("*")
