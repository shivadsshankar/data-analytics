with open('community.dat','r') as infile:
	with open('overlapping_nodes_with_labels.txt','w') as outfile:
		for line in infile:
			if len(line.split()) > 2:
				outfile.write(line)
print "See overlapping_nodes_with_labels.txt for output"
infile.close()
outfile.close()