import lief


myfilepath32=r"C:\Users\USER\Desktop\PE_4\PE_Sample_32.exe"
myfilepath64=r"C:\Users\USER\Desktop\PE_4\PE_Sample_64.exe"

pe = lief.parse(myfilepath64)

print("*"*75)
print("Episode 4: NT Headers - Signiture")
print("*"*75)
print("Signature: ", [ chr(x) for x in pe.header.signature])
