import math
a=float(input("Enter a (must be non-negative): "))
b=float(input("Enter b (must be non-negative): "))
c=float(input("Enter c (must be non-negative): "))
d=float(input("Enter d (must be non-negative): "))
e=float(input("Enter e (must be non-negative): "))
f=float(input("Enter f (must be non-negative): "))
g=float(input("Enter g (must be non-negative): "))
h=float(input("Enter h (must be non-negative): "))

result1=(((a**2+b**2)/(c**2+d**2))**.5)*((e**2+f**2)/(g**2+h**2))**.5
result2=(((a**.5+b**.5)/(c**.5+d**.5))**2)*((e**.5+f**.5)/(g**.5+h**.5))**2
print("\n")
print('result1: {0:,.6f}'.format(result1))
print('result2: {0:,.6f}'.format(result2))
