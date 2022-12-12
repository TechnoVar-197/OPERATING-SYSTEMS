def FCFS(arr, head):
 
    seek_count = 0;
    distance, cur_track = 0, 0;
 
    for i in range(size):
        cur_track = arr[i]
 
        # calculate absolute distance
        distance = abs(cur_track - head)
 
        # increase the total count
        seek_count += distance
 
        # accessed track is now new head
        head = cur_track
     
    print("Total number of seek operations = ",seek_count)
 
    # Seek sequence would be the same
    # as request array sequence
    print("Seek Sequence is");
 
    for i in range(size):
        print(arr[i]);
     
# Driver code
if __name__ == '__main__':
 
    # request array
    arr = []
    size = int(input("Enter size of request array:-- "))
    for i in range(size):
    	x = int(input(f'Enter positon {i+1}:--'))
    	arr.append(x)
    head = int(input("Enter Current position of head :-- "))
 
    FCFS(arr, head);
