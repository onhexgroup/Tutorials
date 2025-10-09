import lief


myfilepath32=r"C:\Users\USER\Desktop\PE_6\PE_Sample_32.exe"
myfilepath64=r"C:\Users\USER\Desktop\PE_6\PE_Sample_64.exe"

pe = lief.parse(myfilepath64)


print("*"*75)
print("Episode 6-10: NT Header - optional Header")
print("*"*75)
print(pe.optional_header)
print("DATA DIRECTORY:")
print("{: >15} {: >15} {: >15}".format("Address","Size","Type"))
for val in pe.data_directories:
    print("{: >15} {: >15} {: >15}".format(hex(val.rva),hex(val.size),val.type.name))
