import lief
import datetime

myfilepath32=r"C:\Users\USER\Desktop\PE-11\PE_Sample_32.exe"
myfilepath64=r"C:\Users\USER\Desktop\PE-11\PE_Sample_64.exe"

pe = lief.parse(myfilepath64)

print("*"*75)
print("Episode 11: Section Headers")
print("*"*75)
for entry in pe.sections:
    print(entry)