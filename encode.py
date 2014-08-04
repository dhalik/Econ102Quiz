import struct;                  #    Needed to convert string to byte

f = open("QuestionBank/econ.xml","rb")       #    Open the file in read binary mode
s = "char question_data[] = {"

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
s = s + "};"                     #    Close the bracktes
f.close()                       #    Close the file

# Write the resultan code to a file that can be compiled
fw = open("econ.cpp","w");
fw.write(s);
fw.close();
