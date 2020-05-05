print('\nOpening list-1 & list-2 of names')
with open("name-list-1.txt") as fp1:
    list1 = fp1.read().split("\n")
with open("name-list-2.txt") as fp2:
    list2 = fp2.read().split("\n")
count1 = len(list1)
count2 = len(list2)
i = 0
j = 0
list3=[]
list1.sort()
list2.sort()
print('\nComparing names in list-1 & list-2')
while i <count1 and j <count2:
    if list1[i] < list2[j]:
        i += 1
    elif list1[i] > list2[j]:
        j += 1
    else:
        list3.append(list1[i])
        i += 1
        j += 1
print('\nPrinting & saving common names from list-1 & list-2 in output-names\n')
with open("output-names.txt",'w+') as fp3:
    for name in list3:
        fp3.write(name+'\n')
        print(name)
