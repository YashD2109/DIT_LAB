#Program to display word with longest length

sentence=input("Enter sentence : \n")
longest=max(sentence.split(),key=len)
print("Longest Word is : ",longest)
print(" and its Length is : ",len(longest))

#Program to determine the frequency of occurance of perticular character in string

freq={}
for char in sentence:
    if char!=' ':    
        if freq.get(char)==None:
            freq[char]=1
        else:
            freq[char]+=1
print("Count of all character in Geeks for Geeks is : \n" ,freq)

#Program to check whether give string is palindrome or not

def is_Palindrome(s):
    return s==s[::-1]

ans=is_Palindrome(sentence)
if ans:
    print("Yes")
else:
    print("No")

#Program to display index of first appearance of the substring

substring=input("Enter the substring to check appearance of : ")
index=sentence.find(substring)
print(index)

#Program to count the occurances of each word in string

freq={}
words=sentence.split()

for word in words:
    if freq.get(word)==None:
        freq[word]=1
    else:
        freq[word]+=1
print(freq)