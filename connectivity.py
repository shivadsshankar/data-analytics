# Processing each individual node and its connects into an arraylist
edgelist_infile_name = raw_input("Enter input file name that contains edgelist, its edgelist should be in sorted order, zero should not be the node number and last line should be a string such as the end, ..: ")
with open(edgelist_infile_name, 'r') as edgelist_infile:
#with open('edgelist.txt', 'r') as edgelist_infile:
	node_connects_list = []
	temp_community = []
	temp_num_old = ''
	for line in edgelist_infile:
		if temp_num_old != line.split()[0]:
			temp_num_old = line.split()[0]
			node_connects_list.append(temp_community)
			temp_community = []
			temp_community.append(line.split()[0])
			temp_community.append(line.split()[1])
		else:
			temp_community.append(line.split()[1])
	node_connects_list = node_connects_list[1:]
edgelist_infile.close()

# Printing each individual node and its connections
nodes_with_individual_connections_outfile_name = raw_input("Enter output file name that contains individual nodes with its connections: ")
with open(nodes_with_individual_connections_outfile_name, 'w') as node_list_file:
	temp_community_index = 1
	for node_list in node_connects_list:
		if node_list:
			temp_var = "node "+str(temp_community_index)+" -> "
			node_list_file.write(temp_var)
			temp_community_index = temp_community_index + 1
			for element in node_list:
				node_list_file.write("  "+element)
			node_list_file.write("\n")
node_list_file.close()
print "\nsee ",nodes_with_individual_connections_outfile_name," file for each individual node and its connections \n"

# Storing community labels into an array for each algorithm
number_of_algorithms = int(raw_input("Enter the number of algorithms you want to find consensus between 4 to 9: "))
community_labels_file_name = raw_input("Enter the file name which contains community labels as (total number nodes) * (number of algorithms) format: ")
with open(community_labels_file_name, 'r') as community_labels_infile:
#with open('communities.txt', 'r') as community_labels_infile:	
	algo1 = []
	algo1.append('')
	algo2 = []
	algo2.append('')
	algo3 = []
	algo3.append('')
	algo4 = []
	algo4.append('')
	algo5 = []
	algo5.append('')
	algo6 = []
	algo6.append('')
	algo7 = []
	algo7.append('')
	algo8 = []
	algo8.append('')
	algo9 = []
	algo9.append('')
	
	if number_of_algorithms == 4:
		for line in community_labels_infile:
			algo1.append(line.split()[0])
			algo2.append(line.split()[1])
			algo3.append(line.split()[2])
			algo4.append(line.split()[3])
	elif number_of_algorithms == 5:
		for line in community_labels_infile:
			algo1.append(line.split()[0])
			algo2.append(line.split()[1])
			algo3.append(line.split()[2])
			algo4.append(line.split()[3])
			algo5.append(line.split()[4])
	elif number_of_algorithms == 6:
		for line in community_labels_infile:
			algo1.append(line.split()[0])
			algo2.append(line.split()[1])
			algo3.append(line.split()[2])
			algo4.append(line.split()[3])
			algo5.append(line.split()[4])
			algo6.append(line.split()[5])
	elif number_of_algorithms == 7:
		for line in community_labels_infile:
			algo1.append(line.split()[0])
			algo2.append(line.split()[1])
			algo3.append(line.split()[2])
			algo4.append(line.split()[3])
			algo5.append(line.split()[4])
			algo6.append(line.split()[5])
			algo7.append(line.split()[6])
	elif number_of_algorithms == 8:
		for line in community_labels_infile:
			algo1.append(line.split()[0])
			algo2.append(line.split()[1])
			algo3.append(line.split()[2])
			algo4.append(line.split()[3])
			algo5.append(line.split()[4])
			algo6.append(line.split()[5])
			algo7.append(line.split()[6])
			algo8.append(line.split()[7])
	elif number_of_algorithms == 9:
		for line in community_labels_infile:
			algo1.append(line.split()[0])
			algo2.append(line.split()[1])
			algo3.append(line.split()[2])
			algo4.append(line.split()[3])
			algo5.append(line.split()[4])
			algo6.append(line.split()[5])
			algo7.append(line.split()[6])
			algo8.append(line.split()[7])
			algo9.append(line.split()[8])
community_labels_infile.close()

# Get the degrees of each node from the file which contains degree of each node
degree_file_name = raw_input("Enter file name which contains degree of each node: ")
with open(degree_file_name, 'r') as degree_infile:
#with open('degrees.txt', 'r') as degree_infile:
	degree = []
	degree.append('')
	for line in degree_infile:
		degree.append(line.split()[0])
degree_infile.close()

