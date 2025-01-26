#!/usr/bin/python3

def old_dico():
    word_list = []

    isf = 0

    with open("mots_6_lettres.txt", "r") as file:
        
        
        for row in file:
            isf = 0
            for i in range(len(row)-1):
                if row[i] < 'a' or row[i] > 'z':
                    isf = 1

            if isf == 0:
                word_list.append(row[:-1])
                print(row)


    with open("result", "w") as result:
        
        for word in word_list:
            result.write(word)
            result.write("\n")


def is_matching_first():
    
    with open("mots_6_lettres.txt", "r") as file:

        for row in file:
            if row[0] == row[1]:
                print("oui ;(");

is_matching_first()