def bestFit(blockSize, m, processSize, n):
      
    # Stores block id of the block allocated to a process 
    allocation = [-1] * n 
    for i in range(n):
          
        # Find the best fit block for current process 
        bestIdx = -1
        for j in range(m):
            if blockSize[j] >= processSize[i]:
                if bestIdx == -1: 
                    bestIdx = j 
                elif blockSize[bestIdx] > blockSize[j]: 
                    bestIdx = j
  
        # If we could find a block for 
        # current process 
        if bestIdx != -1:
              
            # allocate block j to p[i] process 
            allocation[i] = bestIdx 
  
            # Reduce available memory in this block. 
            blockSize[bestIdx] -= processSize[i]
  
    print("Process No. Process Size     Block no.")
    for i in range(n):
        print(i + 1, "               ", processSize[i],end = "               ") 
        if allocation[i] != -1: 
            print(allocation[i] + 1) 
        else:
            print("Not Allocated")
  
# Driver code 
if __name__ == '__main__': 
    blockSize = [] 
    processSize = [] 
    m = int(input("Enter Number of memory holes:--"))
    n = int(input("Enter Number of Processess:--"))
    for i in range(m):
    	x=int(input("Enter memory hole size:--- "))
    	blockSize.append(x)
    	
    for i in range(n):
    	x=int(input("Enter Process size:--- "))
    	processSize.append(x)
    	  
    bestFit(blockSize, m, processSize, n)
