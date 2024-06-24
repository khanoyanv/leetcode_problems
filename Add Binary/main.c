char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    char* res = (char*)malloc(maxLen + 2);
    if(res == NULL) {
        return NULL;
    }
    int i = lenA-1;
    int j = lenB-1;
    int carry = 0;
    int sum = 0;
    int index = 0;
    while(i >= 0 || j >= 0 || carry) {
        sum += carry;
        if(i >= 0) { sum += a[i] - 48; }
        if(j >= 0) { sum += b[j] - '0'; }
        res[index++] = sum % 2 + '0';
        carry = sum / 2;
        --i;
        --j;
        sum = 0;
    }
    for(int i = 0; i < index/2; ++i) {
        int tmp = res[i];
        res[i] = res[index -1 -i];
        res[index -1 -i] = tmp;
    }
    res[index] = '\0';
    return res;
}
