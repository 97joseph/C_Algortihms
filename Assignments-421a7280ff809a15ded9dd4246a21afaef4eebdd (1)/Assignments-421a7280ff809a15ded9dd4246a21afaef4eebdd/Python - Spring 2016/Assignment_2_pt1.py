#Get 4 strings as input from the user.
input_1=input("Enter first string: ")
input_2=input("Enter second string: ")
input_3=input("Enter third string: ")
input_4=input("Enter fourth string: ")
print("\n")

#Variables that hold the final strings
largest_string=None
smallest_string=None
second_largest_string=None
second_smallest_string=None

#The 4 string inputs are split/assigned into 2 groups that hold the largest and smallest values for each.
Group_1_largest=None
Group_1_smallest=None
Group_2_largest=None
Group_2_smallest=None

################################################
#If/else statements assigning strings into groups finding the largest and smallest for each group. Group1 contains inputs 1 and 2, Group2 contains inputs 3 and 4.
if input_1 >input_2:
    Group_1_largest=input_1
    Group_1_smallest=input_2
else:
    Group_1_largest=input_2
    Group_1_smallest=input_1

if input_3 >input_4:
    Group_2_largest=input_3
    Group_2_smallest=input_4
else:
    Group_2_largest=input_4
    Group_2_smallest=input_3

###################################################

"""
Assigning strings to their final variables for output: The largest string is found using the first if/else statement
comparing both of the largest strings in group 1 and 2. Once the largest string has been found, the second largest needs to be determined.
Since there are 3 strings remaining including the largest string of the other group, the largest string of the other group is compared
with the smallest string of the group whose largest has already been assigned (e.g Group_1_largest=largest_string, therefore
Group_2_largest is compared with Group_1_smallest). This is because "Group_1_smallest" can be larger than "Group_2_largest".
e.g (Group_1_largest="4"
     Group_1_smallest="3"
     Group_2_largest="2"
     Group_2_smallest="1")

In the above case, Group-1's smallest number was bigger than Group-2's largest (a problem faced in testing).
After the the greater of the 2 strings is determined, they are assigned to their corresponding variables, only the smallest string
is remaining to be assigned.
The nested/second if/else statement, after finding the largest string, serves to assign all 3 remaining strings
in one go (per case). Hence why only one level of indentation was needed.

"""
if Group_1_largest >Group_2_largest:
    largest_string=Group_1_largest
    if Group_2_largest>Group_1_smallest:
        second_largest_string=Group_2_largest
        second_smallest_string=Group_1_smallest
        smallest_string=Group_2_smallest
    else:
        second_largest_string=Group_1_smallest
        second_smallest_string=Group_2_largest
        smallest_string=Group_2_smallest

    
else:
    largest_string=Group_2_largest
    if Group_1_largest>Group_2_smallest:
        second_largest_string=Group_1_largest
        second_smallest_string=Group_2_smallest
        smallest_string=Group_1_smallest
    else:
        second_largest_string=Group_2_smallest
        second_smallest_string=Group_1_largest
        smallest_string=Group_1_smallest

#Prints out the strings in order of largest to smallest.
print("The largest string is:",largest_string,"\n"+\
      "The second largest string is:",second_largest_string,"\n"+\
      "The second smallest string is:",second_smallest_string,"\n"+\
      "The smallest string is:",smallest_string)
