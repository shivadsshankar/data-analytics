infilename = raw_input("Enter input file name every line should contain atleast two columns: ")
outfilename = raw_input("Enter output file name: ")
with open(infilename,'r') as infile:
	with open(outfilename,'w') as outfile:
		for line in infile:
			outfile.write(line.split()[1] + "\n")
print "see " + outfilename + " for output"
infile.close()
outfile.close()