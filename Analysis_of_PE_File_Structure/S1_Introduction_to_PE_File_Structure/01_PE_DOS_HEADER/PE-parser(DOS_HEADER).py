import lief

myfilepath32=r"C:\\Users\\USER\Desktop\\PE_1\\PE_Sample_32.exe"
myfilepath64=r"C:\\Users\\USER\Desktop\\PE_1\\PE_Sample_64.exe"

pe = lief.parse(myfilepath64)

print("*"*75)
print("E1:DOS Header")
print("*"*75)
print(pe.dos_header)


