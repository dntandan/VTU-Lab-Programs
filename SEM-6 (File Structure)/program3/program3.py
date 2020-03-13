details = []
class student:
    def __init__(self, usn, name, sem):
        self.usn = usn
        self.name = name
        self.sem = sem

    def display_data(self):
        print(f"USN -> {self.usn} \nName -> {self.name} \nSem -> {self.sem} \n")

    def pack(self, file):
        buffer = self.usn + "|" + self.name + "|" + self.sem + "|"
        buffer += "\n"
        file.write(buffer)

    def modify_name(self):
        newname = input("Enter The New Name ==>\t")
        self.name = newname

    def modify_sem(self):
        newsem = input("Enter The New Sem ==>\t")
        self.sem = newsem

def unpack():
    with open("students2.txt", "r") as fp:
        for line in fp:
            fields = line.strip("\n").split("|")[:-1]
            details.append(student(fields[0], fields[1], fields[2]))

def search():
    found=False
    for x in details:
        if key == x.usn:
            found=True
            print("\n----Record Found----\n")
            x.display_data()
            option = input(
                "Select The Data To Modify\n1.Name\n2.Sem\n3.Do'nt Modify Anything ==>\t"
            )
            if option == "1":
                x.modify_name()
            elif option == "2":
                x.modify_sem()
            elif option == "3":
                break
    if not found:
        print("\n----Record Not Found----\n")


while True:
    choice = input(
        "\n1.Insert Student Details\n2.Search and Modify Student Details\n3.Exit\nEnter Your Choice ==>\t"
    )
    if choice == "1":
        usn = input("Enter USN \t")
        name = input("Enter Name \t")
        sem = input("Enter Sem \t")
        new_student = student(usn, name, sem)
        with open("students2.txt", "a+") as fp:
            new_student.pack(fp)
        print("\n---- Entered Data ----")
        new_student.display_data()
    elif choice == "2":
        details = []
        unpack()
        key = input("Enter The USN To Search & Modify ==>\t")
        search()
        with open("students2.txt", "w+") as fp:
            for x in details:
                x.pack(fp)
    elif choice == "3":
        break
    else:
        print("\n----Invalid Data Entered! Please Try Again----\n")
