def checkio(text):

    # Initialize dictionary to store letter and count
    count = 0
    lowered = text.lower()
    most = lowered[0]
    for i in lowered:
        if i.isalpha():
            if lowered.count(i) > count:
                most = i
                count = lowered.count(i)
            elif lowered.count(i) == count:
                if i < most:
                    most = i
                    count = lowered.count(i)

    return most


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio("Hello World!") == "l", "Hello test"
    assert checkio("How do you do?") == "o", "O is most wanted"
    assert checkio("One") == "e", "All letter only once."
    assert checkio("Oops!") == "o", "Don't forget about lower case."
    assert checkio("AAaooo!!!!") == "a", "Only letters."
    assert checkio("abe") == "a", "The First."
    print("Start the long test")
    assert checkio("a" * 9000 + "b" * 1000) == "a", "Long."
    print("The local tests are done.")
