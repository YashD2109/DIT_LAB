def insertionSort(arr):
    n=len(arr)
    if n<=1:
        return
    for i in range(1,n):
        key=arr[i]
        j=i-1
        while(j>=0 and key<arr[j]):
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=key
arr=[54,26,93,17,77,31,44,55,20]
insertionSort(arr)
print(arr,"\n\n")

def shellSort(arr):
    n=len(arr)
    gap=n//2
    while gap>0:
        for i in range(0,n,gap):
            temp=arr[i]
            j=i
            while(j>=gap and arr[j-gap]>temp):
                arr[j]=arr[j-gap]
                j-=gap
            arr[j]=temp
        gap//=2
    
arr=[54,26,93,17,77,31,44,55,20]
shellSort(arr)
print(arr)


