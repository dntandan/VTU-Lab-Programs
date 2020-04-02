infile = input("\nEnter the input file name ==>\t ")
finp = open(infile, "r")
outfile = input("Enter the output file name ==>\t ")
foutp = open(outfile, "w+")
if not finp or not foutp:
    print("FATAL ERROR -- File Do Not Exist")
    exit()
for line in finp:
    foutp.write(line.strip()[::-1] + "\n")
print("File Read & Write Completed")
finp.close()
foutp.close()
