def intersection(l1,l2):
    res=[]
    for student in l1:
        if student in l2:
            res.append(student)
    return res

def union(l1,l2):
    res=l2.copy()
    for student in l1:
        if not student in l2:
            res.append(student)
    return res

def diff(l1,l2):
    res=[]
    for student in l1:
        if not student in l2:
            res.append(student)
    return res

a=[1,2,3,4,5,6,7] #cricket
b=[2,3,6,7,9,10] #Badminton
c=[2,4,6,8,10,12] #football

print(f"A ={a} \nB ={b} \nC ={c}\n")
print(f"Student Who Play both Cricket And Badminton = {intersection(a,b)}")
print(f"Student Who Play Cricket or Badminton but Not Both = {diff(union(a,b),intersection(a,b))}")
print(f"Number of Student who Play Neither Cricket Nor Badminton = {diff(diff(c,b),a)}")
print(f"Number of Student who play Cricket and Football but not Badminton = {diff(union(a,c),b)}")