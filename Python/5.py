#This code prompts the user for two integer values "n" and "m",
#and then creates an "n x m" matrix filled with random integer values between 1 and 100.
#It then finds the maximum value in the matrix and prints out the value and the indices of the cell(s) containing the maximum value.
import random
while True:
    try:
        a=[]
        n=int(input("Dose n:"))
        m=int(input("Dose m:"))

        for i in range(n):
            b=[]
            for j in range(m):
                b.append(random.randint(1,100))
            a.append(b)
        for z in a:
            print(z)

        maxV=a[0][0]
        maxi=[0]
        maxj=[0]
        for i in range(n):
            for j in range(m):
                if maxV==a[i][j]:
                    maxi.append(i)
                    maxj.append(j)
                elif maxV<a[i][j]:
                    maxV=a[i][j]
                    maxi.clear()
                    maxj.clear()
                    maxi.append(i)
                    maxj.append(j)
        print ("To megisto einai: {}".format(maxV))
        print("Oi theseis megistou einai:")
        for i in range(len(maxi)):
            print ("({0},{1})".format(maxi[i], maxj[i]))
    except:
        print("Lathos")
        pass
