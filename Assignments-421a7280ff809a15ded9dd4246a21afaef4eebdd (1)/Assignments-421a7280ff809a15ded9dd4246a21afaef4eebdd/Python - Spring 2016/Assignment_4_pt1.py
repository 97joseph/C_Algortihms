#gets number of inputs
def get_num_of_inputs():
    num_of_inputs=int(input("Enter the number of inputs: "))
    return num_of_inputs
    
def get_input():
    numerator=int(input("\nEnter the numerator: "))
    while True:
        #while loop to make sure the denominator isn't set to 0
        denominator=int(input("Enter the denominator (must not be zero): "))
        if denominator==0:
            print("Error: invalid input")
        else:
            break
    
        
    return numerator,denominator


def calc_quotient(numerator,denominator):
    count=0
    decreasing_numerator=abs(numerator)
    if denominator==1:
        count=numerator
    elif denominator==-1:
        count=-numerator
    else:
        while decreasing_numerator>=abs(denominator):
            decreasing_numerator=decreasing_numerator-abs(denominator)
            count+=1
        #XOR Logic gate. Only one can be negative (negative=true) for the statement to evaluate to true
        if (numerator==-abs(numerator) or denominator==-abs(denominator)) and not(numerator==-abs(numerator) and denominator==-abs(denominator)) and numerator!=0:

            #rounds down by one if the numerator is smaller than the denominator and one of the 2 is negative
            if abs(numerator)<abs(denominator):
                count=-(count+1)
            #rounds down by one if either the numerator or denominator in a fraction where the numerator is bigger
            #decreasing_numerator acts as a remainder, therefore if it stores a number greater than 0 then there was a remainder leftover.
            elif abs(numerator)>abs(denominator) and (decreasing_numerator>0):
                count=-count-1
            else:
                count=-count
    return numerator,denominator,count
        
        
   
def display_output(numerator,denominator,quotient):
     print("The quotient of "+str(numerator)+" and "+str(denominator)+" is: "+str(quotient))

def main():
    for num in range(get_num_of_inputs()):
        numerator,denominator=get_input()
        numerator_display,denominator_display,quotient_display=calc_quotient(numerator,denominator)
        display_output(numerator_display,denominator_display,quotient_display)
        

main()
