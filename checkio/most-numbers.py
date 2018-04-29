def checkio(*args):
    maxArg = 0
    minArg = 0
    for x in args:
        if x == type(str):
            return "Empty"
        else:
            # Get args
            maxArg = max(args)
            minArg = min(args)
    diff = maxArg - minArg
    return diff
    # Return difference max - minimum arg

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    def almost_equal(checked, correct, significant_digits):
        precision = 0.1 ** significant_digits
        return correct - precision < checked < correct + precision

    assert almost_equal(checkio(1, 2, 3), 2, 3), "3-1=2"
    assert almost_equal(checkio(5, -5), 10, 3), "5-(-5)=10"
    assert almost_equal(checkio(10.2, -2.2, 0, 1.1, 0.5), 12.4, 3), "10.2-(-2.2)=12.4"
    assert almost_equal(checkio(), 0, 3), "Empty"

