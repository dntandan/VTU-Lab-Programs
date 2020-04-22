rrn = [-1]
cnt = 0

class student:
    def __init__(self, usn, name, sem):
        self.usn = usn
        self.name = name
        self.sem = sem

    def display_data(self):
        print(f"\nUSN -> {self.usn} \nName -> {self.name} \nSem -> {self.sem} \n")

    def pack(self, file):
        global cnt
        pos = file.tell()
        buf = self.usn + "|" + self.name + "|" + self.sem + "|"
        buf += "\n"
        file.write(buf)
        cnt += 1
        rrn.append(pos)

def unpack(pos):
    with open("record.txt", "r") as fp:
        fp.seek(pos)
        line = fp.readline()
        fields = line.strip("\n").split("|")[:-1]
        s1 = student(fields[0], fields[1], fields[2])
        s1.display_data()

def find_rrn():
    global cnt, pos, rrn
    pos = 0
    try: 
        with open("record.txt", "r+") as fp:
            line = fp.readline()
            while line:
                rrn.append(pos)
                pos = fp.tell()  # for returning the location of the next line
                cnt += 1
                line = fp.readline()
    except:
        pass

find_rrn()
while True:
    choice = input(
        "\n1.Insert a record\n2.Search for a record using RRN\n3.Exit\nEnter your choice ==>\t"
    )
    if choice == "1":
        usn = input("Enter USN \t")
        name = input("Enter name \t")
        sem = input("Enter sem \t")
        new_student = student(usn, name, sem)
        with open("record.txt", "a+") as fp:
            new_student.pack(fp)
    elif choice == "3":
        break
    elif choice == "2":
        print(cnt)
        rrn_search = int(input("Enter the RRN to be found \t"))
        if rrn_search > cnt or rrn_search < 0:
            print("Invalid RRN Entered!")
            continue
        print("RRN Record Found")
        pos = rrn[rrn_search]
        with open("record.txt", "r") as fp:
            unpack(pos)
    else:
        print("Invalid Input")
