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
        global_index.append(sec_index(self.usn,self.name,pos))
        global_index.sort(key = lambda x:x.name)

class sec_index:
    def __init__(self,usn,name,addr):
        self.usn=usn
        self.name=name
        self.addr=addr

def create_index():
    global count, pos, global_index
    pos = 0
    try:
        with open("student-record-secondary-index.txt","r") as fp:
            line = fp.readline()
            while line:
                if line.startswith('*') or len(line) == 0:#escape the deleted record and read next
                    line = fp.readline()
                    pos = fp.tell()
                else:
                    fields=line.strip('\n').split("|")[:-1]
                    global_index.append(sec_index(fields[0], fields[1], pos))
                    pos = fp.tell()
                    count += 1
                line = fp.readline() #for removing extra blank line at the EOF while we delete a record
        global_index.sort(key = lambda x:x.name)#sorting index by USN
    except:
        pass

def find_sec(name_srch):
    global find_cnt,found,indexnums
    find_cnt = 0
    indexnums = []
    found = []
    for ind, i in enumerate(global_index):
        if i.name == name_srch:
            found.append(i)
            indexnums.append(ind)
            find_cnt += 1

def search():
    global global_index, found, find_cnt
    name_srch = input("\nEnter the name of the student to be searched ==> \t")
    find_sec(name_srch)
    if find_cnt >0:
        if find_cnt == 1:
            print('\nOne record found')
            ch = 0
        else:
            print('\nMultiple records found\nChoice\tDetails')
            for i in range(find_cnt):
                print(i, "\tUSN="+found[i].usn)
            ch = int(input('Enter your choice: ==> \t'))
            if ch > find_cnt:
                print('Invalid range')
                return
        print('\nUSN|Name|Sem')
        with open("student-record-secondary-index.txt","r") as fp:
            fp.seek(found[ch].addr)
            line = fp.readline()
            print(line.strip('\n'))
    else:
        print('\nRecord not found')


def delete():
    global global_index, find_cnt, found, indexnums, count
    name_srch = input("\nEnter the name of the student to be deleted ==> \t")
    find_sec(name_srch)
    if find_cnt > 0:
        if find_cnt == 1:
            print('\nOne record found')
            ch = 0
        else:
            print('\nMultiple records found\nChoice\tDetails')
            for i in range(find_cnt):
                print(i, "\tUSN="+found[i].usn)
            ch = int(input('Enter your choice: ==> \t'))
            if ch > find_cnt:
                print('Invalid range')
                return
        print('Record deleted')
        with open("student-record-secondary-index.txt","r+") as fp:
            fp.seek(found[ch].addr)
            fp.write('*')
        global_index.pop(indexnums[ch])
        count -= 1
    else:
        print('\nRecord not found')


create_index()#has to be called when prog. starts
while True:
    choice = int(input('\n1.Add a record\n2.Search for a record\n3.Delete a record\n4.Exit\nEnter your choice ==> \t'))
    if choice == 1:
        usn=input("\nEnter USN ==> \t")
        name=input("Enter Name ==> \t")
        sem=input("Enter SEM ==> \t")
        s1=student(usn,name,sem)
        with open("student-record-secondary-index.txt","a+") as fp:
            s1.pack(fp)
    elif choice == 2:
        search()
    elif choice == 3:
        delete()
    else:
        break
