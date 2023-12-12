import numpy as np
from scipy.sparse import csr_matrix

x=np.array([[1,2],[4,5]])
y=np.array([[7,8],[9,10]])

print("The element wise addition of matrix is : ")
print(np.add(x,y))

print("The element wise substaction of matrix is : ")
print(np.subtract(x,y))

print("The element wise multiply of matrix is : ")
print(np.dot(x,y))

print("Transpose of given matrix is : ")
print(x.T)
print("\n\n")

a=np.array([[2,0,0],[0,0,2],[0,0,2]])
b=np.array([[1,0,0],[0,0,1],[0,0,2]])

print("matrix representation of A : \n",a)
print("matrix representation of B : \n",b)

sa=csr_matrix(a)
sb=csr_matrix(b)
print("Sparse matrix of A is : \n",sa)
print("Sparse matrix of B is : \n",sb)

c=np.add(a,b)
sc=csr_matrix(c)
print("Addition of sparse matric of A & B is : \n",sc)

d=np.subtract(a,b)
sd=csr_matrix(d)
print("Substaction of sparse matric of A & B is : \n",sd)

e=np.dot(a,b)
se=csr_matrix(e)
print("Multiplication of sparse matric of A & B is : \n",se)

f=a.T
sf=csr_matrix(f)
print("Transpose of sparse matric of A is : \n",sf)