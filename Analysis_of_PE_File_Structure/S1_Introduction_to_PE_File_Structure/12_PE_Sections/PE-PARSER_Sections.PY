import lief
import datetime

myfilepath32=r"C:\Users\USER\Desktop\PE-11\PE_Sample_32.exe"
myfilepath64=r"C:\Users\USER\Desktop\PE-11\PE_Sample_64.exe"

pe = lief.parse(myfilepath64)

print("*"*75)
print("Episode 12: Data Directory in Section")
print("*"*75)
for directory in pe.data_directories:
    section = directory.section
    section_name = section.name if section else "N/A"
    print(f"{directory.type.name:<25} | {section_name:<15}")


