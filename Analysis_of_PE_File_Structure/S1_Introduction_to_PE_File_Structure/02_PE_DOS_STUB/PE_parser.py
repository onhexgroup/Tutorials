import lief


myfilepath32=r"0.exe"
myfilepath64=r"PE_Sample_64.exe"

pe = lief.parse(myfilepath32)


print("*"*75)
print("Episode 2:DOS stub")
print("*"*75)
dos_stub_text = ''.join(chr(c) if 32 <= c <= 126 else '.' for c in pe.dos_stub)
print(dos_stub_text)