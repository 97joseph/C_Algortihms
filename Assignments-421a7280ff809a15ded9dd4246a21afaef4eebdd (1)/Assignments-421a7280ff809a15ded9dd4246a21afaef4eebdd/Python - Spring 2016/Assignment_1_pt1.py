name=input("What is your name?\n")
fav_color=input("What is your favorite color?\n")
coll_maj=input("What is your college major?\n")
address=input("What is your address?\n")
fav_movie=input("What is your favorite movie?\n")
Num_units=int(input("How many units have you taken in college?\n"))
bankBalance=float(input("Enter bank balance\n"))


print("----- Personal information -----\n"\
      "'Your name is':","\\"+name+"\\"+"\n"\
      '"Your favorite color is":',"\\n"+fav_color+"\\n"+"\n" \
      '""Your college major is"":',"\\n\\n"+coll_maj+"\\n\\n","\n"\
      "\\\Your address is\\\:","''"+address+"''","\n"\
      "'''your favorite movie is''':",'"""'+fav_movie+'"""',"\n"\
      "\\\\\\\The number of college units that you have taken is\\\\\\\\:","\\n\\n\\n\\n"+str(Num_units)+"\\n\\n\\n\\n","\n"\
      """""''Your bank account balance is''"": \\t\\t\\t\\t{:,.2f}\\t\\t\\t\\t""".format(bankBalance))
      
