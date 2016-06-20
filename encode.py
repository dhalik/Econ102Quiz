import struct;                  #    Needed to convert string to byte
import sys;
import os.path;

if (len(sys.argv) != 2):
    print("Run this utility as python encode.py <questionFile.xml>")
    sys.exit(0)

filename = sys.argv[1]

if (not os.path.isfile(filename)):
    print("File passed does not exist or is unusable")
    sys.exit(0)

f = open(sys.argv[1],"rb")       #    Open the file in read binary mode
s = "#ifndef __ORG__H__ \n #define __ORG__H__ \n char question_data[] = {"

b = f.read(1)                   #    Read one byte from the stream
db = struct.unpack("b",b)[0]     #    Transform it to byte
h = hex(db)                      #    Generate hexadecimal string
s = s + h;                      #    Add it to the final code
b = f.read(1)                   #    Read one byte from the stream

while b != "":
    s = s + ","                 #    Add a coma to separate the array
    db = struct.unpack("b",b)[0] #    Transform it to byte
    h = hex(db)                  #    Generate hexadecimal string
    s = s + h;                  #    Add it to the final code
    b = f.read(1)               #    Read one byte from the stream

s = s + ",0x00"                     #    Close the bracktes
s = s + "}; \n #endif"                     #    Close the bracktes
f.close()                       #    Close the file

# Write the resultan code to a file that can be compiled
fw = open("questionrepo.h","w");
fw.write(s);
fw.close();
