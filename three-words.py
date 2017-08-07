def checkio(words):
    # True = Found three words in succession
    x = words.split()
    test = 0
    for i in x:
        if i.isalpha():
            test += 1
        else:
            if test >= 3:
                break
            else:
                test = 0
    return test >= 3

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("Hello World hello") == True, "Hello"
    assert checkio("He is 123 man") == False, "123 man"
    assert checkio("1 2 3 4") == False, "Digits"
    assert checkio("bla bla bla bla") == True, "Bla Bla"
    assert checkio("Hi") == False, "Hi"
    assert checkio("one two 3 four five six 7 eight 9 ten eleven 12") == True
