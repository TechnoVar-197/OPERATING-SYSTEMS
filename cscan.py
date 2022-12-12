disk_size = 200
 
 
def CSCAN(arr, head):
 
    seek_count = 0
    distance = 0
    cur_track = 0
    left = []
    right = []
    seek_sequence = []

    left.append(0)
    right.append(disk_size - 1)
 
    for i in range(size):
        if (arr[i] < head):
            left.append(arr[i])
        if (arr[i] > head):
            right.append(arr[i])
 
    # Sorting left and right vectors
    left.sort()
    right.sort()
 
    # First service the requests
    # on the right side of the
    # head.
    for i in range(len(right)):
        cur_track = right[i]
 
        # Appending current track
        # to seek sequence
        seek_sequence.append(cur_track)
 
        # Calculate absolute distance
        distance = abs(cur_track - head)
 
        # Increase the total count
        seek_count += distance
 
        # Accessed track is now new head
        head = cur_track
 
    # Once reached the right end
    # jump to the beggining.
    head = 0
 
    # adding seek count for head returning from 199 to 0
    seek_count += (disk_size - 1)
 
    # Now service the requests again
    # which are left.
    for i in range(len(left)):
        cur_track = left[i]
 
        # Appending current track
        # to seek sequence
        seek_sequence.append(cur_track)
 
        # Calculate absolute distance
        distance = abs(cur_track - head)
 
        # Increase the total count
        seek_count += distance
 
        # Accessed track is now the new head
        head = cur_track
 
    print("Total number of seek operations =",seek_count)
    print("Seek Sequence is")
    print(*seek_sequence, sep="\n")
 
# Driver code
if __name__ =="__main__":  
    # request array
    arr = []
    size = int(input("Enter size of request array:-- "))
    for i in range(size):
    	x = int(input(f'Enter positon {i+1}:--'))
    	arr.append(x)
    head = int(input("Enter Current position of head :-- "))
    CSCAN(arr,head)
