#The code you provided is a working implementation of a game similar to the popular board game "SOS".
#It prompts the player to input a coordinate in the form 'S,i,j', where 'S' is the symbol 'S' or 'O',
#and 'i' and 'j' are the row and column coordinates of the player's choice, respectively. The goal is to make word 'SOS'.
import random
def printt():
    print("   0 1 2 3 4 5 6 7 8 9")
    for i in range(10):
        print(str(i)+": ",end="")
        for j in range(10):
            print(table[i][j]+" ",end="")
        print()

def getPlayerInput():
    i=input("Dose Stoixeio kai syntetagmenes sti morfi: 'S,i,j':\n").split(sep=',')
    if len(i)!=3 or (not(i[0].upper()=="S" or i[0].upper()=="O")) or (not i[1].isdigit()) or (not i[2].isdigit()):
        print("Den edwses swsta to input.")
        return getPlayerInput()
    else:
        if int(i[1])<0 or int(i[1])>9 or int(i[2])<0 or int(i[2])>9:
            print("Den edwses swsta to input.")
            return getPlayerInput()
        if table[int(i[1])][int(i[2])]!=" ":
            print("Den einai keni i thesi.")
            return getPlayerInput()
        table[int(i[1])][int(i[2])]=i[0].upper()

def getComputerInput():
    if hasFreeSpace(table):
        if random.randint(0,1)==0:
            l="S"
        else:
            l="O"
        i=[l,random.randint(0,9),random.randint(0,9)]
        if table[int(i[1])][int(i[2])]!=" ":
            return getComputerInput()
        table[int(i[1])][int(i[2])]=i[0].upper()

def evalTable(tab):
    S=0
    for i in range(10):
        for j in range(10):
            if tab[i][j]=="O":
                try:
                    if tab[i-1][j]=="S" and tab[i+1][j]=="S":
                        S+=1
                    if tab[i-1][j-1]=="S" and tab[i+1][j+1]=="S":
                        S+=1
                    if tab[i-1][j+1]=="S" and tab[i+1][j-1]=="S":
                        S+=1
                    if tab[i][j-1]=="S" and tab[i][j+1]=="S":
                        S+=1
                except:
                    pass
    return S

def hasFreeSpace(table):
    f=False
    for i in range(10):
        for j in range(10):
            if table[i][j]==" ":
                f=True
    return f


try:
    table=[]
    for i in range(10):
        b=[]
        for j in range(10):
            b.append(' ')
        table.append(b)
    PScore=0
    CScore=0
    printt()
    print("Player: {}  Computer: {}".format(PScore,CScore))
    while hasFreeSpace(table):
        temps=evalTable(table)
        getPlayerInput()
        PScore += evalTable(table)-temps
        temps=evalTable(table)
        getComputerInput()
        CScore+=(evalTable(table)-temps)
        printt()
        print("Player: {}  Computer: {}".format(PScore,CScore))
    if PScore>CScore:
        print("Congrats, you won!")
    elif PScore==CScore:
        print("Tie!")
    else:
        print("The Computer Won!")
except:
    print("Some Error Occured!")