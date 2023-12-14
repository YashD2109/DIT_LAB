marklist=[20,50,40,50,90,90,None,89,None]
n=int(input("Enter no of students "))
for i in range(n):
    mark=int(input(f"Enter marks {i+1} student : "))
    marklist.append(mark)
print(marklist)
total=0
absent_student=0
freq={}

max_val=marklist[0]
min_val=marklist[0]

for mark in marklist:
    if mark==None:
        absent_student+=1
    else:
        total+=mark
        #calculate Max and Min
        max_val=max(max_val,mark)
        min_val=min(min_val,mark)

        #Frequency of marks
        if freq.get(mark)==None:
            freq[mark]=1
        else:
            freq[mark]+=1

highest_freq=0
highest_freq_mark=0
for mark in freq:
    if freq[mark]>highest_freq:
        highest_freq=freq[mark]
        highest_freq_mark=mark

print(f"Averrage Score of the class = {total/len(marklist)}\n")
print(f"Highest Score={max_val} and lowest score={min_val}\n")
print(f"Number of absent student= {absent_student}\n")
print(f"Mark with highest frequency : {highest_freq_mark}\n")