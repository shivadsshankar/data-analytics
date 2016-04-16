with open('network.dat', 'r') as infile:
	with open('edgelist.txt', 'w') as outfile:
		for line in infile:
			splitline = line.split('\t') 
			newline = splitline[0] + '\t' + splitline[1] + '\n'
			outfile.write(newline)
print "See edgelist.txt for output"
outfile.close()
infile.close()
