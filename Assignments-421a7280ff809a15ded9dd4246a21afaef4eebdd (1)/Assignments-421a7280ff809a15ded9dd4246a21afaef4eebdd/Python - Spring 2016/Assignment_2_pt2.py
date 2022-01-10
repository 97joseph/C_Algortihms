import math
HTDGS_IN_PCKG=12
HTDG_BUNS_IN_PCKG=8
BRGRS_IN_PCKG=6
BRGR_BUNS_IN_PCKG=10


num_of_guest=int(input("Enter the total number of guests: "))
num_of_guests_having_htdgs=int(input("Enter the number of guests having hotdogs: "))
num_of_htdgs_per_guest=int(input("Enter the number of hotdogs each guest will have: "))
num_of_guests_having_burgers=int(input("Enter the number of guests having burgers: "))
num_of__brgrs_per_guest=int(input("Enter the number of burgers each guest will have: "))


#a) Number of hotdogs for all guests
total_number_of_htdgs_for_guests=num_of_guests_having_htdgs * num_of_htdgs_per_guest

# b) Number of burgers for all guests
total_number_of_brgrs_for_guests= num_of_guests_having_burgers * num_of__brgrs_per_guest

""" c) Minimum number of hotdog packages needed. Math module rounds up floating point numbers.
Since you can't have part of a hotdog package."""
min_num_of_htdg_pckgs=math.ceil(total_number_of_htdgs_for_guests/HTDGS_IN_PCKG)

# d) Minimum number of hotdog bun packages needed.
min_num_of_htdg_bun_pckgs=math.ceil(total_number_of_htdgs_for_guests/HTDG_BUNS_IN_PCKG)

""" e) Number of hotdogs left over = Remainder of minimum number of packages
of hotdogs times the number of hotdogs in a package divided by the number of hotdogs in a package"""
num_of_lftovr_htdgs=(min_num_of_htdg_pckgs*HTDGS_IN_PCKG) - total_number_of_htdgs_for_guests


#f) Same method for finding the leftover as shown above.
num_of_lftovr_htdgs_buns=(min_num_of_htdg_bun_pckgs*HTDG_BUNS_IN_PCKG) - total_number_of_htdgs_for_guests#total_number_of_htdgs_for_guests % HTDG_BUNS_IN_PCKG


#g)
min_num_of_brgr_pckgs=math.ceil(total_number_of_brgrs_for_guests/BRGRS_IN_PCKG)

#h)
min_num_of_brgr_bun_pckgs=math.ceil(total_number_of_brgrs_for_guests/BRGR_BUNS_IN_PCKG)

#i)
num_of_lftovr_brgrs=(min_num_of_brgr_pckgs*BRGRS_IN_PCKG) - total_number_of_brgrs_for_guests

#j)
num_of_lftovr_brgr_buns=(min_num_of_brgr_bun_pckgs*BRGR_BUNS_IN_PCKG) - total_number_of_brgrs_for_guests

#k The "percent_eating..." variables find the percentage eating either of the 2 foods and formats it to 2 decimal places.
percent_eating_htdgs="{0:.2f}".format((num_of_guests_having_htdgs/num_of_guest)*100)+"%"

#l)
percent_eating_brgrs="{0:.2f}".format((num_of_guests_having_burgers/num_of_guest)*100)+"%"

#m) Determined and printed out below the output-print statement



print("\nTotal number of hot dogs:", total_number_of_htdgs_for_guests,"\n"+\
      "Total number of burgers:", total_number_of_brgrs_for_guests,"\n"+\
      "Minimum number of hot dog packages needed:",min_num_of_htdg_pckgs,"\n"+\
      "Minimum number of hot dog bun packages needed:",min_num_of_htdg_bun_pckgs,"\n"+\
      "Number of hot dogs left over:",num_of_lftovr_htdgs,"\n"+\
      "Number of hot dog buns left over:",num_of_lftovr_htdgs_buns,"\n"+\
      "Minimum number of burger packages needed:",min_num_of_brgr_pckgs,"\n"+\
      "Minimum number of burger bun packages needed:",min_num_of_brgr_bun_pckgs,"\n"+\
      "Number of burgers left over:",num_of_lftovr_brgrs,"\n"+\
      "Number of burger buns left over:",num_of_lftovr_brgr_buns,"\n"+\
      "The percentage of guests that had hot dogs:",percent_eating_htdgs,"\n"+\
      "The percentage of guests that had burgers:",percent_eating_brgrs)

#m) Displays if more people ate hot dogs or burgers. Based on sample runs in programming assignment instructions.
if num_of_guests_having_htdgs>num_of_guests_having_burgers:
    print("More guests ate hot dogs (%d) than burgers (%d)" % (num_of_guests_having_htdgs,num_of_guests_having_burgers))
elif num_of_guests_having_htdgs==num_of_guests_having_burgers:
    print("The guests ate the same number of hot dogs (%d) and burgers (%d)" %(num_of_guests_having_htdgs,num_of_guests_having_burgers))
else:
    print("More guests ate burgers (%d) than hotdogs (%d)" %(num_of_guests_having_burgers,num_of_guests_having_htdgs))
      
      
      
      
