
marks=[3,46,8,31,2,85,87]

def selectionSort(marks):
    n=len(marks)
    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if marks[min_index]>marks[j]:
                min_index=j
        marks[i],marks[min_index]=marks[min_index],marks[i]
    print("Marks of student afterperforming selection sort on the list : ")
    for i in marks:
        print(i,end=" ")
    print("\n")
selectionSort(marks)

marks=[3,46,8,31,2,85,87]
def bubbleSort(marks):
    n=len(marks)
    for i in range (n):
        for j in range(0,n-i-1):
            if(marks[j]>marks[j+1]):
                marks[j],marks[j+1]=marks[j+1],marks[j]
    print("Marks of students after performing ubble sort on the list : ")
    for i in marks:
        print(i,end=" ")
    print("\n")
bubbleSort(marks)
    