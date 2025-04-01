def romanToInt(s: str):
    roman_numbers = {
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1
    }

    result = 0
    for i in range(len(s) - 1):
        if roman_numbers[s[i]] < roman_numbers[s[i + 1]]:
            result -= roman_numbers[s[i]]
        else:
            result += roman_numbers[s[i]]
    
    return result + roman_numbers[s[-1]]

# print(romanToInt("III"))
# print(romanToInt("LVIII"))
print(romanToInt("MCMXCIV"))
