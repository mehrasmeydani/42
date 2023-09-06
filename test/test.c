int main() {
    char* result;
    char* input[] = {
        // Valid Inputs
        "1010", "01", "0123456789",       // Binary to Decimal
        "FF", "0123456789ABCDEF", "01",  // Hexadecimal to Binary
        "321", "01234567", "0123456789",  // Decimal to Octal
        "101010", "01", "0123456789ABCDEF",  // Binary to Hexadecimal
        "1A4", "0123456789ABCDEF", "01234567",  // Hexadecimal to Octal
        "1001", "0123456789", "01",  // Decimal to Binary
        "321", "0123456789", "0123456789ABCDEF",  // Decimal to Hexadecimal
        "A7", "0123456789ABCDEF", "0123456789",  // Hexadecimal to Decimal
        "77", "01234567", "0123456789ABCDEF",  // Octal to Hexadecimal
        "15", "0123456789ABCDEF", "01234567",  // Decimal to Octal

        // Invalid Inputs
        "1010", "01+", "0123456789",      // Invalid Base (contains '+')
        "FF", "\tABC", "01",             // Invalid Base (contains non-printable characters)
        "1A4", "0123456789", "",         // Invalid Base (empty base_to)
        "1101", "01", "012+3456789",     // Invalid Base (contains '+')
        "1101", "01", "",                // Invalid Base (empty base_to)
        "1010", "01", "01234567",        // Invalid Input (base_from too small for binary)
        "12345", "0123456789", "01",     // Invalid Input (base_from too large for binary)
        "1010", "01234567", "01",        // Invalid Input (base_from too large for binary)
        "FF", "01", "0123456789ABCDEF",  // Invalid Input (base_from too small for hexadecimal)
        "ABC123", "0123456789ABCDEF", "01234567",  // Invalid Input (base_from too large for hexadecimal)
        "1A4", "0123456789", "01",      // Invalid Input (base_from too large for octal)
        "12", "01", "0123456789ABCDEF",  // Invalid Input (base_to too small for binary)
        "1010", "01", "0123456789ABCDEF", // Invalid Input (base_to too small for hexadecimal)
        "15", "0123456789", "01"        // Invalid Input (base_to too small for octal)
    };

    int num_tests = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < num_tests; i += 3) {
        result = ft_convert_base(input[i], input[i + 1], input[i + 2]);
        if (result != NULL) {
            printf("Test %d: Passed - Input: (%s) Base From: (%s) Base To: (%s) Result: (%s)\n",
                   (i / 3) + 1, input[i], input[i + 1], input[i + 2], result);
            free(result);
        } else {
            printf("Test %d: Failed - Input: (%s) Base From: (%s) Base To: (%s)\n",
                   (i / 3) + 1, input[i], input[i + 1], input[i + 2]);
        }
    }

    return 0;
}
