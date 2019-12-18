def longest(s: str):
    # length = len(s)
    # cursor = 0
    current_longest = 0

    string = str()
    cp_s = list(s)
    for i in cp_s:
        if i in string:
            current_length = len(string)
            if current_length > current_longest:
                current_longest = current_length
                string = str()
            continue
        temp_char = cp_s.pop()
        string += temp_char
        # TODO: not finished

    return current_longest


if __name__ == '__main__':
    ss = 'jdijafofdjaoghdiosagha'
    print(longest(ss))