# Check each node's community labels with its connected node's community labels for all algorithms
overlapping_output_file_name = raw_input("Enter output file name to store overlapping nodes: ")
with open(overlapping_output_file_name, 'w') as overlapping_outfile:
	for sub_array in node_connects_list:
		algo1_count = 0
		algo2_count = 0
		algo3_count = 0
		algo4_count = 0
		algo5_count = 0
		algo6_count = 0
		algo7_count = 0
		algo8_count = 0
		algo9_count = 0
		consensus_count = 0
		if (int(degree[int(sub_array[0])]) % 2 == 0):
			temp_degree = int(degree[int(sub_array[0])])
		else:
			temp_degree = int(degree[int(sub_array[0])]) + 1

		if number_of_algorithms == 4:
			for element in sub_array[1:]:
				if algo1[int(sub_array[0])] != algo1[int(element)]:
					algo1_count = algo1_count + 1
				if algo2[int(sub_array[0])] != algo2[int(element)]:
					algo2_count = algo2_count + 1
				if algo3[int(sub_array[0])] != algo3[int(element)]:
					algo3_count = algo3_count + 1
				if algo4[int(sub_array[0])] != algo4[int(element)]:
					algo4_count = algo4_count + 1
			if algo1_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo2_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo3_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo4_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if consensus_count >= 2:
				overlapping_outfile.write(sub_array[0]+"\n")

		if number_of_algorithms == 5:
			for element in sub_array[1:]:
				if algo1[int(sub_array[0])] != algo1[int(element)]:
					algo1_count = algo1_count + 1
				if algo2[int(sub_array[0])] != algo2[int(element)]:
					algo2_count = algo2_count + 1
				if algo3[int(sub_array[0])] != algo3[int(element)]:
					algo3_count = algo3_count + 1
				if algo4[int(sub_array[0])] != algo4[int(element)]:
					algo4_count = algo4_count + 1
				if algo5[int(sub_array[0])] != algo5[int(element)]:
					algo5_count = algo5_count + 1
			if algo1_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo2_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo3_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo4_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo5_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if consensus_count >= 3:
				overlapping_outfile.write(sub_array[0]+"\n")

		if number_of_algorithms == 6:
			for element in sub_array[1:]:
				if algo1[int(sub_array[0])] != algo1[int(element)]:
					algo1_count = algo1_count + 1
				if algo2[int(sub_array[0])] != algo2[int(element)]:
					algo2_count = algo2_count + 1
				if algo3[int(sub_array[0])] != algo3[int(element)]:
					algo3_count = algo3_count + 1
				if algo4[int(sub_array[0])] != algo4[int(element)]:
					algo4_count = algo4_count + 1
				if algo5[int(sub_array[0])] != algo5[int(element)]:
					algo5_count = algo5_count + 1
				if algo6[int(sub_array[0])] != algo6[int(element)]:
					algo6_count = algo6_count + 1
			if algo1_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo2_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo3_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo4_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo5_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo6_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if consensus_count >= 3:
				overlapping_outfile.write(sub_array[0]+"\n")

		if number_of_algorithms == 7:
			for element in sub_array[1:]:
				if algo1[int(sub_array[0])] != algo1[int(element)]:
					algo1_count = algo1_count + 1
				if algo2[int(sub_array[0])] != algo2[int(element)]:
					algo2_count = algo2_count + 1
				if algo3[int(sub_array[0])] != algo3[int(element)]:
					algo3_count = algo3_count + 1
				if algo4[int(sub_array[0])] != algo4[int(element)]:
					algo4_count = algo4_count + 1
				if algo5[int(sub_array[0])] != algo5[int(element)]:
					algo5_count = algo5_count + 1
				if algo6[int(sub_array[0])] != algo6[int(element)]:
					algo6_count = algo6_count + 1
				if algo7[int(sub_array[0])] != algo7[int(element)]:
					algo7_count = algo7_count + 1
			if algo1_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo2_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo3_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo4_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo5_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo6_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo7_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if consensus_count >= 4:
				overlapping_outfile.write(sub_array[0]+"\n")

		if number_of_algorithms == 8:
			for element in sub_array[1:]:
				if algo1[int(sub_array[0])] != algo1[int(element)]:
					algo1_count = algo1_count + 1
				if algo2[int(sub_array[0])] != algo2[int(element)]:
					algo2_count = algo2_count + 1
				if algo3[int(sub_array[0])] != algo3[int(element)]:
					algo3_count = algo3_count + 1
				if algo4[int(sub_array[0])] != algo4[int(element)]:
					algo4_count = algo4_count + 1
				if algo5[int(sub_array[0])] != algo5[int(element)]:
					algo5_count = algo5_count + 1
				if algo6[int(sub_array[0])] != algo6[int(element)]:
					algo6_count = algo6_count + 1
				if algo7[int(sub_array[0])] != algo7[int(element)]:
					algo7_count = algo7_count + 1
				if algo8[int(sub_array[0])] != algo8[int(element)]:
					algo8_count = algo8_count + 1
			if algo1_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo2_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo3_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo4_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo5_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo6_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo7_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo8_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if consensus_count >= 4:
				overlapping_outfile.write(sub_array[0]+"\n")

		if number_of_algorithms == 9:
			for element in sub_array[1:]:
				if algo1[int(sub_array[0])] != algo1[int(element)]:
					algo1_count = algo1_count + 1
				if algo2[int(sub_array[0])] != algo2[int(element)]:
					algo2_count = algo2_count + 1
				if algo3[int(sub_array[0])] != algo3[int(element)]:
					algo3_count = algo3_count + 1
				if algo4[int(sub_array[0])] != algo4[int(element)]:
					algo4_count = algo4_count + 1
				if algo5[int(sub_array[0])] != algo5[int(element)]:
					algo5_count = algo5_count + 1
				if algo6[int(sub_array[0])] != algo6[int(element)]:
					algo6_count = algo6_count + 1
				if algo7[int(sub_array[0])] != algo7[int(element)]:
					algo7_count = algo7_count + 1
				if algo8[int(sub_array[0])] != algo8[int(element)]:
					algo8_count = algo8_count + 1
				if algo9[int(sub_array[0])] != algo9[int(element)]:
					algo9_count = algo9_count + 1
			if algo1_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo2_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo3_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo4_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo5_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo6_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo7_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo8_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if algo9_count >= temp_degree/2:
				consensus_count = consensus_count + 1
			if consensus_count >= 5:
				overlapping_outfile.write(sub_array[0]+"\n")
print "\nsee ",overlapping_output_file_name," for overlapping nodes\n"
overlapping_outfile.close()
