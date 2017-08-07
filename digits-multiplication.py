def checkio(number):
    '''
    Multiply all the digits, in sequence, excluding 0s
    '''
    number = str(number)
    number = list(number)
    x = 1
    for i in number:
        i = int(i)
        if i == 0:
            pass
        else:
            x *= i
    return x

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(123405) == 120
    assert checkio(999) == 729
    assert checkio(1000) == 1
    assert checkio(1111) == 1
