bool isAnagram(char* s, char* t) {
    size_t sLen = strlen(s);
    size_t tLen = strlen(t);
    int size = 26;
    int arr[26] = {0};

    if(sLen != tLen) {
        return false;
    }

    
    for(int i = 0; s[i] != '\0'; i++) {
        arr['z' - s[i]]++;
        arr['z' - t[i]]--;
    }

    for(int i = 0; i < size; i++) {
        if(arr[i] != 0) {
            return false;
        }
    }

    return true;
}
