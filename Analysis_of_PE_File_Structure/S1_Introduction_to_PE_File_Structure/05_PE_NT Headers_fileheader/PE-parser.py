import lief
import datetime

myfilepath32=r"C:\Users\USER\Desktop\PE_5\PE_Sample_32.exe"
myfilepath64=r"C:\Users\USER\Desktop\PE_5\PE_Sample_64.exe"

pe = lief.parse(myfilepath64)


print("*"*75)
print("Episode 5: NT Header - File Header")
print("*"*75)

print("Machine: " ,pe.header.machine.name,
      "\nNumber Of Sections: ",pe.header.numberof_sections,
      "\nTimeDateStamp (UTC): ", datetime.datetime.utcfromtimestamp(pe.header.time_date_stamps).strftime('%Y-%m-%d %H:%M:%S'),
      "\nPointer To Symbol Table: ",pe.header.pointerto_symbol_table,
      "\nnumber of symbols: ",pe.header.numberof_symbols,
      "\nsize of optional header: ",pe.header.sizeof_optional_header,
      "\ncharacteristics: ")
if (pe.header.has_characteristic):
    for val in pe.header.characteristics_list:
        print("\t",val.name)
else:
    print("NO Characteristics")
