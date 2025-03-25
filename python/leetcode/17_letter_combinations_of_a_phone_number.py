def letter_combinations(digits):
    if not digits:
        return []

    digit_to_char = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    combinations = []

    def backtrack(index, path):
        if index == len(digits):
            combinations.append("".join(path))
            return
        current_digit = digits[index]
        for char in digit_to_char[current_digit]:
            path.append(char)
            backtrack(index + 1, path)
            path.pop()

    backtrack(0, [])
    return combinations

# Example usage:
print(letter_combinations("23"))