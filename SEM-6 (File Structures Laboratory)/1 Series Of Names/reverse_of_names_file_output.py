count = int(input("\nEnter the no. of names ==>\t"))
outfile = input("Enter the output file name ==>\t")
foutp = open(outfile, "w+")
for i in range(count):
    name = input("\nEnter the name ==>\t")
    foutp.write(name[::-1] + "\n")
foutp.close()
