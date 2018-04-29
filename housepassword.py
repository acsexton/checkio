def checkio(data):
    """
    The password will be considered strong enough if its length is greater
    than or equal to 10 symbols, it has at least one digit, as well as
    containing one uppercase letter and one lowercase letter in it. The
    password contains only ASCII latin letters or digits.

    :param data:
    :return:
    """

    import string

    number = False
    lowercase = False
    uppercase = False
    if len(data) >= 10:
        for x in data:
            if x.isdigit():
                number = True
            elif x in string.ascii_lowercase:
                lowercase = True
            elif x in string.ascii_uppercase:
                uppercase = True
    if number and lowercase and uppercase:
        goodpass = True
    else:
        goodpass = False

    return goodpass


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio('A1213pokl') == False, "1st example"
    assert checkio('3bAse730onE4') == True, "2nd example"
    assert checkio('asasasasasasasaas') == False, "3rd example"
    assert checkio('QWERTYqwerty') == False, "4th example"
    assert checkio('123456123456') == False, "5th example"
    assert checkio('QwErTy911poqqqq') == True, "6th example"
    print("Coding complete? Click 'Check' to review your tests and earn cool rewards!")
