global_index = []
count = -1

class student:
    def __init__(self,usn,name,sem):
        self.usn=usn
        self.name=name
        self.sem=sem
    def pack(self,file):
        global count,global_index
        pos=file.tell()
        buf=self.usn+"|"+self.name+"|"+self.sem+"|"
        buf+="\n"
        file.write(buf)
        count+=1
        global_index.append(index(self.usn,pos))
        global_index.sort(key = lambda x:x.usn)

class index:
    def __init__(self,usn,addr):
        self.usn=usn
        self.addr=addr

def create_index():
    global count, pos, global_index
    pos = 0
    try:
        with open("student-record-index.txt","r") as fp:
            line = fp.readline()
            while line:
                if line.startswith('*') or len(line) == 0:#escape the deleted record and read next
                    line = fp.readline()
                    pos = fp.tell()
                else:
                    fields=line.strip('\n').split("|")[:-1]
                    global_index.append(index(fields[0], pos))
                    pos = fp.tell()
                    count += 1
                line = fp.readline() #for removing extra blank line at the EOF while we delete a record
        global_index.sort(key = lambda x:x.usn)
    except:
        pass

def find_index(usn_srch):
    index = -1
    for i in range(count+1):
        if global_index[i].usn == usn_srch:
            index = i
    return index

def search():
    global global_index
    usn_srch = input("\nEnter the USN of the student to be found ==> \t")
    index = find_index(usn_srch)
    if index == -1:
        print('\nRecord not found')
    else:
        print('\nRecord found\nUSN|Name|Sem')
        with open("student-record-index.txt","r") as fp:
            fp.seek(global_index[index].addr)
            line = fp.readline()
            print(line.strip('\n'))

def delete():
    global global_index,count
    usn_srch = input("\nEnter the USN of the student to be deleted ==> \t")
    index = find_index(usn_srch)
    if index == -1:
        print('Record not found')
    else:
        print('Record deleted')
        print(global_index[index].addr)
        with open("student-record-index.txt","r+") as fp:
            fp.seek(global_index[index].addr)
            fp.write('*')#* in student-record-index.tx files means record is deleted for that entry
        global_index.pop(index)#removing element from index array
        count -= 1#decrease the elements count by 1

create_index()#has to be called when prog. starts
while True:
    choice = int(input('\n1.Add a record\n2.Search for a record\n3.Delete a record\n4.Exit\nEnter choice ==> \t'))
    if choice == 1:
        usn=input("\nEnter USN ==> \t")
        name=input("Enter name ==> \t")
        sem=input("Enter sem ==> \t")
        s1=student(usn,name,sem)
        with open("student-record-index.txt","a+") as fp:
            s1.pack(fp)
    elif choice == 2:
        search()
    elif choice == 3:
        delete()
    else:
        break
