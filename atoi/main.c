int myAtoi(char* s) {
    if (s == NULL || *s == '\0') {
        return 0;
    }
    int i = 0;
    while (s[i] == ' ') {
        i++;
    }
    int sign = 1;
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    long long result = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        result = result * 10 + (s[i] - '0');
        if (sign == 1 && result > INT_MAX) {
            return INT_MAX;
        } else if (sign == -1 && -1 * result < INT_MIN) {
            return INT_MIN;
        }
        i++;
    }
    return sign * result;
}
