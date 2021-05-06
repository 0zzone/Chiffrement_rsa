# Import
from time import *

# Formules mathématiques
def reste(a,b):
    """ Cette fonction permet de calculer le reste de a par b. """
    return a % b

def pgcd(a,b):
    """ Cette fonction permet de calculer PGCD(a,b). """
    a_arr = []
    b_arr = []
    fin = []
    for i in range(1,a):
        if a%i ==0:
            a_arr.append(i)
    for k in range(1,b):
        if b%k ==0:
            b_arr.append(k)
    for c in a_arr:
        for l in b_arr:
            if c == l:
                fin.append(c)
    if fin == []:
        return 1
    else:
        return max(fin)

def inverse(e,fi):
    """ Cette fonction permet de calculer un inverse de e modulo fi. """
    d = 1
    while reste(d*e,fi) != 1:
        d+=1
    return d

def det_e(fi):
    """ Cette fonction permet de calculer un entier e tel que PGCD(e,fi) = 1. """
    e = 5
    while pgcd(e,fi) != 1:
        e += 1
    return e

def cle():
    """ Cette fonction permet de créer les éléments d'une clé publique et une clé privée. """
    p = int(input('Entrez un nombre premier: '))
    q = int(input('Entrez un autre nombre premier: '))
    n = p*q
    fi = (p-1)*(q-1)
    e = det_e(fi)
    d = inverse(e,fi)
    dic = {
        'public': {
            'n': n,
            'e': e
        },
        'private':{
            'd': d
        }
    }
    return dic

def crypter():
    """ Cette fonction permet de crypter un message. """
    m = int(input('Entrez l\'entier que vous souhaitez crypter: '))
    n = int(input('Entrez la variable n de la clé publique: '))
    e = int(input('Entrez la variable e de la clé publique: '))
    c = reste(m**e,n)
    return 'Votre message crypté est le chiffre ' + str(c)

def decrypter():
    """ Cette fonction permet de décrypter un message. """
    x = int(input('Entrez l\'entier que vous voulez décrypter: '))
    d = int(input('Entrez la valeur d de votre clé privée: '))
    n = int(input('Entrez la valeur n de votre clé publique: '))
    final = reste(x**d,n)
    return 'Le message est: ' + str(final)

# Menu
def menu():
    """ Cette fonction permet de rendre le code facile d\'execution. """
    print('Veuillez choisir le numéro correspondant parmi les propositions:')
    sleep(1)
    print('1/ Je souhaite créer ma clé privée et publique\n')
    sleep(1)
    print('2/ Je souhaite crypter un message à l\'aide d\'une clé publique\n')
    sleep(1)
    print('3/ Je souhaite décrypter mon message grâce à ma clé privée\n\n')
    sleep(1)
    a = int(input('Votre choix: '))
    if a == 1:
        print(cle())
    elif a == 2:
        print(crypter())
    elif a == 3:
        print(decrypter())
    else:
        print('Erreur. Réessayez.')
        return menu()

menu()
    
