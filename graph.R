data <- read.table("/home/shiva/Fortunato-Package2Experimentation/experiment1-100_overlaps/edgelist_with_repeats.txt")
mat <- as.matrix(data,ncol=2,byrow=TRUE)
graph <- graph.edgelist(mat,directed = FALSE)
new_graph <- simplify(graph)