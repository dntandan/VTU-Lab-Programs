lst = []

for i in range(4):
    with open('name-list-'+str(i+1)+'.txt') as fp:
        list1 = fp.read().split('\n')
    list1.sort()
    with open('sorted-name-list-'+str(i+1)+'.txt','w') as fp:
        for x in list1:
            fp.write(x+'\n')

files = ["name-list-1.txt", "name-list-2.txt","name-list-3.txt","name-list-4.txt"]

fhandler = []
for f in files:
    fhandler.append(open(f,'r'))

lines = []
for fh in fhandler:
    lines.append(fh.readline())

while len(fhandler) > 0:
    smallest = min(lines)
    smallestposition = lines.index(smallest)
    lst.append(smallest)
    lines[smallestposition] = fhandler[smallestposition].readline()
    if lines[smallestposition] == "":
        fhandler.pop(smallestposition)
        lines.pop(smallestposition)
print('Merged List Is As Follow:')
for names in sorted(set(lst)):
    print(names.strip('\n'))
